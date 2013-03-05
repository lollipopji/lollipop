#include <stdio.h>
#include <stdlib.h>
/*
 *
 *直接插入排序法，复杂度为o(n^2)
 *
 */
void direct_insert_sort(int arry[],int len);
void print_arry(int arry[],int len);

int main()
{
    int a[]={49,38,65,97,76,13,27};
    int len=sizeof(a)/sizeof(a[0]);
    direct_insert_sort(a,len);
    print_arry(a,len);
    return 0;
}
/*
 * 主要函数，以数组作为参数传递，需要在后面跟上该数组的大小作为参数
 * 绝对不能通过数组名传入函数后，再在函数中使用sizeof(a)/sizeof(a[0])的
 * 方式计算数组长度。那时sizeof(a)会将a当成是一个指针，大小为4字节。
 */
void direct_insert_sort(int arry[],int len)
{
    int i,j,temp;
    for(i=1;i<len;i++)
    {
        if(arry[i]<arry[i-1])
        {
            temp=arry[i];
            for(j=i-1;j>=0&&temp<arry[j];j--)//j>=0主要是怕数组超出界限
            {
                arry[j+1]=arry[j];
            }
            //跳出循环两种情况：j==-1(只要将数组a[0]赋值为temp便可)
            //                  temp>=arry[j],此时temp应该放在j后面
            //以上两种情况都是将temp放置在j+1的位置上。
            arry[j+1]=temp;
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

