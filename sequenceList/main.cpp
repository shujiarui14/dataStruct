#include <stdio.h>
#include <stdlib.h>
#include "./sequenceList.h"

void test(sQlist &L)
{
    int i=0;
    for(;i<10;i++)
    {
        L.data[i]=i+1;
    }
    L.length=10;
}
int main()
{
    printf("hello\n");
    sQlist L;
    test(L);

    printList(L);
    insertList(L,8,99);
    printList(L);
    int del;
    delList(L,8,del);
    printList(L);
    insertList(L,1,88);
    printList(L);
    insertList(L,12,66);
    printList(L);
    insertList(L,13,55);
    printList(L);
    printf("第1号位置的元素是：%d\n",getElem(L,1));
    printf("元素9的位置在：第%d位\n",locate(L,9));
    return 0;
}


void initSqList(sQlist &L)
{
    int i=0;
    for(;i<MaxSzie;i+=1)
    {
        L.data[i]=0;
        //给每个数据都赋值为0
        //防止脏数据造成误会
    }
    L.length=0;
}
//那么对于这个表来说只能存放32个数据（但记住位序从1开始的）
//如果想要增加表的长度是不可能的


void initSqList1(sQlist1 &L)
{
    L.data=(int*)malloc(sizeof(int)*initSzie);
    L.maxSize=initSzie;
    L.length=0;
}

void increaseSzie(sQlist1 &L,int increaseLength)
{
    int *remember=L.data;
    L.data=(int*)malloc(sizeof(int)*(L.maxSize+increaseLength));
    int i=0;
    for(;i<L.length;i+=1)
    {
        L.data[i]=remember[i];
    }
    L.maxSize=L.maxSize+increaseLength;
    free(remember);
}
//动态分配的特点
//1、水机访问，能在时间复杂度O(1)的时间内找到第i个元素
//2、存储密度高
//3、拓展容量不方便
//4、插入删除元素不方便

bool insertList(sQlist &L,int where,int e)
{
    if(where<1||where>L.length+1)
    {
        return false;
    }
    if(L.length==MaxSzie)
    {
        return false;
    }
    int i=L.length;
    for(;i>=where;i--)
    {
        L.data[i]=L.data[i-1];
    }
    L.data[where-1]=e;
    L.length++;
    return true;
}

void printList(sQlist L)
{
    int i=0;
    for(;i<L.length;i++)
    {
        printf("%d  ",L.data[i]);
    }
    printf("\n");
}

bool delList(sQlist &L,int where,int &del)
{
    if(where<0||where>L.length)
    {
        return false;
    }
    del=L.data[where-1];
    for(;where<L.length;where++)
    {
        L.data[where-1]=L.data[where];
    }
    L.length--;
    return true;
}

int getElem(sQlist L,int i)
{
    if(i<0||i>L.length)
    {
        return -1;
    }
    return L.data[i-1];
}

int locate(sQlist L,int target)
{
    int i=0;
    for(;i<L.length;i++)
    {
        if(L.data[i]==target)
        {
            return i+1;
        }
    }
    return 0;
}

void destroyList(sQlist &L)
{
    free(L);
}

bool emptyList(sQlist L)
{
    if(L.length==0)
    {
        return true;
    }
    return false;
}

int getLength(sQlist L)
{
    return L.length;
}

