#include <stdio.h>
#include <stdlib.h>
#include "./dLinkList.h"

int main()
{
    dLinkList dL;
    test(dL);
    return 0;
}






void test(dLinkList dL)
{
    initdLinkList(dL);
    nextInsertNewNode(dL,99);
    printDList(dL);
    insertToList(dL,2,88);
    printDList(dL);
    insertToList(dL,1,77);
    printDList(dL);
    priorInsertNewNode(dL->next->next,66);
    printDList(dL);
    int del=0;
    delNodeOfList(dL,3,del);
    printf("删除的是：%d\n",del);
    printDList(dL);
    printf("当前双链表的长度为：%d\n",getLength(dL));
    printf("第3个元素是：%d\n",getElem(dL,3)->data);
    priorInsertNewNode(dL->next->next,55);
    printDList(dL);
    nextInsertNewNode(dL->next->next,44);
    printDList(dL);
    printf("66的位置在：%d\n",*locateElem(dL,66));
}

bool initdLinkList(dLinkList &dL)
{
    dL=(dLinkNode*)malloc(sizeof(dLinkNode));
    if(dL==NULL)
    {
        return false;
    }
    dL->next=dL->prior=NULL;
    return true;
}

bool isEmpty(dLinkList dL)
{
    if(dL->next==NULL)
    {
        return true;
    }
    return false;
}

bool priorInsertNewNode(dLinkNode* dN,int e)
{
    if(dN==NULL)
    {
        return NULL;
    }
    dLinkNode *p=(dLinkNode*)malloc(sizeof(dLinkNode));
    p->data=e;
    p->prior=p->next=NULL;

    p->next=dN;
    if(dN->prior!=NULL)
    {
        dN->prior->next=p;
    }
    p->prior=dN->prior;
    dN->prior=p;

    return true;
}

bool nextInsertNewNode(dLinkList dN,int e)
{
    if(dN==NULL)
    {
        return false;
    }
    dLinkNode *p=(dLinkNode*)malloc(sizeof(dLinkNode));
    p->data=e;
    p->prior=p->next=NULL;

    p->next=dN->next;
    if(dN->next!=NULL)
    {
        dN->next->prior=p;
    }
    p->prior=dN;
    dN->next=p;
    return true;
}

bool insertToList(dLinkList &dL,int i,int e)
{
    if(dL==NULL)
    {
        return false;
    }
    dLinkNode *move=(dLinkNode*)malloc(sizeof(dLinkNode));
    move=dL;
    int j=0;
    for(;j<i-1;j+=1)
    {
        move=move->next;
    }

    dLinkNode *newNode=(dLinkNode*)malloc(sizeof(dLinkNode));
    if(newNode==NULL)
    {
        return false;
    }
    newNode->data=e;
    newNode->next=move->next;
    if(move->next!=NULL)
    {
        move->next->prior=newNode;
    }
    newNode->prior=move;
    move->next=newNode;
    return true;
}

int getLength(dLinkList dL)
{
    int i=0;
    dL=dL->next;
    while(dL!=NULL)
    {
        dL=dL->next;
        i++;
    }
    return i;
}

dLinkNode* getElem(dLinkList dL,int i)
{
    if(dL==NULL||i<1||i>getLength(dL))
    {
        return NULL;
    }

    dLinkNode *move=dL;
    int j=1;
    for(;j<i+1;j++)
    {
        move=move->next;
    }

    if(move!=NULL)
    {
        return move;
    }
    return NULL;

}

int* locateElem(dLinkList dL,int target)
{
   
    if(dL==NULL)
    {
        return NULL;
    }
    int* i=(int*)malloc(sizeof(int));
    *i=1;
    dL=dL->next;
    while(dL!=NULL)
    {
        if(dL->data==target)
        {
           return i;
        }
        dL=dL->next;

        *i=*i+1;
    }
    return NULL;

}

bool delNodeOfList(dLinkList &dL,int i,int &del)
{
    if(dL==NULL)
    {
        return false;
    }
    //printf("length=%d  i=%d \n",getLength(dL),i);
    if(i<1 || i>getLength(dL))
    {
        printf("hello\n");
        return false;
    }

    dLinkNode *move=(dLinkNode*)malloc(sizeof(dLinkNode));
    move=dL;
    int j=0;
    for(;j<i-1;j+=1)
    {
        move=move->next;
    }
    dLinkNode *tmp=move->next;
    del=tmp->data;
    move->next=tmp->next;
    tmp->next->prior=move;
    return true;
}

void printDList(dLinkList dL)
{
    dL=dL->next;
    while(dL!=NULL)
    {
        printf("%d  ",dL->data);
        dL=dL->next;
    }
    printf("\n");
}

