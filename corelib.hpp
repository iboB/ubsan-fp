#pragma once

#include "export.h"

#if BUILDING_CORE
#   define CORE_API SYMBOL_EXPORT
#else
#   define CORE_API SYMBOL_IMPORT
#endif

struct CORE_API argument {
    virtual ~argument();
};
