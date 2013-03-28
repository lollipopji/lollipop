#include <stdio.h>
#include <stdlib.h>
void HeapAdjust(int a[],int start,int end)
{
    int i=start,j,temp;
    while(2*i+1<=end)
    {
        if(2*i+2<=end && a[2*i+1]>a[2*i+2])j=2*i+2;
        else j=2*i+1;
        if(a[i]>a[j])
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
        }
        else break;
    }

}

void HeapCreate(int a[],int len)
{
    int start=len/2-1;
    int i;
    for(i=start;i>=0;i--)
    {
        HeapAdjust(a,i,len-1);
    }
}
void PrintArray(int a[],int len)
{
    int i=0;
    int end=len-1;
    for(i=0;i<len;i++)
    {
        printf("%d ",a[0]);
        a[0]=a[end--];
        HeapAdjust(a,0,end);
    }
    printf("\n");
}
int main()
{
    int a[]={49,38,65,97,76,13,27,49};
    int len=sizeof(a)/sizeof(a[0]);
    HeapCreate(a,len);
    PrintArray(a,len);
    return 0;
}
