#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int done = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

void thr_exit() {
    printf("thr signal: 子线程开始退出\n");
    pthread_mutex_lock(&m);
    printf("thr signal: 子线程获得锁\n");
    done = 1;
    printf("thr signal: 子线程设置 done = %d\n", done);
    pthread_cond_signal(&c);
    printf("thr signal: 已发送条件变量信号\n");
    pthread_mutex_unlock(&m);
    printf("thr signal: 子线程释放锁\n");
}

void *child(void *arg) {
    printf("child: 子线程开始\n");
    sleep(1);  // 模拟工作负载
    printf("child: 子线程工作完成\n");
    thr_exit();
    printf("child: 子线程退出\n");
    return NULL;
}

void thr_join() {
    printf("thr join: 等待子线程完成...\n");
    pthread_mutex_lock(&m);
    printf("thr join: 获得锁\n");
    while (done == 0) {
        printf("thr join: 进入条件变量等待\n");
        pthread_cond_wait(&c, &m);
    }
    printf("thr join: 条件变量被唤醒，done = %d\n", done);
    pthread_mutex_unlock(&m);
    printf("thr join: 释放锁\n");
}

int main(int argc, char *argv[]) {
    printf("parent: 主线程开始\n");
    pthread_t p;
    
    // 创建子线程
    int ret = pthread_create(&p, NULL, child, NULL);
    if (ret != 0) {
        fprintf(stderr, "错误: 无法创建线程，错误码: %d\n", ret);
        return 1;
    }
    
    // 等待子线程完成
    thr_join();
    
    // 等待子线程完全结束
    pthread_join(p, NULL);
    
    printf("parent: 主线程结束\n");
    
    // 清理资源
    pthread_mutex_destroy(&m);
    pthread_cond_destroy(&c);
    
    return 0;
}
