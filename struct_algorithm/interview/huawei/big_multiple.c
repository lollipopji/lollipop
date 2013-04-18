#include <stdlib.h>
#include <stdio.h>
void Multiple(int a[],int b[],int result[])
{
    int i,j,k;
    for(i=30;i>=0;i--)
    {
        k=100-31+i;
        for(j=30;j>=0;j--)
        {
            result[k]+=a[i]*b[j];
            int update_pos=k;
            while(result[update_pos]>=10)
            {
                result[update_pos-1]+=result[update_pos]/10;
                result[update_pos]=result[update_pos]%10;
                update_pos--;
            }
            --k;
        }
    }
}
void PrintResult(int result[])
{
    int i,j;
    for(i=0;i<100;i++)
    {
        if(0!=result[i])
        {
            for(j=i;j<100;j++)
            {
                printf("%d",result[j]);
            }
            printf("\n");
            break;
        }
    }
}
int main()
{
    int a[31]={1,2,3,4,5,6,7,8,9,1,0,1,1,1,2,1,3,1,4,1,5,1,6,1,7,1,8,1,9,2,0};
    int b[31]={2,0,1,9,1,8,1,7,1,6,1,5,1,4,1,3,1,2,1,1,1,0,9,8,7,6,5,4,3,2,1};
    int result[100]={0};
    Multiple(a,b,result);
    PrintResult(result);
    return 0;
}
