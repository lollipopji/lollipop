#include <stdlib.h>
#include <stdio.h>
/*
 * 使用前序的字符串来创建一颗树：ABC##DE#G##F###(就应该按照这个来进行输入)
 * 然后使用递归的方式（前、中、后）序遍历二叉树
 *
 */
typedef struct BitNode
{
    char flag;
    struct BitNode *lchild, *rchild;
}BitNode,*BiTree;

BiTree CreateBitree(void)
{
    char c;
    BiTree T;
    scanf("%c",&c);
    if(c=='#')T=NULL;
    else
    {
        T=(BiTree)malloc(sizeof(BitNode));
        if(!T) {printf("Overflow!\n");exit(1);}
        T->flag=c;
        T->lchild=CreateBitree();
        T->rchild=CreateBitree();
    }
    return T;
}
void PreOrderVisit(BiTree T)
{
    if(T)
    {
        printf("%c",T->flag);
        PreOrderVisit(T->lchild);
        PreOrderVisit(T->rchild);
    }
}
void InOrderVisit(BiTree T)
{
    if(T)
    {
        InOrderVisit(T->lchild);
        printf("%c",T->flag);
        InOrderVisit(T->rchild);
    }
}
void PostOrderVisit(BiTree T)
{
    if(T)
    {
        PostOrderVisit(T->lchild);
        PostOrderVisit(T->rchild);
        printf("%c",T->flag);
    }
}

int main()
{
    BiTree bit_tree=CreateBitree();
    PreOrderVisit(bit_tree);
    printf("\n");
    InOrderVisit(bit_tree);
    printf("\n");
    PostOrderVisit(bit_tree);
    printf("\n");
    return 0;
}
