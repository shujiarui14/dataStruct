#include <stdio.h>
#include <stdlib.h>
#include "./linkStack.h"


int main()
{
    linkStackList ls;
    test(ls);
    return 0;
}

bool initLinkStack(linkStackList &s)
{
    s=(linkStackList)malloc(sizeof(linkStack));
    if(s==NULL)
    {
        return false;
    }
    s->next=NULL;
    return true;
}

bool destroyLinkStack(linkStackList &s)
{
    linkStack *pre=s;
    while(s->next!=NULL)
    {
        s=s->next;
        free(pre);
        pre=s;
    }
    free(s);
    return true;
}

bool emptyLinkStack(linkStackList s)
{
    if(s->next==NULL)
    {
        return true;
    }
    return false;
}

bool pushLinkStack(linkStackList &s,int e)
{
    if(s==NULL)
    {
        return false;
    }

    linkStack* newElem=(linkStack*)malloc(sizeof(linkStack));
    if(newElem==NULL)
    {
        return false;
    }
    newElem->data=e;
    newElem->next=s->next;
    s->next=newElem;
    return true;
}

bool popLinkStack(linkStackList &s,int &out)
{
    if(s==NULL)
    {
        return false;
    }
    out=s->next->data;
    linkStack *tmp=s;
    s=s->next;
    free(tmp);
    return true;
}

int* getTop(linkStackList s)
{
    if(s==NULL)
    {
        return NULL;
    }
    int* p=(int*)malloc(sizeof(int));
    s=s->next;
    *p=s->data;
    return p;
}

void printLinkStackListData(linkStackList s)
{
    s=s->next;
    if(s==NULL)
    {
        return;
    }
    while(s!=NULL)
    {
        printf("%d  ",s->data);
        s=s->next;
    }
    printf("\n");
}

void test(linkStackList s)
{
    initLinkStack(s);
    int i=0;
    for(;i<10;i+=1)
    {
        pushLinkStack(s,i+1);
    }
    printLinkStackListData(s);
    int del=0;
    popLinkStack(s,del);
    printf("出栈的元素为：%d\n",del);
    printLinkStackListData(s);
    popLinkStack(s,del);
    printf("出栈的元素为：%d\n",del);
    pushLinkStack(s,88);
    printLinkStackListData(s);
    printf("此时栈顶元素为：%d\n",*getTop(s));
    popLinkStack(s,del);
    printf("出栈的元素为：%d\n",del);
    printLinkStackListData(s);
    if(emptyLinkStack(s))
    {
        printf("此时栈空！\n");
    }
    else
    {
        printf("此时栈不空！\n");
    }
    for(i=0;i<8;i+=1)
    {
        popLinkStack(s,del);
    }
    if(emptyLinkStack(s))
    {
        printf("此时栈空！\n");
    }
    else
    {
        printf("此时栈不空！\n");
    }
    pushLinkStack(s,99);
    if(emptyLinkStack(s))
    {
        printf("此时栈空！\n");
    }
    else
    {
        printf("此时栈不空！\n");
    }
    printLinkStackListData(s);
}