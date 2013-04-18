#include "thread_pool.h"

void* run(void * arg)
{
    thread_pool* pool=(thread_pool*)arg;
    while(1)
    {
        pthread_mutex_lock(&(pool->mutex));
        printf("run locked!\n");
        while(pool->front==NULL && pool->shutdown!=1)
            pthread_cond_wait(&(pool->cond),&(pool->mutex));
        if(pool->shutdown==1)
        {
            pthread_mutex_unlock(&(pool->mutex));
            printf("run unlock and thread exit\n");
            pthread_exit(NULL);
        }
        thread_runner* runner=pool->front;
        pool->front=pool->front->next;
        pthread_mutex_unlock(&(pool->mutex));
        printf("run unlocked!\n");
        runner->callback(runner->arg);
        free(runner);
        runner=NULL;
        printf("run-> runned and free runner!\n");
    }
    pthread_exit(NULL);
}


void thread_pool_init(thread_pool* pool,int max_thread_size)
{
    pthread_mutex_init(&(pool->mutex),NULL);
    pthread_cond_init(&(pool->cond),NULL);
    pool->front=NULL;
    pool->rear=NULL;
    pool->shutdown=0;
    
    int i,temp;
    pool->pthread=(pthread_t*)malloc(max_thread_size*sizeof(pthread_t));
    for(i=0;i<max_thread_size;i++)
    {
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
        if((temp=pthread_create(&(pool->pthread[i]),&attr,run,(void*)pool))!=0)
            printf("create thread error!\n");
    }
    printf("Create %d detached threads!\n",max_thread_size);

}


void add_runner(thread_pool* pool,void*(*callback)(void* arg),void* arg)
{
    thread_runner* new_runner=(thread_runner*)malloc(sizeof(thread_runner));
    new_runner->callback=callback;
    new_runner->arg=arg;
    new_runner->next=NULL;
    pthread_mutex_lock(&(pool->mutex));
    printf("add_runner locked!\n");
    if(pool->rear==NULL)
    {
        pool->front=new_runner;
        pool->rear=new_runner;
    }
    else 
    {
        pool->rear->next=new_runner;
        pool->rear=new_runner;
    }
    pthread_cond_signal(&(pool->cond));
    printf("add_runner:add a runner and wakeup a waiting thread!\n");
    pthread_mutex_unlock(&(pool->mutex));
    printf("add_runner unclocked\n");

}

void thread_pool_destroy(thread_pool** lpool)
{
    thread_pool* pool=*lpool;
    if(!(pool->shutdown))
    {
        pool->shutdown=1;
        pthread_mutex_lock(&(pool->mutex));
        printf("thread_pool_destroy locked!\n");
        pthread_cond_broadcast(&(pool->cond));
        pthread_mutex_unlock(&(pool->mutex));
        printf("thread_pool_destroy unlocked and waking up all threads!\n");
        sleep(1);
        free(pool->pthread);
        
        thread_runner*head=NULL;
        while(pool->front!=NULL)
        {
            head=pool->front;
            free(head);
            pool->front=pool->front->next;
        }
        printf("all runners freed!\n");

        pthread_mutex_destroy(&(pool->mutex));
        pthread_cond_destroy(&(pool->cond));

        printf("mutex and cond destroyed!\n");
        
        free(pool);
        *(lpool)=NULL;
        printf("pool freed!\n");
    } 
}
