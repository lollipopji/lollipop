#include <stdio.h>
#include <stdlib.h>
/*
 *
 *2路插入排序法，数据移动次数有所减少，复杂度仍为o(n^2)
 *
 */
void move_reduce_insert_sort(int arry[],int len);
void print_arry(int arry[],int len);

int main()
{
    int a[]={49,38,65,97,76,13,27,49};
    int len=sizeof(a)/sizeof(a[0]);
    move_reduce_insert_sort(a,len);
    //print_arry(a,len);
    return 0;
}
/*
 * 主要函数，以数组作为参数传递，需要在后面跟上该数组的大小作为参数
 * 绝对不能通过数组名传入函数后，再在函数中使用sizeof(a)/sizeof(a[0])的
 * 方式计算数组长度。那时sizeof(a)会将a当成是一个指针，大小为4字节。
 */
void move_reduce_insert_sort(int arry[],int len)
{
    int i,j,temp,high,low,mid;
    int a_temp[len];//需要额外的辅助数组来存放相应的整个数组。
    int first,final;
    a_temp[0]=arry[0];
    first=final=0;
    for(i=1;i<len;i++)
    {
        if(arry[i]<a_temp[0])
        {
            if(first==0)
            {
                first=len-1;
                a_temp[first]=arry[i];
            }
            else
            {
                low=first;high=len-1;
                while(low<=high)
                {
                    mid=(low+high)/2;
                    if(a_temp[mid]>arry[i])high=mid-1;
                    else low=mid+1;
                }
                for(j=first;j<=high;j++)
                {
                    a_temp[j-1]=a_temp[j];
                }
                a_temp[high]=arry[i];
                first--;
            }
        }
        else
        {
            if(final==0)
            {
                final=1;
                a_temp[final]=arry[i];
            }
            else
            {
                low=1;high=final;
                while(low<=high)
                {
                    mid=(low+high)/2;
                    if(a_temp[mid]>arry[i])high=mid-1;
                    else low=mid+1;
                }
                for(j=final;j>=high+1;j--)
                {
                    a_temp[j+1]=a_temp[j];
                }
                a_temp[high+1]=arry[i];
                final++;
            }
        }
    }
    print_arry(a_temp,len);
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

