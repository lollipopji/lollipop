#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1=0,n2=0,n5=0;
    int sum=15;
    int i,j,k;
    int count=0;
    for(i=0;i<=sum/5;i++)
    {
        for(j=0;j<=(sum-i*5)/2;j++)
        {
            for(k=0;k<=sum-i*5-j*2;k++)
            {
                if(i*5+j*2+k==sum)
                {
                    printf("%d %d %d\n",i,j,k);
                    count++;
                }
            }
        }
    }
    printf("There are %d kinds of result!\n",count);
    return 0;
}
