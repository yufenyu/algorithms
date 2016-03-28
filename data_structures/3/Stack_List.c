#include "stack.h"
int IsEmpty(Stack S)
{
    return S->next == NULL;
}

Stack CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct Node));
    if(S == NULL)
        printf("error");
    S->next = NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S)
{
    if(S == NULL)
        printf("error");
    else
    {
        while(!IsEmpty(S))
            Pop(S);
    }
}

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("error");
    else
    {
        TmpCell->Element = X;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->next->Element;
    printf("error");
    return 0;
}

void Pop(Stack S)
{
    PtrToNode TmpCell;
    if(IsEmpty(S))
        printf("ERROR");
    else
    {
        TmpCell = S->next;
        S->next = TmpCell->next;
        free(TmpCell);
    }
}
