#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int start_flag=0;
    for(i=2;i<=sqrt(n);i++)
    {
        if(0==n%i)
        {
            n/=i;
            if(0==start_flag)
            {
                printf("%d",i--);
                start_flag=1;
            }
            else
                printf("*%d",i--);
        }
    }
    printf("*%d",n);
    return 0;
}
