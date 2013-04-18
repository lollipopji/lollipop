#include <stdio.h>
#include <stdlib.h>

int BitCount(unsigned int n)
{
    unsigned int temp=n-((n>>1)&033333333333)-((n>>2)&011111111111);
    return ((temp+(temp>>3))&030707070707)%63;
}
int main()
{
    unsigned int n=659;
    printf("%d\n",BitCount(n));
}

