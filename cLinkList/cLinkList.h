

typedef struct _cLinkNode
{
    int data;
    _cLinkNode *next;
}cLinkNode,*cLinkList;


bool initCLinkList(cLinkList &cL);

bool isEmpty(cLinkList cL);

bool insertToList(cLinkList &cL,int i,int e);
bool priorInsert(cLinkNode *cN,int e);
bool nextInsert(cLinkNode *cN,int e);

bool delElemFromList(cLinkList &cL,int i,int &del);
bool delNodeFromList(cLinkNode *cN,int &del);

int getLength(cLinkList cL);

cLinkNode *getElem(cLinkList cL,int i);
int *locateElem(cLinkList cL,int target);



void printList(cLinkList cL);

