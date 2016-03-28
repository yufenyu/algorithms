#include <stdio.h>
#include "list.h"
#define N 6
void main()
{
    int Larray[N] = {4, 5, 6, 7, 8, 9}; 
    List L = CreateList(Larray, N);
    int Parray[4] = {6, 4, 3, 1};
    List P = CreateList(Parray, 4);
    int cursor = 1;
    Position posP = P->next;
    Position posL = L->next;

    while(posP != NULL)
    {
        while(cursor < posP->Element)
        {
            posL = posL->next;
            cursor++;
        }
        printf("%d ", posL->Element);
        posP = posP->next;
    }
    printf("\n");


}
