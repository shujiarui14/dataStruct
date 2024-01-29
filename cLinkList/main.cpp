#include <stdio.h>
#include <stdlib.h>
#include "./cLinkList.h"


int main()
{
    cLinkList cL;
    int del;
    initCLinkList(cL);
    insertToList(cL,1,1);
    insertToList(cL,2,2);
    insertToList(cL,1,0);
    priorInsert(cL->next,-1);
    printList(cL);
    nextInsert(cL->next->next->next->next,3);
    printList(cL);
    nextInsert(cL->next->next->next,88);
    printList(cL);
    priorInsert(cL->next->next->next->next->next->next,66);
    printList(cL);
    delElemFromList(cL,4,del);
    printf("%d已删除！\n",del);
    printList(cL);
    delNodeFromList(cL->next->next->next->next->next,del);
    printf("%d已删除！\n",del);
    printList(cL);
    printf("循环链表的长度为：%d\n",getLength(cL));
    printf("第4个元素是：%d\n",getElem(cL,4)->data);
    printf("3在第%d号位置上\n",*locateElem(cL,3));
    return 0;
}

bool initCLinkList(cLinkList &cL)
{
    cL=(cLinkNode*)malloc(sizeof(cLinkNode));
    if(cL==NULL)
    {
        return false;
    }
    cL->next=cL;
    return true;
}

bool isEmpty(cLinkList cL)
{
    if(cL->next!=cL)
    {
        return false;
    }
    return true;
}

bool insertToList(cLinkList &cL,int i,int e)
{
    if(cL==NULL)
    {
        return false;
    }

    cLinkNode *move=(cLinkNode*)malloc(sizeof(cLinkNode));
    cLinkNode *newNode=(cLinkNode*)malloc(sizeof(cLinkNode));
    newNode->data=e;
    move=cL;
    int j=0;
    while(j<i-1)
    {
        move=move->next;
        j++;
    }
    if(move->next==cL)
    {
        move->next=newNode;
        newNode->next=cL;
        return true;
    }

    newNode->next=move->next;
    move->next=newNode;
    return true;

}

bool priorInsert(cLinkNode *cN,int e)
{
    if(cN==NULL||cN->next==cN)//我到底如何判断这个节点是尾节点还是头节点呢
    {
        return false;
    }
    cLinkNode *newNode =(cLinkNode*)malloc(sizeof(cLinkNode));
    if(newNode==NULL)
    {
        return false;
    }
    newNode->data=cN->data;
    cN->data=e;
    newNode->next=cN->next;
    cN->next=newNode;
    return true;
}

bool nextInsert(cLinkNode *cN,int e)
{
    if(cN==NULL)
    {
        return false;
    }
    cLinkNode *newNode=(cLinkNode*)malloc(sizeof(cLinkNode));
    newNode->data=e;
    newNode->next=cN->next;
    cN->next=newNode;
    return true;
}

bool delElemFromList(cLinkList &cL,int i,int &del)
{
    if(cL==NULL)
    {
        return false;
    }
    cLinkNode *move=(cLinkNode*)malloc(sizeof(cLinkNode));
    move=cL;
    int j=0;
    for(;j<i-1;j++)
    {
        move=move->next;
    }
    cLinkNode *q=move->next;
    del=q->data;
    move->next=q->next;
    //move->mext=move->next->next;
    free(q);
    return true;
}


bool delNodeFromList(cLinkNode *cN,int &del)
{
    if(cN==NULL)
    {
        return false;
    }
    cLinkNode *remember=cN;
    while(cN->next!=remember)
    {
        cN=cN->next;
    }
    cLinkNode* q=remember;
    del=q->data;
    cN->next=q->next;
    free(q);
    return true;
}

int getLength(cLinkList cL)
{
    int count=0;
    if(cL==NULL)
    {
        return 0;
    }
    cLinkNode *remember=cL;
    while(cL->next!=remember)
    {
        count++;
        cL=cL->next;
    }
    return count;
}

cLinkNode *getElem(cLinkList cL,int i)
{
    if(cL==NULL)
    {
        return NULL;
    }
    cLinkNode *move=cL;
    int j=0;
    for(;j<i;j++)
    {
        move=move->next;
    }
    if(move!=NULL)
    {
        return move;
    }
    return NULL;
}

int *locateElem(cLinkList cL,int target)
{
    if(cL==NULL)
    {
        return NULL;
    }
    int *i=(int*)malloc(sizeof(int));
    *i=0;
    cLinkNode *remember=cL;
    while(cL->next!=remember)
    {
        cL=cL->next;
        *i=*i+1;
        if(cL->data==target)
        {
            return i;
        }
    }
    return NULL;
}

void printList(cLinkList cL)
{
    if(cL==NULL)
    {
        return;
    }
    cLinkNode *remember=cL;
    //printf("1=%p   2=%p  3=%p 4=%p\n",cL,cL->next,cL->next->next,cL->next->next->next);
    while(cL->next!=remember)
    {
        cL=cL->next;
        printf("%d ",cL->data);
    }
    printf("\n");
     
}