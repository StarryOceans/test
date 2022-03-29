#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
void redir(void) {
    close(STDIN_FILENO);
    open("i.txt", O_RDONLY);
    close(STDOUT_FILENO);
    creat("o.txt", 0644);
    close(STDERR_FILENO);
    creat("e.txt", 0644);
}
void resume(void) {
    close(STDIN_FILENO);
    stdin = fopen("/dev/tty", "r");
    close(STDOUT_FILENO);
    stdout = fopen("/dev/tty", "w");
    close(STDERR_FILENO);
    stderr = fopen("/dev/tty", "w");
    setbuf(stderr, NULL);
}
void doio(void) {
    int x, y;
    // 读标准输入
    scanf("%d%d", &x, &y);
    // 写标准输出
    printf("%d+%d=%d\n", x, y, x + y);
    fflush(stdout);
    malloc(0xFFFFFFFF);
    // 写标准错误
    perror("malloc");
}
int main(void) {
    redir();
    doio();
    resume();
    doio();
    return 0;
}

