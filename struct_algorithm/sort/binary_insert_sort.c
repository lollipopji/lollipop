#include <stdio.h>
#include <stdlib.h>
/*
 *
 *折半插入排序法，数据移动次数与直接插入排序法一样，只是对有序数组的查找使用了
 *折半查找，复杂度仍为o(n^2)
 *
 */
void binary_insert_sort(int arry[],int len);
void print_arry(int arry[],int len);

int main()
{
    int a[]={49,38,65,97,76,13,27};
    int len=sizeof(a)/sizeof(a[0]);
    binary_insert_sort(a,len);
    print_arry(a,len);
    return 0;
}
/*
 * 主要函数，以数组作为参数传递，需要在后面跟上该数组的大小作为参数
 * 绝对不能通过数组名传入函数后，再在函数中使用sizeof(a)/sizeof(a[0])的
 * 方式计算数组长度。那时sizeof(a)会将a当成是一个指针，大小为4字节。
 */
void binary_insert_sort(int arry[],int len)
{
    int i,j,temp,high,low,mid;
    for(i=1;i<len;i++)
    {
        if(arry[i]<arry[i-1])
        {
            temp=arry[i];
            low=0;high=i-1;
            while(low<=high)//折半的方法退出条件总是high要比low小1，此时low的位置就是可以存放的位置。
            {
                mid=(low+high)/2;
                if(arry[mid]>temp)high=mid-1;
                else low=mid+1;
            }
            for(j=i-1;j>=high+1;j--)
            {
                arry[j+1]=arry[j];
            }
            arry[high+1]=temp;
        }
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

