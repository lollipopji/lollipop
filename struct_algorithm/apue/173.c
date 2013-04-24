#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char buf[]="This is not buffered!";
    write(STDOUT_FILENO,buf,sizeof(buf)-1);
    printf("This is buffered!\n");
    pid_t pid;
    int a=1;
    if((pid=fork())==0)
    {
        a=2;
    }
    else
    {
        sleep(2);
    }
    printf("a=%d\n",a);
    return 0;
}
