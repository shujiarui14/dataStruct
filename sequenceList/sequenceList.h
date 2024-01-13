
#define MaxSzie 32
#define initSzie 32


typedef struct _sQlist
{
    int data[MaxSzie];
    int length;
}sQlist;

typedef struct _sQlist1
{
    int *data;
    int maxSize;
    int length;
}sQlist1;

void initSqList(sQlist &L);
void initSqList1(sQlist1 &L);
void increaseSzie(sQlist1 &L,int increaseLength);
bool insertList(sQlist &L,int where,int e);
void printList(sQlist L);
bool delList(sQlist &L,int where,int &del);
int getElem(sQlist L,int i);
int locate(sQlist L,int target);
void destroyList(sQlist &L);
bool emptyList(sQlist L);
int getLength(sQlist L);
