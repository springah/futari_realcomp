#pragma once
#ifndef PPC_CONFIG_H_INCLUDED
#define PPC_CONFIG_H_INCLUDED


#define PPC_IMAGE_BASE 0x88000000ull
#define PPC_IMAGE_SIZE 0x7D0000ull
#define PPC_CODE_BASE 0x88080000ull
#define PPC_CODE_SIZE 0x1E88A0ull

#ifdef PPC_INCLUDE_DETAIL
#include "ppc_detail.h"
#endif

#endif
