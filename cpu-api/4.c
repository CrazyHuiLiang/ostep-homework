/*
    4 编写一个调用 fork() 的程序，然后调用某种形式的 exec() 来运行程序 /bin/ls
    尝试 exec() 的所有变体，包括：
    execl()
    execle()
    execlp()
    execv()
    execvp()
    execvpe()
    为什么同样的基本调用会有这么多变种？
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
        printf("parent id: %d, child pid: %d \n", (int)getpid(), pid);
    } else if (pid == 0) { // child
        printf("child pid: %d\n", (int)getpid());
        exec("ls");
    } else {
        printf("fork() error");
    }

    return 0;
}
