// 编写一个调用 fork() 的程序。在调用 fork() 之前，让主进程访问一个变量（例如x），并将其值设置为某个值（例如100）。
// 子进程中的变量有什么值？当子进程和父进程都改变了x的值，变量会发生什么？

/*
    x的值都是100，是相同的，因为子进程复制了父进程的内存空间
    之后再修改x的值，两个进程就互不影响了
*/

#include <stdio.h>    // C library to perform Input/Output operations (header)
#include <stdlib.h>   // C Standard General Utilities Library (header)
#include <unistd.h>   // standard symbolic constants and types; https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html
#include <string.h>   // C Strings (header)
#include <fcntl.h>    // file control options; https://pubs.opengroup.org/onlinepubs/007904875/basedefs/fcntl.h.html
#include <sys/wait.h> // The <sys/wait.h> header shall define the following symbolic constants for use with waitpid(): https://pubs.opengroup.org/onlinepubs/009696699/basedefs/sys/wait.h.html

int main()
{
    printf("begin\n");
    int x = 100;
    int pid = fork();
    if (pid > 0) { // parent
        printf("parent id: %d, child pid: %d \n", (int)getpid(), pid);
        printf("parent x %d\n", x);
        x = 300;
        printf("parent x %d\n", x);
    } else if (pid == 0) { // child
        printf("child pid: %d\n", (int)getpid());
        printf("child x %d\n", x);
        x = 200;
        printf("child x %d\n", x);
    } else {
        printf("fork() error");
    }

    return 0;
}
