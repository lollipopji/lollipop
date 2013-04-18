#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100

/*************************双堆实现中位数*******************
 * 使用最大堆和最小堆实现中位数的查找
参考链接：http://www.jishu521.com/post/imzooer/8010506.html
求数组中位数的方法：
用堆维护中位数的意思是说，设计两个堆，第一个堆(大顶堆)存放小于中位数的元素，第二个堆(小顶堆)存放大于中位数的元素。

下面是双堆维护中位数的语言描述：
1、初始化的时候设置两个变量分别记录两个堆【左堆和右堆】的元素的个数。
2、取第一个元素d[0]作为初始中位数m。
3、循环后面的每一个元素，如果比m大，则插入到右堆，如果比m小，则插入到左堆。
4、.如果此时最小堆和最大堆的元素个数的差值>=2 ，则将m加入到元素个数少的堆中，然后从元素个数多的堆将根节点赋值到m，最后重建两个最大堆和最小堆，返回到3。

此时，如果想要知道当前的中位数，若左右堆的元素个数相等，则输出左右堆顶元素的平均值，否则输出堆元素个数较大堆的堆顶元素。
*/
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int MaxHeapPopAdjust(int max_heap[])
{
    int len=max_heap[0];
    int ret;
    if(len>0)
    {
        ret=max_heap[1];
        max_heap[1]=max_heap[len];
        int i=1,j;
        while(2*i<=len)
        {
            if((2*i+1<=len) && (max_heap[2*i+1]>max_heap[2*i]))j=2*i+1;
            else j=2*i;
            if(max_heap[i]<max_heap[j])
            {
                swap(&max_heap[i],&max_heap[j]);
                i=j;
            }
            else break;

        }
        --max_heap[0];
        return ret;
    }
}

int MinHeapPopAdjust(int min_heap[])
{
    int len=min_heap[0];
    int ret;
    if(len>0)
    {
        ret=min_heap[1];
        min_heap[1]=min_heap[len];
        int i=1,j;
        while(2*i<=len)
        {
            if((2*i+1<=len) && (min_heap[2*i+1]<min_heap[2*i]))j=2*i+1;
            else j=2*i;
            if(min_heap[i]>min_heap[j])
            {
                swap(&min_heap[i],&min_heap[j]);
                i=j;
            }
            else break;

        }
        --min_heap[0];
        return ret;
    }
}

void MaxHeapPushAdjust(int max_heap[],int elem)
{
    max_heap[0]++;
    max_heap[max_heap[0]]=elem;
    int i=max_heap[0];
    while(i/2>0)
    {
        if(max_heap[i/2]<max_heap[i])
        {
            swap(&max_heap[i/2],&max_heap[i]);
            i=i/2;
        }
        else break;
    }
    
}

void MinHeapPushAdjust(int min_heap[],int elem)
{
    min_heap[0]++;
    min_heap[min_heap[0]]=elem;
    int i=min_heap[0];
    while(i/2>0)
    {
        if(min_heap[i/2]>min_heap[i])
        {
            swap(&min_heap[i/2],&min_heap[i]);
            i=i/2;
        }
        else break;
    }
}
int FindMiddle(int array[],int max_heap[],int min_heap[])
{
    int middle=0;
    int array_len=array[0];
    int i;
    for(i=1,middle=array[1];i<=array_len;i++)
    {
        if(array[i]<middle)MaxHeapPushAdjust(max_heap,array[i]);
        else MinHeapPushAdjust(min_heap,array[i]);
        if(max_heap[0]-min_heap[0]==2)
        {
            middle=MaxHeapPopAdjust(max_heap);
            MinHeapPushAdjust(min_heap,middle);
        }
        else if (min_heap[0]-max_heap[0]==2)
        {   
            middle=MinHeapPopAdjust(min_heap);
            MaxHeapPushAdjust(max_heap,middle);
        }
    }
    printf("%d %d\n",max_heap[0],min_heap[0]);
    if(max_heap[0]-min_heap[0]==-1)
        printf("The middle num is %d\n",min_heap[1]);
    else if(max_heap[0]-min_heap[0]==-1)
        printf("The middle num is %d\n",max_heap[1]);
    else
        printf("The middle num is %f\n",(min_heap[1]+max_heap[1])/2.0);

}
int main()
{
    int array[]={7,13,51,34,200,30,40,66,10,70,20,60};
    int len=sizeof(array)/sizeof(array[0])-1;
    array[0]=len;
    int max_heap[MAXLEN];
    int min_heap[MAXLEN];
    max_heap[0]=0;
    min_heap[0]=0;
    FindMiddle(array,max_heap,min_heap);
    return 0;
}
