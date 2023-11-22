// 2．编写一个打开文件的程序（使用 open()系统调用），然后调用 fork()创建一个新进程。
// 子进程和父进程都可以访问 open()返回的文件描述符吗？当它我并发（即同时）写入文件时，
// 会发生什么？

/*
    子进程父进程可以同时访问一个文件描述符，并发写入文件时，两个进程的写入内容都会写入
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
    int fid = open("./test.txt", O_CREAT|O_WRONLY|O_TRUNC);

    int pid = fork();
    if (pid > 0) { // parent
        printf("parent id: %d, child pid: %d, fid: %d \n", (int)getpid(), pid, fid);
        const void *buf = "parent\n";
        for (int i=0; i< 100000; i++) {
            write(fid, buf, 7);
        }
    } else if (pid == 0) { // child
        printf("child pid: %d, fid: %d\n", (int)getpid(), fid);
        const void *buf = "child\n";
        for (int i=0; i< 100000; i++) {
            write(fid, buf, 6);
        }
    } else {
        printf("fork() error");
    }

    return 0;
}
