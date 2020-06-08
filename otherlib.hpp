#pragma once

#include "export.h"

#if BUILDING_OTHER
#   define OTHER_API SYMBOL_EXPORT
#else
#   define OTHER_API SYMBOL_IMPORT
#endif

struct argument;

using fptr = void (*)(argument*);

OTHER_API fptr get_fptr();
