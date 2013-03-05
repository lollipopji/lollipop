#include <stdio.h>
#include <stdlib.h>
/*
 *
 *最为简单的冒泡排序，复杂度为o(n^2)
 *
 */
void bubble_sort(int arry[],int len);
void print_arry(int arry[],int len);

int main()
{
    int a[]={49,38,65,97,76,13,27};
    int len=sizeof(a)/sizeof(a[0]);
    bubble_sort(a,len);
    print_arry(a,len);
    return 0;
}
/*
 * 主要函数，以数组作为参数传递，需要在后面跟上该数组的大小作为参数
 * 绝对不能通过数组名传入函数后，再在函数中使用sizeof(a)/sizeof(a[0])的
 * 方式计算数组长度。那时sizeof(a)会将a当成是一个指针，大小为4字节。
 */
void bubble_sort(int arry[],int len)
{
    int i,j,temp,exchange_flag;
    for(i=len-1;i>0;i--)
    {
        exchange_flag=0;//在每一次的循环开始之前都设置未交换标志,如果交换了说明还需要下一次循环，否则已经是有序数列了。
        for(j=0;j<i;j++)
        {
            if(arry[j]>arry[j+1])
            {
                temp=arry[j];
                arry[j]=arry[j+1];
                arry[j+1]=temp;
                exchange_flag=1;
            }
        }
        if(exchange_flag==0)break;
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

