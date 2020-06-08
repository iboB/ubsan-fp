#include "otherlib.hpp"

int main() {
    auto ptr = get_fptr();
    ptr(nullptr);
}