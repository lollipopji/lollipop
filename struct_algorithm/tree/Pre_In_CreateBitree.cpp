#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

typedef struct BitNode{
    char flag;
    struct BitNode *lchild,*rchild;
}BitNode,*BiTree;

BiTree Rebuild(char pre[],int pre_start,int pre_end,char in[],int in_start,int in_end)
{
    if(pre_start<=pre_end)
    {
        BiTree T;
        T=(BiTree)malloc(sizeof(BitNode));
        if(!T){printf("overflow!\n");exit(1);}
        T->flag=pre[pre_start];
        if(pre_start==pre_end)
        {
            T->lchild=NULL;
            T->rchild=NULL;
            return T;
        }
        else
        {
            int i;
            for(i=in_start;i<=in_end;i++)
            {
                if(pre[pre_start]==in[i])break;
            }
            if(i>in_end) return NULL;
            else
            {
                T->lchild=Rebuild(pre,pre_start+1,pre_start+i-in_start,in,in_start,i-1);
                T->rchild=Rebuild(pre,pre_start+i-in_start+1,pre_end,in,i+1,in_end);
            }
            return T;
        }
    }
    else return NULL;
}
void InOrderVisit(BiTree T)
{
    if(T)
    {
        InOrderVisit(T->lchild);
        printf("%c ",T->flag);
        InOrderVisit(T->rchild);
    }
}
/*
 * 这是中序遍历二叉树的非递归版本：
 */
void InOrderVisit_Stack(BiTree T)
{
    stack<BiTree> in_stack;
    BiTree p=T;
    while(p||!in_stack.empty())
    {
        if(p)
        {
            in_stack.push(p);
            p=p->lchild;
        }
        else
        {
            p=in_stack.top();
            printf("%c ",p->flag);
            in_stack.pop();
            p=p->rchild;
        }
    }
}

void DepthVisit(BiTree T)
{
    queue<BiTree>depth_queue;
    depth_queue.push(T);
    BiTree p;
    while(!depth_queue.empty())
    {
        p=depth_queue.front();
        printf("%c ",p->flag);
        depth_queue.pop();
        if(p->lchild)depth_queue.push(p->lchild);
        if(p->rchild)depth_queue.push(p->rchild);
    }
}

void PreOrderVisit(BiTree T)
{
    if(T)
    {
        printf("%c ",T->flag);
        PreOrderVisit(T->lchild);
        PreOrderVisit(T->rchild);
    }
}
void PostOrderVisit(BiTree T)
{
    if(T)
    {
        PostOrderVisit(T->lchild);
        PostOrderVisit(T->rchild);
        printf("%c ",T->flag);
    }
}

//前序遍历求二叉树中叶子节点的个数
void CountLeaves(BiTree T,int &count)
{
   if(T) 
   {
       if(T->lchild==NULL && T->rchild==NULL)
        count++;
       else
        {
            CountLeaves(T->lchild,count);
            CountLeaves(T->rchild,count);
        }
   }
}

//这是使用递归的方式求二叉树的深度
int Depth(BiTree T)
{
    if(T)
    {
        if(T->lchild==NULL && T->rchild==NULL)
            return 1;
        int left_depth=Depth(T->lchild);
        int right_depth=Depth(T->rchild);
        int max_depth=(left_depth>right_depth)?left_depth+1:right_depth+1;
        return max_depth;
    }
}
int main()
{
    char pre[]="ABDHJEICFG";
    char in[]="DJHBEIAFCG";
    int lenth=sizeof(pre)-1;
    BiTree T=Rebuild(pre,0,lenth,in,0,lenth);
    printf("非递归中序遍历的结果是：");
    InOrderVisit_Stack(T);
    printf("\n前序遍历的结果是：");
    PreOrderVisit(T);
    printf("\n后序遍历的结果是：");
    PostOrderVisit(T);
    printf("\n深度遍历的结果是：");
    DepthVisit(T);
    printf("\n");
    int count=0;
    CountLeaves(T,count);
    printf("There are %d leaves!\n",count);
    int depth=Depth(T);
    printf("The depth of the tree is %d!\n",depth);
    return 0;
}
