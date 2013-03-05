#include <stdio.h>
#include <stdlib.h>

/*
 * 堆排序-最主要的是先将堆的一次调整过程思路理清楚：
 * （1）先将最后一个元素和堆顶元素进行交换（此时堆顶的左右子树都是排好的堆）
 * （2）判断是否有左子树，有的话再判断是否有右子树，如果存在右子树并且右子树比左子树要小
 * （3）那将右子树的位置保存（因为我们要沿着右子树往下走）
 * （4）之后判断父节点和子树中较小的节点哪个小，如果是子树小，那么需要对换，并且go on 否则直接break
 * 
 * 堆排序比快速排序的性能好，体现在最坏的情况下，堆排序的时间复杂度为o(nlogn)而快速排序还可能退化成冒泡排序O(n^2)
 */
void HeapCreate(int a[],int len);
void PrintArray(int a[],int len);
void HeapAdjust(int a[],int start,int end);
int main()
{
    int array[]={49,38,65,97,76,13,27,49};
    int len=sizeof(array)/sizeof(array[0]);
    HeapCreate(array,len);
    PrintArray(array,len);
    int i=0;
    for(;i<len;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
void HeapCreate(int a[],int len)
{
    int i;
    for(i=len/2-1;i>=0;i--)
    {
        HeapAdjust(a,i,len);//从下往上进行一次调整
    }
}
void HeapAdjust(int a[],int start,int len)//start从0开始，end应该是len-1
{
    int i=start,j,temp;
    for(j=2*i+1;j<len;j=j*2+1)//循环继续，说明i下面还是有子节点的
    {
        if((j+1<len)&&(a[j]>a[j+1]))++j;//用j来保存子节点中较小的那个节点下标
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
void PrintArray(int a[],int len)
{
    int i,temp;
    int end=len;
    for(i=0;i<len;i++)
    {
        printf("%d ",a[0]);
        temp=a[0];
        a[0]=a[end-1];//如果是小顶堆，那么到最后得到的数组是逆序的。
        a[end-1]=temp;
        HeapAdjust(a,0,--end);
    }
    printf("\n");
}
