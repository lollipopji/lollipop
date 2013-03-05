#include <stdio.h>
#include <stdlib.h>
/*
 *
 *快速排序，复杂度为o(n*logn)
 *
 */
void quick_sort(int arry[],int low,int high);
void print_arry(int arry[],int len);

int main()
{
    int a[]={49,38,65,97,76,13,27,49};
    int len=sizeof(a)/sizeof(a[0]);
    quick_sort(a,0,len-1);
    print_arry(a,len);
    return 0;
}
/*
 * 主要函数，以数组作为参数传递，需要在后面跟上该数组的大小作为参数
 * 绝对不能通过数组名传入函数后，再在函数中使用sizeof(a)/sizeof(a[0])的
 * 方式计算数组长度。那时sizeof(a)会将a当成是一个指针，大小为4字节。
 */
void quick_sort(int arry[],int low,int high)
{
    int i,j,pivot_key,pivot_pos;
    int next_low=low;
    int next_high=high;
    pivot_key=arry[low];
    pivot_pos=low;
    while(low<high)
    {
        while(arry[high]>=pivot_key)
        {
            high--;
        }
        arry[pivot_pos]=arry[high];
        pivot_pos=high;
        while(low<high&&arry[low]<=pivot_key)
        {
            low++;
        }
        arry[pivot_pos]=arry[low];
        pivot_pos=low;
    }
    arry[pivot_pos]=pivot_key;
    if(next_low<(pivot_pos-1))
    {
         quick_sort(arry,next_low,pivot_pos-1);
    }
    if((pivot_pos+1)<next_high)
    {
        quick_sort(arry,pivot_pos+1,next_high);
    }
}
void print_arry(int arry[],int len)
{
    int i=0;
    for(i=0;i<len;i++)
    {
        printf("%d ",arry[i]);
    }
    printf("\n");
}

