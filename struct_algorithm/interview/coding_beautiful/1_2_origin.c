#include <stdio.h>
#include <stdlib.h>

#define HALF_BITS_LENGTH 4
#define FULLMASK 0xFF
#define LEFTMASK (FULLMASK<<HALF_BITS_LENGTH)
#define RIGHTMASK (FULLMASK>>HALF_BITS_LENGTH)
#define GETLEFT(n) ((n & LEFTMASK)>>HALF_BITS_LENGTH)
#define GETRIGHT(n) (n & RIGHTMASK)
#define SETLEFT(n,elem) (n=(n & RIGHTMASK) | ((elem)<<HALF_BITS_LENGTH))
#define SETRIGHT(n,elem) (n=(n & LEFTMASK) | (elem)) 

int main()
{
    unsigned char a;
    int count=0;
    for(SETLEFT(a,0);GETLEFT(a)<=8;SETLEFT(a,(GETLEFT(a)+1)))
    {
        for(SETRIGHT(a,0);GETRIGHT(a)<=8;SETRIGHT(a,(GETRIGHT(a)+1)))
        {
            if(GETLEFT(a)%3!=GETRIGHT(a)%3)
                printf("(%d,%d) %d\n",GETLEFT(a),GETRIGHT(a),++count);
        }
    }
    return 0;
}
