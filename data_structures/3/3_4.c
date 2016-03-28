#include <stdio.h>
#include "list.h"
#define N 6
#define M 4
void main()
{
    int Larray[N] = {9, 8, 7, 6, 4, 3}; 
    List L = CreateList(Larray, N);
    int Parray[4] = {6, 4, 3, 1};
    List P = CreateList(Parray, 4);
    
    Print(L);

    Print(P);
    Position Result = L;
    Position posR = L;
    Position posL = L->next;
    Position posP = P->next;

    while(posL != NULL && posP != NULL)
    {
        if(posL->Element < posP->Element)
        {
            posR->next = posL;
            posL = posL->next;
        }
        else if(posL->Element > posP->Element)
        {
            posR->next = posP;
            posP = posP->next;
        }
        else
        {
            posR->next = posL;
            posL = posL->next;
            posP = posP->next;
        }
    }
    if(posL == NULL)
        posR->next = posP;
    if(posP == NULL)
        posR->next = posL;
    
    Print(Result);
    printf("\n");
}
