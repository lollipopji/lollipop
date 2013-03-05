#include <stdlib.h>
#include <stdio.h>
/*
 * 问题描述：(1)给定N，输出从1到N的全排列...
 * （2）给定一个数组，比如a b c d 输出它的全排列中的下一个序列，此时应该输出 a b d c 
 * 思路：参考STL中next_permutation(iterator begin iterator end)来实现：
 * 如果知道了（2）的方法，要计算（1）只要进行循环输出便可。
 *
 * find_next_permutation的方法：
 * （1）从数组尾端开始，找到第一个使得 a[i]<a[i+1]的地方，记录i位置（我们知道i+1到len-1都是递减的）
 * （2）再从数组尾端开始，找到第一个使得a[j]>=a[i]的j，我们也可以推断a[j]是i+1到len-1中比a[i]大的最小的数
 * （3）交换a[j]和a[i]，这样保证了交换后序列肯定比原序列要大。
 * （4）因为i+1到len-1是递减的，我们需要将它前后互换（以中轴为中心的互换）来保证这个数列是递增的，这样就保证了
 *      交换后的序列是比原序列大的最小的序列。
 *
 *  上面的一次next_permutation解决了，全排列的问题就很好解决了。
 */
int find_next_permutation(char a[],int len);//这个函数是重点
void PrintArray(char a[],int len);
int main()
{
    char a[]={'a','b','c','d'};
    int len=sizeof(a)/sizeof(a[0]);
    PrintArray(a,len);
    while(find_next_permutation(a,len))//用来计算全排列，如果有下一个排列，则输出之。
    {
        PrintArray(a,len);
    }
    return 0;
}

int find_next_permutation(char a[],int len)
{
    int i,j;
    char temp;
    //用来找到一个a[i]<a[i+1]的地方
    for(i=len-2;i>=0;i--)
    {
        if(a[i]<a[i+1])break;
    }
    if(i<0)return 0;
    else
    {
        for(j=len-1;j>=i+1;j--)
        {
            if(a[i]<a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                break;
            }
        }
        //用来进行后端序列的逆序，保证得到的序列是比原序列大的最小的序列
        for(j=i+1;j<=(i+len)/2;j++)
        {
            temp=a[j];
            a[j]=a[len+i-j];
            a[len+i-j]=temp;
        }
    }
    return 1;
}
void PrintArray(char a[],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%c ",a[i]);
    }
    printf("\n");
}

