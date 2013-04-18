#include <stdio.h>
#include <stdlib.h>

int Sum1s(int n)
{
    int count=0;
    int factor=1;
    int lower=0;
    int current=0;
    int higher=0;
    while(n/factor!=0)
    {
        lower=n%factor;
        current=(n/factor)%10;
        higher=(n/factor)/10;
        switch(current)
        {
            case 0:
                count+=higher*factor;
                break;
            case 1:
                count+=higher*factor+lower+1;
                break;
            default:
                count+=(higher+1)*factor;
        }
        factor*=10;
    }
    return count;
}
int main()
{
    int n;
    scanf("%d",&n);
    int k=Sum1s(n);
    printf("There are %d 1s in the numbers!\n",k);
    return 0;
}

