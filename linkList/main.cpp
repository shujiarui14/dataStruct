#include <stdio.h>
#include <stdlib.h>
#include "./likList.h"

int main()
{
    
    int i=0;
    LNList L;
    initLNodeLIst(L);
    for(;i<10;i++)
    {
        listInsert(L,(i+1),(i+2));
    }
    printList(L);
    listNextInsert(L->next->next,99);
    printList(L);
    listPriorInsert(L->next->next,88);
    printList(L);
    int del;
    DelList(L,2,del);
    printf("删除的是%d\n",del);
    printList(L);
    DelNode(L->next->next->next);
    printList(L);
    printf("第7个元素是%d\n",getElem(L,7)->data);
    printf("10在第%d号位置上\n",locateElem(L,10));
    listInsert(L,11,12);
    listInsert(L,1,1);
    printList(L);
    printf("现在的表长为：%d\n",getLength(L));
    return 0;
}


void initLNodeList0(LNList &L)
{
    L=NULL;
}//不带头节点的初始化

bool initLNodeLIst(LNList &L)
{
    L=(LNode*)malloc(sizeof(LNode));
    if(L==NULL)
    {
        return false;
    }
    L->next=NULL;
    return true;
}

bool listEmpty(LNList L)
{
    if(L->next==NULL)
        return true;
    else
    return false;
}

int getLength(LNList L)
{
    int count=0;
    while(L->next!=NULL)
    {
        count+=1;
        L=L->next;
    }
    return count;
}
//代头节点的插入
bool listInsert0(LNList &L,int i,int e)
{
    if(i==1)
    {
        LNode* in=(LNode*)malloc(sizeof(LNode));
        in->data=e;
        in->next=L;
        L=in;
        return true;
    }

    LNode* move=(LNode*)malloc(sizeof(LNode));
    move=L;
    int j=0;
    for(;j<i-1&&move!=NULL;j++)
    {
        move=move->next;
    }
    if(move==NULL)
    {
        return false;
    }
    LNode* in=(LNode*)malloc(sizeof(LNode));
    in->data=e;
    in->next=move->next;
    move->next=in;
    return true;
}

//不带头节点的插入
bool listInsert(LNList &L,int i,int e)
{
    if(i<1)
    {
        return false;
    }
    int j=0;
    LNode* move=(LNode*)malloc(sizeof(LNode));
    move=L;
    for(;j<i-1&&move!=NULL;j++)
    {
        move=move->next;
    }
    if(move==NULL)
    {
        return false;
    }
    
    LNode* newNde=(LNode*)malloc(sizeof(LNode));
    newNde->data=e;
    newNde->next=move->next;
    move->next=newNde;
    return true;
}

//在给定节点的后面插入一个节点
bool listNextInsert(LNode* p,int e)
{
    if(p==NULL)
    {
        return false;
    }

    LNode* in=(LNode*)malloc(sizeof(LNode));
    if(in==NULL)
    {
        return false;
    }
    in->data=e;
    in->next=p->next;
    p->next=in;
    return true;
}

//在给定节点的前面插入一个节点
bool listPriorInsert(LNode* p,int e)
{
    if(p==NULL)
    {
        return false;
    }
    LNode* in=(LNode*)malloc(sizeof(LNode));
    if(in==NULL)
    {
        return false;
    }

    // in->next=p->next;
    // p->next=in;
    // in->data=p->data;
    // p->data=e;
    in->data=p->data;
    p->data=e;
    in->next=p->next;
    p->next=in;
    return true;
}


bool DelList(LNList &L,int i,int &del)
{
    if(i<1)
    {
        return false;
    }

    int j=0;
    LNode *move=(LNode*)malloc(sizeof(LNode));
    move=L;
    while(j<i-1&&move!=NULL)
    {
        move=move->next;
        j+=1;
    }
    if(move==NULL)
    {
        return false;
    }
    del=move->next->data;
    move->next=move->next->next;
    return true;
}

//删除给定的节点
bool DelNode(LNode *p)
{
    if(p==NULL)
    {
        return false;
    }

    LNode *q=p->next;
    p->data=q->data;
    p->next=q->next;
    free(q);
    return true;
}

LNode* getElem(LNList L,int i)
{
    if(L==NULL)
    {
        return NULL;
    }
    int j=0;
    for(;j<i&&L!=NULL;j++)
    {
        L=L->next;
    }
    return L;
}

int locateElem(LNList L,int e)
{
    if(L==NULL)
    {
        return 0;
    }
    int j=1;
    while(L!=NULL)
    {
        L=L->next;
        if(L->data==e)
        {
            break;
        }
        j++;
    }
    if(L==NULL)
        return 0;
    else
        return j;
}



void printList(LNList L)
{
    if(L==NULL)
    {
        return;
    }

    LNode* remember=L;
    int i=0;
    L=L->next;
    for(;L!=NULL;i++)
    {
        printf("%d  ",L->data);
        L=L->next;
    }
    L=remember;
    printf("\n");
}

