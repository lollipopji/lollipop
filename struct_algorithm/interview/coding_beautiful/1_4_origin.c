#include <stdlib.h>
#include <stdio.h>
#define MAX 10000
typedef struct{
    int kind;
    int min;
}Info;

Info GetInfo(int a[],int len)
{
    int i;
    Info info;
    for(info.kind=0,info.min=MAX,i=0;i<len;i++)
    {
        if(a[i]>0)
        {
            if(a[i]<info.min)info.min=a[i];
            info.kind++;
        }
    }
    return info;
}
void UpdateInfo(int a[],int len,Info info)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(a[i]>0)
        {
            a[i]-=info.min;
        }
    }
}
int main()
{
    int a[]={2,2,2,1,1};
    float discount[]={1,0.95,0.9,0.8,0.75};
    int len=sizeof(a)/sizeof(a[0]);
    Info info=GetInfo(a,len);
    float sum=0.0;
    while(info.kind!=0)
    {
        sum+=info.kind*8*info.min*discount[info.kind-1];
        printf("%f\n",sum);
        UpdateInfo(a,len,info);
        info=GetInfo(a,len);
    }
    printf("You need to pay %f EUR!\n",sum);
    return 0;
}
