#define maxSize 255

typedef struct _SqStack
{
    int data[maxSize];
    int top;
}SqStack,*SqStackList;

bool initStack(SqStackList &s);
void destroyStack(SqStackList &s);
bool emptyStack(SqStackList s);
bool pushStack(SqStackList &s,int e);
bool popStack(SqStackList &s,int &out);
int* getTop(SqStackList s);

void printStackData(SqStackList s);

void test(SqStackList s);
