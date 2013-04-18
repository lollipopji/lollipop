#include <stdio.h>
#include <stdlib.h>

int Partition(int a[],int low,int high)
{
    int key=a[low];
    while(low<high)
    {
        while(a[high]>=key && low<high)--high;//快排很容易出现问题的地方就是low<high忘了写
        if(low<high)a[low++]=a[high];//将high的值移动到low,并且此时应该将low++
        else break;
        while(a[low]<=key && low<high)++low;
        if(low<high)a[high--]=a[low];
        else break;
    }
    //printf("@@@@@@@@@@@%d\n",low);
    a[low]=key;
    return low;
}
void QuickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int low_keep=Partition(a,low,high);
        QuickSort(a,low,low_keep-1);
        QuickSort(a,low_keep+1,high);
    }
}
void PrintArray(int a[],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[]={49,38,65,97,76,13,27,49};
    int len=sizeof(a)/sizeof(a[0]);
    QuickSort(a,0,len-1);
    PrintArray(a,len);
    return 0;
}
