

typedef struct _dLinkNode
{
    int data;
    struct _dLinkNode *prior,*next;
}dLinkNode,*dLinkList;


bool initdLinkList(dLinkList &dL);

bool isEmpty(dLinkList dL);

bool priorInsertNewNode(dLinkNode* dN,int e);
bool nextInsertNewNode(dLinkNode* dN,int e);
bool insertToList(dLinkList &dL,int i,int e);

int getLength(dLinkList dL);
dLinkNode *getElem(dLinkList dL,int i);
int* locateElem(dLinkList dL,int target);

bool delNodeOfList(dLinkList &dL,int i,int &del);

void printDList(dLinkList dL);

void test(dLinkList dL);
