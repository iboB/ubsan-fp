#define BUILDING_OTHER 1
#include "otherlib.hpp"
#include "corelib.hpp"

#include <cstdio>

fptr get_fptr() {
    return [](argument* a) {
        printf("Do not optimize %p away\n", a);
    };
}