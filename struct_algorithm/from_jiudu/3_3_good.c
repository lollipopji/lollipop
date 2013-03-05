#include <stdio.h>
#include <stdlib.h>
/*
 * 问题描述：现在有n个数，其中3个数的和为K，试着找出这3个数值（可能存在很多种组合）
 * 思路一：先排序（使用快速排序需要O(nlogn)），然后先取a[i](i从0到len-1)，再从i+1到len-1
 * 中选择两个数使得它们的和为sum-a[i]...具体做法是判断a[low]+a[high]与（sum-a[i]）的大小关系
 * 若大于，那么high--，若小于low++，相等就输出（还需要继续判断：low++,high--）
 */
void QuickSort(int arry[],int low,int high);
void Judge(int arry[],int len,int sum);

int main()
{
    int a[]={19,25,13,10,2,5,1,8,7,9};
    int len=sizeof(a)/sizeof(a[0]);
    QuickSort(a,0,len-1);
    int sum;
    printf("Please input the sum:");
    scanf("%d",&sum);
    Judge(a,len,sum);
}

void QuickSort(int arry[],int low,int high)
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
         QuickSort(arry,next_low,pivot_pos-1);
    }
    if((pivot_pos+1)<next_high)
    {
        QuickSort(arry,pivot_pos+1,next_high);
    }
}

void Judge(int arry[],int len,int sum)
{
    int i,low,high;
    int two_sum;//用来存放减去最小一个数后得到的两个值得sum
    for(i=0;i<=len-3;i++)
    {
        low=i+1;
        high=len-1;
        if(arry[i]*3>sum)break;//因为a[i]是3个数中最小的，所以当a[i]的3倍比sum还大时，没有必要go on了
        two_sum=sum-arry[i];
        while(low<high)
        {
            if((2*arry[low]>two_sum)||(2*arry[high]<two_sum))//当最小值的两倍比sum大或者最大值的两倍比sum还小时，那么退出判断
                break;
            else
            {
                if(arry[low]+arry[high]<two_sum)
                {
                    low++;
                }
                else if(arry[low]+arry[high]>two_sum)
                {
                    high--;
                }
                else
                {
                    //需要明确的一个条件是:在数组中没有相同的数出现。
                    printf("%d+%d+%d=%d\n",arry[i],arry[low],arry[high],sum);
                    low++;
                    high--;
                }
            }
        }
    }
}
