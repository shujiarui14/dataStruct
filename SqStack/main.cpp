#include <stdio.h>
#include <stdlib.h>
#include "./SqStack.h"



int main()
{
    SqStackList s;
    test(s);
    return 0;
}


bool initStack(SqStackList &s)
{
    s=(SqStackList)malloc(sizeof(SqStack));
    if(s==NULL)
    {
        return false;
    }
    s->top=-1;
    return true;
}

void destroyStack(SqStackList &s)
{
    free(s);
}

bool emptyStack(SqStackList s)
{
    if(s->top==-1)
    {
        return true;
    }
    return false;
}

bool pushStack(SqStackList &s,int e)
{
    s->top+=1;
    if(s->top>=maxSize)
    {
        return false;
    }
    s->data[s->top]=e;
    return true;
}

bool popStack(SqStackList &s,int &out)
{
    if(s->top==-1)
    {
        return false;
    }
    out=s->data[s->top];
    s->top-=1;
    return true;
}


int* getTop(SqStackList s)
{
    if(s->top==-1)
    {
        return NULL;
    }
    int *target=(int*)malloc(4);
    *target=s->data[s->top];
    return target;
}

void printStackData(SqStackList s)
{
    int i=s->top;
    printf("从栈顶到栈底的元素依次为：");
    for(;i>-1;i--)
    {
        printf("%d  ",s->data[i]);
    }
    printf("\n");
}

void test(SqStackList s)
{
    initStack(s);
    int i=0;
    for(;i<10;i++)
    {
        pushStack(s,i+1);
    }
    printStackData(s);
    int tmp=0;
    popStack(s,tmp);
    printf("出栈元素是%d：\n",tmp);
    printStackData(s);
    printf("此时栈顶元素为：%d\n",*getTop(s));
}