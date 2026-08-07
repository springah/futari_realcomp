// Match-side compilation of the SHARED body in decomp/shell/task_kill.inl.
// The same .inl is compiled into the port by decomp/shell/task_kill.cpp, so proving this
// byte-exact proves the code that actually runs.
#include "../../decomp/shell/task_kill.inl"

// ppcmatch needs a non-inline definition to find in the COFF symbol table.
void Task_Kill_match(Task* t) { Task_Kill(t); }
