#include <stdio.h>
#include <stdlib.h>
/*
 * 问题描述：使用归并排序实现逆序数的计算
 * 所谓逆序数是指顺序颠倒的对数，比如(3,2,1)那么顺序颠倒的是(3,2) (2,1) (3,1)是颠倒的
 * 正常的解法是两个循环O(n^2)，我们使用归并排序来实现逆序数的计算
 * {}{}前后两个集合进行合并的时候，如果此时选择后面的集合进行插入，那么这个元素相当于前面集合所剩的元素都是逆序的。
 */
static int count=0;

void Merge(int a[],int low,int high)
{   
    int mid=(low+high)/2;
    int temp[high-low+1];
    int i=low,j=mid+1;
    int k=0;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
            count+=(mid-i+1);//逆序只存在于这种情况：{}{}后面的集合中往temp插入，此时前面的集合中还有数据...那么前面集合中的数据对于后面的那个插入的数来说是逆序的。
        }
    }
    if(i<=mid)
    {
        while(i<=mid)temp[k++]=a[i++];//前面的数插在后面（这些逆序的情况在之前已经全部被考虑过了）
    }
    else if(j<=high)
    {
        while(j<=high)temp[k++]=a[j++];//后面的数插在后面说明对于前面集合的所有数来说，他们都是正序的
    }
    for(i=0;i<k;i++)
    {
        a[low+i]=temp[i];
    }
}
void MergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int middle=(low+high)/2;
        MergeSort(a,low,middle);
        MergeSort(a,middle+1,high);
        Merge(a,low,high);
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
    int a[]={49,38,65,97,76,13,27};
    int len=sizeof(a)/sizeof(a[0]);
    MergeSort(a,0,len-1);
    printf("The inversion number is %d\n",count);
    printf("After sort:");
    PrintArray(a,len);
    return 0;
}
