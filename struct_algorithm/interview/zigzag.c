#include <stdio.h>
#include <stdlib.h>

#define N 4

int main()
{
    int a[N][N]={0};
    int k;
    int value=0;
    int sum=N*N-1;
    for(k=0;k<N;k++)
    {
        if(0==k%2)
        {
            int p,i;
            for(i=0,p=0;p<=k;p++)
            {
                a[k-i][i]=value++;
                i++;
            }
        }
        else if(1==k%2)
        {
            int p,i;
            for(i=0,p=0;p<=k;p++)
            {
                a[i][k-i]=value++;
                i++;
            }
        }
    }
    for(k=0;k<N-1;k++)
    {
        if(0==k%2)
        {
            int p,i;
            for(i=N-1,p=0;p<=k;p++)
            {
                int temp=2*(N-1)-k;
                a[temp-i][i]=sum--;
                i--;
            }
        }
        if(1==k%2)
        {
            int p,i;
            for(i=N-1,p=0;p<=k;p++)
            {
                int temp=2*(N-1)-k;
                a[i][temp-i]=sum--;
                i--;
            }
        }
    }
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%4d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
