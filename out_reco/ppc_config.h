#pragma once
#ifndef PPC_CONFIG_H_INCLUDED
#define PPC_CONFIG_H_INCLUDED


#define PPC_IMAGE_BASE 0x88000000ull
#define PPC_IMAGE_SIZE 0x7B0000ull
#define PPC_CODE_BASE 0x88070000ull
#define PPC_CODE_SIZE 0x1DEEB0ull

#ifdef PPC_INCLUDE_DETAIL
#include "ppc_detail.h"
#endif

#endif
