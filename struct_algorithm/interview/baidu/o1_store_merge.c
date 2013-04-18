#include <stdio.h>
#include <stdlib.h>

void O1StoreMerge(int a[],int a_start,int a_end,int b_start,int b_end)
{
    if(b_start<b_end)
    {int i,j,k,m;
    for(i=a_start;i<=a_end;i++)
    {
        if(a[i]>a[b_start])
        {
            k=i;
            break;
        }
    }
    if(i!=a_end+1)
    {
        for(j=b_start+1;j<=b_end;j++)
        {
            if(a[j]>a[i])
            {
                break;
            }
        }
        m=j;
        int temp,p,q;//the only one to be stored
        for(p=0;p<j-b_start;p++)
        {
            temp=a[j-1];
            q=j-1;
            while(q!=i-1)
            {
                a[q]=a[j-1];
                q--;
            }
            a[i]=temp;
        }
        O1StoreMerge(a,i,j-1,j,b_end);
    }
    }
}

int main()
{
    int a[]={3,5,6,8,10,1,2,4,7,9};
    int len=sizeof(a)/sizeof(a[0]);
    int a_start=0,a_end=len/2-1,b_start=len/2,b_end=len-1;
    O1StoreMerge(a,a_start,a_end,b_start,b_end);
    int q=0;
    for(q=0;q<10;q++)
    {
        printf("%d\n",a[q]);
    }
    return 0;
}
