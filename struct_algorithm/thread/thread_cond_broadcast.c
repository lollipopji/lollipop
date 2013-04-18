#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

typedef struct ARG{
    int no;
    char str[10];
}Arg;

pthread_mutex_t mutex;
pthread_cond_t cond;
int g_flag=0;
pthread_t thread_1,thread_2;


void* thread1(void* arg)
{
    printf("%s:I am thread %d\n",(*((Arg*)arg)).str,(*((Arg*)arg)).no);
    pthread_mutex_lock(&mutex);
    g_flag=1;
    printf("I am thread1,g_flag is %d\n",g_flag);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    printf("thread1 leave!\n");
    pthread_exit(NULL);
}
void* thread2(void* arg)
{
    printf("%s:I am thread %d\n",(*((Arg*)arg)).str,(*((Arg*)arg)).no);
    //pthread_mutex_unlock(&mutex);
    pthread_mutex_lock(&mutex);
    while(g_flag!=1)
        pthread_cond_wait(&cond,&mutex);
    g_flag=2;
    printf("I am thread2,g_flag is %d\n",g_flag);
    pthread_mutex_unlock(&mutex);
    printf("thread2 leave!\n");
    pthread_exit(NULL);
}
int main()
{
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    int temp;
    Arg arg;
    arg.no=2;
    strncpy(arg.str,"thread2",sizeof(arg.str)-1);
    arg.str[sizeof(arg.str)-1]='\0';
    if((temp=pthread_create(&thread_2,NULL,thread2,&arg))!=0)
        printf("create thread2 error!\n");
    else printf("create thread2 OK!\n");
    arg.no=1;
    strncpy(arg.str,"thread1",sizeof(arg.str)-1);
    arg.str[sizeof(arg.str)-1]='\0';
    if((temp=pthread_create(&thread_1,NULL,thread1,&arg))!=0)
        printf("create thread1 error!\n");
    else printf("create thread1 OK!\n");
    //pthread_cond_wait(&cond,&mutex);
    //printf("Thread1 comes here!\n");
    pthread_join(thread_2,NULL);
    printf("main exit!\n");
    return 0;
}
