#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * 线程池中需要对任务进行缓存;每个任务包括的主要内容是回调函数和相应的参数
 * 任务是采用一种队列来实现的。
 */
typedef struct runner
{
    void* (*callback)(void*arg);
    void* arg;
    struct runner* next;
}thread_runner;

/*
 * 这是一个线程池的结构，包括互斥量和条件变量（条件变量在线程池结构中可以唤醒被阻塞的空闲线程，很关键）
 * 在线程池中需要排队的是任务。
 */
typedef struct pool
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    thread_runner * front;//任务队列的队头
    thread_runner * rear;//任务队列的队尾
    int shutdown;//用来标识线程池是否关闭
    pthread_t*pthread;//其实是用一个线程数组来实现的
    int max_thread_size;
}thread_pool;

//定义线程的执行函数...在run中应该是while(1)的循环，在没有任务可执行时等待cond条件
void* run(void * arg);

//线程池的初始化工作
void thread_pool_init(thread_pool* pool,int max_thread_size);

//往线程池中添加新的任务...没收到一个任务，我们都需要将相应的任务放置到线程池中的任务队列中去
void add_runner(thread_pool* pool,void*(*callback)(void* arg),void* arg);

//我们需要在退出时能够销毁线程池，否则会造成内存泄露
void thread_pool_destroy(thread_pool** lpool);
#endif

