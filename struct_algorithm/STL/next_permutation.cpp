#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

void TestArray()
{
    char chs[]={'a','d','c','e','b'};
    int count=sizeof(chs)/sizeof(chs[0]);
    next_permutation(chs,chs+count);
    printf("TestArray:");
    int i; 
    for(i=0;i<count;i++)
    {
        printf("%c ",chs[i]);
    }
    printf("\n");
}
int main()
{
    TestArray();
    return 0;
}
