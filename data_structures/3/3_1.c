#include <stdio.h>
#include "list.h"
#define N 5
void main()
{
    int A[N] = {5, 4, 0, 1, 2};
    int i;
    List L = CreateList(A, N);
    Position P = L->next;
    while(P != NULL)
    {
        printf("%d ", P->Element);
        P = P->next;
    }
    printf("\n");    
}
