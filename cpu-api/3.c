/*
    3 使用 fork() 编写另一个程序。子进程应打印 “hello”， 父进程应打印 "goodbye"
    你应该尝试确保子进程先打印。你能否不在父进程调用 wait() 而做到这一点呢

    可以在父进程中使用 sleep(1) 使的父进程让渡出cpu的执行
*/

#include <stdio.h>    // C library to perform Input/Output operations (header)
#include <stdlib.h>   // C Standard General Utilities Library (header)
#include <unistd.h>   // standard symbolic constants and types; https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html
#include <string.h>   // C Strings (header)
#include <fcntl.h>    // file control options; https://pubs.opengroup.org/onlinepubs/007904875/basedefs/fcntl.h.html
#include <sys/wait.h> // The <sys/wait.h> header shall define the following symbolic constants for use with waitpid(): https://pubs.opengroup.org/onlinepubs/009696699/basedefs/sys/wait.h.html

int main()
{

    int pid = fork();
    if (pid > 0) { // parent
        // wait(NULL);
        sleep(1);
        printf("parent id: %d, child pid: %d \n", (int)getpid(), pid);

    } else if (pid == 0) { // child
        printf("child pid: %d\n", (int)getpid());
    } else {
        printf("fork() error");
    }

    return 0;
}
