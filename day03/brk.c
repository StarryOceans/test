#include <stdio.h>
#include <unistd.h>
/*
 * xxxIIIIDDDDDDDDCC...C
 *    ^   ^       ^     ^
 *    p1  p2      p3
 */
int main(void) {
    setbuf(stdout, NULL);
    int* p1 = (int*)sbrk(0);
	printf("p1=%x\n",p1);
    if (p1 == (int*)-1) {
        perror("sbrk");
        return -1;
    }
    double* p2 = (double*)(p1 + 1);
	printf("p2=%x\n",p2);
    if (brk(p2) == -1) {
        perror("brk");
        return -1;
    }
    *p1 = 0;
    printf("%d\n", *p1);
    char* p3 = (char*)(p2 + 1);
	printf("p3=%x\n",p3);
    if (brk(p3) == -1) {
        perror("brk");
        return -1;
    }
    *p2 = 1.2;
    printf("%g\n", *p2);
    void* p4 = p3 + 256;
    if (brk(p4) == -1) {
        perror("brk");
        return -1;
    }
    sprintf(p3, "Hello, World!");
    printf("%s\n", p3);
    if (brk(p1) == -1) {
        perror("brk");
        return -1;
    }
    return 0;
}

