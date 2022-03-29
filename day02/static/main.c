#include "math.h"
int main(void) {
    int a = 30, b = 20;
    show(a, '+', b, add(a, b));
    show(a, '-', b, sub(a, b));
    return 0;
}

