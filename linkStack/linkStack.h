

typedef struct _linkStack
{
    int data;
    _linkStack *next;
}linkStack,*linkStackList;

bool initLinkStack(linkStackList &s);
bool destroyLinkStack(linkStackList &s);
bool emptyLinkStack(linkStackList s);
bool pushLinkStack(linkStackList &s,int e);
bool popLinkStack(linkStackList &s,int &out);
int* getTop(linkStackList s);

void printLinkStackListData(linkStackList s);
void test(linkStackList s);