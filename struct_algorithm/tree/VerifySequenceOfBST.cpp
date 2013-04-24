#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

/*
 * 判断某一个数组是否是搜索二叉树的后序遍历
 * 思路：后续遍历，最后面一个是树的根，而且搜索二叉树还满足，根的左子树都是小于根，右子树都大于根
 * 所以我们还是使用递归的方式去判断是否符合搜索二叉树的性质，如果有一个不满足（右子树中有数小于根或者左子树中有数大于根）
 * 那么我们就判断这并不是搜索二叉树的后序遍历
*/
bool VerifySequenceOfBST(int a[],int len)
{
    if(a==NULL || len<=0)return false;//notice
    if(len==1) return true;//notice
    int root=a[len-1];
    int i;
    for(i=0;i<len-1;i++)
    {
        if(a[i]>root)break;
    }
    int j=i+1;
    for(;j<len-1;j++)
    {
        if(a[j]<root) return false;//notice这些地方都是递归返回的地方，需要特别小心！
    }
    bool left=true;
    left=VerifySequenceOfBST(a,i);
    bool right=true;
    right=VerifySequenceOfBST(a+i,len-i-1);
    return (left && right);
}
int main()
{
    int a[]={5,7,6,9,11,10,8};
    int a1[]={7,4,6,5};
    int len=sizeof(a1)/sizeof(a1[0]);
    if(VerifySequenceOfBST(a1,len))printf("It is True!\n");
    else printf("It is not a qualified one!\n");
    return 0;
}

