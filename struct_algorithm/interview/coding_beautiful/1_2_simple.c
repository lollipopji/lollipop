#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned char a:4;
    unsigned char b:4;
}Position;

int main ()
{
    Position pos;
    int count=0;
    for(pos.a=0;pos.a<9;pos.a++)
    {
        for(pos.b=0;pos.b<9;pos.b++)
        {
            if(pos.a%3!=pos.b%3)printf("(%d,%d)%d\n",pos.a,pos.b,++count);
        }
    }
    return 0;
}
