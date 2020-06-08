#pragma once

// Shared library interface
#if !defined(SYMBOL_IMPORT)
#   if defined(_MSC_VER)
#       define SYMBOL_EXPORT __declspec(dllexport)
#       define SYMBOL_IMPORT __declspec(dllimport)
#   else
#       define SYMBOL_EXPORT __attribute__((__visibility__("default")))
#       define SYMBOL_IMPORT
#   endif
#endif
