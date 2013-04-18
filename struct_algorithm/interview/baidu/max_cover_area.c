#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100
#define MIN(a,b) ((a)>(b))?(b):(a)
typedef struct{
    int begin;
    int end;
}Regin;

int Compare_LT(const Regin regin_a,const Regin regin_b)
{
    if((regin_a.begin < regin_b.begin) ||((regin_a.begin==regin_b.begin) && (regin_a.end < regin_b.end)) )
        return 1;//means a is little than b
    else return 0;
}
int Partition(Regin regin[],int low,int high)
{
    Regin regin_key=regin[low];
    while(low<high)
    {
        while(low<high && Compare_LT(regin_key,regin[high]))--high;
        if(low<high)regin[low++]=regin[high];
        else break;
        while(low<high && Compare_LT(regin[low],regin_key))++low;
        if(low<high)regin[high--]=regin[low];
        else break;
    }
    regin[low]=regin_key;
    return low; 
}
void QuickSort(Regin regin[],int low,int high)
{
    if(low<high)
    {
        int low_keep=Partition(regin,low,high);
        QuickSort(regin,low,low_keep-1);
        QuickSort(regin,low_keep+1,high);
    }
}

void MaxCoverArea(Regin regin[],int len)
{
    int i,j;
    int max_len=0;
    Regin regin_a,regin_b;
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(regin[i].end<=regin[j].begin)break;
            else
            {
                int temp;
                if(regin[i].end>regin[j].end)
                    temp=regin[j].end;
                else temp=regin[i].end;
                if (temp-regin[j].begin>max_len)
                {
                    max_len=temp-regin[j].begin;
                    regin_a=regin[i];
                    regin_b=regin[j];
                }
            }
        }
    }
    printf("The max_length cover area is %d\n",max_len);
    printf("It is produced by (%d,%d) and (%d,%d)\n",regin_a.begin,regin_a.end,regin_b.begin,regin_b.end);
}
int main()
{
    Regin regin[MAXLEN];
    regin[0].begin=2;
    regin[0].end=10;

    regin[1].begin=0;
    regin[1].end=8;

    regin[2].begin=1;
    regin[2].end=6;
    int i;
    for(i=0;i<3;i++)
    {
        printf("%d %d \n",regin[i].begin,regin[i].end);
    }
    QuickSort(regin,0,2);
    printf("After quick sort:\n");
    for(i=0;i<3;i++)
    {
        printf("%d %d \n",regin[i].begin,regin[i].end);
    }
    MaxCoverArea(regin,3);
    return 0;
}
