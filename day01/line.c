#include <stdio.h>
int main(void) {
    int x = 1000;
    printf("%d\n", __LINE__);
#line 100
    printf("%d\n", __LINE__);
    return 0;
}


