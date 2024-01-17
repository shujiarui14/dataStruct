
typedef struct _LNode
{
    int data;
    struct _LNode* next;
}LNode,*LNList;


void initLNodeList0(LNList &L);
bool initLNodeLIst(LNList &L);

bool listEmpty(LNList L);

int getLength(LNList L);

bool listInsert0(LNList &L,int i,int e);
bool listInsert(LNList &L,int i,int e);
bool listNextInsert(LNode* p,int e);
bool listPriorInsert(LNode* p,int e);

bool DelList(LNList &L,int i,int &del);
bool DelNode(LNode *p);

LNode* getElem(LNList L,int i);
int locateElem(LNList L,int e);

void printList(LNList L);
