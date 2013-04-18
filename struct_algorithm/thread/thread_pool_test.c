#include "thread_pool.h"

void* threadrun(void*arg)
{
    int* i=(int*)arg;
    printf("%d\n",*i);
}

int main()
{
    thread_pool* pool=(thread_pool*)malloc(sizeof(thread_pool));
    int max_thread_size=2;
    thread_pool_init(pool,max_thread_size);

    int i;
    int temp[3];
    for(i=0;i<3;i++)
    {
        temp[i]=i;
        add_runner(pool,threadrun,&temp[i]);
    }
    sleep(1);
    thread_pool_destroy(&pool);
    printf("test over!\n");
    return 0;
}
