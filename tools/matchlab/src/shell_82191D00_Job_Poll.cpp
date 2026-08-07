// 0x82191D00 (shell) — JOB POLL: run the job's current step, and when the job has reached one of
// its two terminal steps, publish the result and mark this waiter finished.
//
// FOUR BYTE-IDENTICAL COPIES, contiguous and exactly 0x98 apart:
//     0x82191D00  0x82191D98  0x82191E30  0x82191EC8
// All four compare against the SAME two terminal step functions, so they are four instantiations
// of one body rather than four per-object variants.  Found by matchlab/clones.py, which ranks it
// the largest unstarted clone family in either image (38 insn x 4 = 152 instructions).
//
// The step pointer is called with the job as its only argument (`lwz r3,0x10(r3)` feeds the
// `bctrl` directly), and the job is RE-READ from the task after the call — the call may retire
// the step, so the terminal-state test must see the new value, not the pre-call one.
//
// The two terminal steps live 8 bytes apart at 0x82191B10 / 0x82191B18.  Ghidra renders them as
// DAT_ symbols because nothing calls them directly; they are only ever compared against, which is
// what a "finished" sentinel step looks like.

typedef unsigned int u32;

struct Job;

// The job's step function: takes the job, advances it, and re-seats job->step.
typedef void (*JobStep)(Job* job);

struct Job
{
    u32     pad000[0x194 / 4];
    u32     result;                 // 0x194  what the job produced, copied out on completion
    u32     pad198[(0x1A8 - 0x198) / 4];
    JobStep step;                   // 0x1A8  current step; one of the terminals below when done
};

struct JobWaiter
{
    u32   pad00[0x08 / 4];
    u32   state;                    // 0x08  2 == finished
    u32   pad0C;                    // 0x0C
    Job*  job;                      // 0x10
    u32*  out;                      // 0x14  where to publish job->result (may be null)
};

// 0x82191B18 and 0x82191B10 — the two steps a job parks in once it can make no more progress.
// Never called through this path, only compared against.
extern "C" void Job_StepSucceeded(Job* job);    // 0x82191B18
extern "C" void Job_StepFailed(Job* job);       // 0x82191B10

extern "C" void Job_Poll(JobWaiter* w)
{
    Job* job = w->job;
    if (job->step != 0)
        job->step(job);

    job = w->job;

    bool done = (job->step == &Job_StepSucceeded) || (job->step == &Job_StepFailed);
    if (done)
    {
        if (w->out != 0)
            *w->out = job->result;
        w->state = 2;
    }
}
