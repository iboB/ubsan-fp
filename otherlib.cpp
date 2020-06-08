#define BUILDING_OTHER 1
#include "otherlib.hpp"
#include "corelib.hpp"

#include <cstdio>

static void func(argument* a) { 
    printf("Do not optimize %p away\n", a); 
}

fptr get_fptr() {
    return func;
}
