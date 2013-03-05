#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
/*
 *问题描述：给定两个不带环单链表L1和L2，判断它们是否相交并求出交点位置。所谓
 *相交就是两个节点的下一个节点指向了同一个节点。
 *思路一：先遍历求出两个链表的长度len1和len2，然后计算长度之差d=|len1-len2|,
          再让长的那个链表先走d步，然后两个链表同步往后走，如果遇到next相同
          的节点，那么next的值就是交点的位置。此方法的时间复杂度o(max(len1,len2))
          空间复杂度较小
 *思路二：利用栈。遍历两个链表，并将地址放入到两个栈中。再两个栈同步退栈，并且比较
          退栈得到的内容，如果是相同的，则继续，否则退出退栈的循环。没有相同的表示
          没有交点，否则，此时的就是交点。时间复杂度仍然是0(max(len1,len2)),需要使用
          栈空间来存放相应的数据，空间复杂度比较高。
 */
typedef struct Node
{
    int num;
    struct Node * next;
}Node;

void InitLink(Node* link_a,Node* link_b);
void PrintLink(Node* link_a,Node* link_b);
void InitPointerArray(Node* link_a,vector<Node*> &array_a,Node* link_b,vector<Node*> &array_b);
void Judge(const vector<Node*> &array_a,const vector<Node*> &array_b);
int main()
{
    Node* link_a=(Node*)malloc(sizeof(Node));
    Node* link_b=(Node*)malloc(sizeof(Node));
    link_a->next=NULL;
    link_b->next=NULL;//我们构造的是两个带头结点的链表
    InitLink(link_a,link_b);//初始化链表
    //PrintLink(link_a,link_b);
    vector<Node*> array_a;
    vector<Node*> array_b;//使用vector来模拟栈的内容
    InitPointerArray(link_a,array_a,link_b,array_b);//遍历链表中的元素，存入到栈中
    Judge(array_a,array_b);//判断是否有交点，并且输出信息。
}

void InitLink(Node* link_a,Node* link_b)
{
    int i=0,j=0;
    Node* a=link_a;
    Node* b=link_b;
    for(i=0;i<4;i++)
    {
        Node* temp=(Node*)malloc(sizeof(Node));
        temp->num=i;
        temp->next=NULL;
        a->next=temp;
        a=temp;
    }
    for(i=4;i<8;i++)
    {
        Node* temp=(Node*)malloc(sizeof(Node));
        temp->num=i;
        temp->next=NULL;
        b->next=temp;
        b=temp;
    }
    for(i=8;i<12;i++)
    {
        Node* temp=(Node*)malloc(sizeof(Node));
        temp->num=i;
        temp->next=NULL;
        a->next=temp;
        b->next=temp;
        a=b=temp;
    }
}

void PrintLink(Node* link_a,Node* link_b)
{
    Node* a=link_a->next;
    Node* b=link_b->next;
    printf("This is link a:");
    while(a!=NULL)
    {
        printf("%d ",a->num);
        a=a->next;
    }
    printf("\nThis is link b:");
    while(b!=NULL)
    {
        printf("%d ",b->num);
        b=b->next;
    }
    printf("\n");

}
//需要注意的是vector数组应该采用引用类型的。
void InitPointerArray(Node* link_a,vector<Node*> &array_a,Node* link_b,vector<Node*> &array_b)
{
    Node* a=link_a->next;
    int i=0;
    while(a!=NULL)
    {
        array_a.push_back(a);
        a=a->next;
    }
    Node* b=link_b->next;
    i=0;
    while(b!=NULL)
    {
        array_b.push_back(b);
        b=b->next;
    }
}


void Judge(const vector<Node*> &array_a,const vector<Node*> &array_b)
{
    vector<Node*>::const_iterator a_pos=array_a.end()-1;//对于const 引用，使用const_iterator
    vector<Node*>::const_iterator b_pos=array_b.end()-1;
    int com_size=((array_a.size()>array_b.size())?array_b.size():array_a.size());
    int i=0;int count=0;
    for(i=0;i<com_size;i++)
    {
        if(*a_pos!=*b_pos)break;
        else
        {
            count++;
            --a_pos;
            --b_pos;
        }
    }
    if(count==0)printf("没有相交\n");
    else printf("在倒数第%d个相交\n",count);
}
