#include <stdio.h>
#include <stdlib.h>
#include "list.h"
List CreateList(int A[], int len)
{
    List L;
    L = malloc(sizeof(struct Node));
    if(L == NULL)
    {
        printf("ERROR");
        return NULL;
    }
    else
    {
        int i;
        L->Element = 2222;
        L->next = NULL;
        for(i = 0; i < len; i++)
            Insert(A[i], L, L);
        return L;
    }
    
}


int IsEmpty(List L)
{
    return L->next == NULL;
}

int IsLast(Position P, List L)
{
    return P->next == NULL;
}

Position Find(ElementType X, List L)
{
    Position P = L->next;
    while(P != NULL && P->Element != X)
    {
        P = P->next;
    }
    return P;
}

Position FindPrevious(ElementType X, List L)
{
    Position P = L;
    while(P->next != NULL && P->next->Element != X)
        P = P->next;
    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if(!IsLast(P, L))
    {
        TmpCell = P->next;
        P->next = TmpCell->next;
        free(TmpCell);
    }
}

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("error");
    TmpCell->Element = X;
    TmpCell->next = P->next;
    P->next = TmpCell;
}

Position Next(Position P, List L)
{
    return P->next;
}

void Print(List L)
{
    Position P = L->next;
    while(P != NULL)
    {
        printf("%d ", P->Element);
        P = P->next;
    }
    printf("\n");
}

























