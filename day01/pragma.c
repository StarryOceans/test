#include <stdio.h>
#pragma GCC dependency "dep.c"
#pragma GCC poison goto float
int main(void) {
    //float f;
    double f;
    printf("1\n");
    //goto label;
    printf("2\n");
label:
    printf("3\n");
    struct A {
        double d; // 8
        char   c; // 1
        int    i; // 4
        short  h; // 2
    }; // ddddddddcxxxiiiihhxx
    printf("%u\n", sizeof(struct A)); // 20
#pragma pack(1)
    struct B {
        double d; // 8
        char   c; // 1
        int    i; // 4
        short  h; // 2
    }; // ddddddddciiiihh
    printf("%u\n", sizeof(struct B)); // 15
#pragma pack(2)
    struct C {
        double d; // 8
        char   c; // 1
        int    i; // 4
        short  h; // 2
    }; // ddddddddcxiiiihh
    printf("%u\n", sizeof(struct C)); // 16
#pragma pack()
    struct D {
        double d; // 8
        char   c; // 1
        int    i; // 4
        short  h; // 2
    }; // ddddddddcxxxiiiihhxx
    printf("%u\n", sizeof(struct D)); // 20
    return 0;
}

