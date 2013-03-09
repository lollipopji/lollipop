#include <stdio.h>
#include <stdlib.h>

/*
 *  merge_sort: 主要的思想是 递归+合并 时间复杂度为O(nlogn)在n较大的情况下，归并排序比堆排序的时间复杂度好（虽然
 *  都是在O(nlogn)的数量级上），但是归并排序有一个比较差的性能是它的空间复杂度是O(n)，这个性能是比堆排序差的
 *
 *  总的比较下来，快速排序的时间复杂度应该是所有排序方法中最小的（指的是在平均复杂度） 堆排序在最坏的情况下时间复杂度
 *  仍然是O(nlogn)
 *
 */
void Merge(int a[],int low,int high);
void Sort(int a[],int low,int high);
void PrintArray(int a[],int len);

int main()
{
    int array[]={49,38,65,97,76,13,27,49};
    int len=sizeof(array)/sizeof(array[0]);
    Sort(array,0,len-1);
    PrintArray(array,len);
    return 0;
}

//主要思想是利用递归：递归退出条件：当要排序的序列只有一个元素时。
void Sort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        Sort(a,low,mid);
        Sort(a,mid+1,high);
        Merge(a,low,high);
    }

}

//这个和之前在数据结构的链表中提到的有序链表合并的思想类似
void Merge(int a[],int low,int high)
{
    int mid=(low+high)/2;
    int temp[high-low+1];//需要用到辅助空间来存放合并后的数组。（如果不采用辅助空间，在算法复杂度上比较高）
    int i=low;
    int j=mid+1;
    int k=0;
    //哪个小，就将哪个移入到辅助数组中去
    while(i<=mid&&j<=high)
    {
        if(a[i]<=a[j])temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    //在low部分全部移入辅助数组之后（可能high部分还没有完全移入辅助数组，则将high部分剩余的全部移入）
    if(i>mid)
    {
        for(;k<high-low+1;k++)
        {
            temp[k]=a[j++];
        }
    }
    //与上面类似
    else if(j>high)
    {
        for(;k<high-low+1;k++)
        {
            temp[k]=a[i++];
        }
    }
    //使用辅助数组更新我们原先的数组
    for(k=0;k<high-low+1;k++)
    {
        a[low+k]=temp[k];
    }
}

//打印排序后的数组
void PrintArray(int a[],int len)
{
    int i;
    printf("After sorted,the array is:");
    for(i=0;i<len;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
