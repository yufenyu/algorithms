#include <stdio.h>
#include <malloc.h>
#define N 5
typedef struct node
{
    int data;
    struct node * next;
}listNode;
listNode *Creat(void);
void insert(listNode *, int);

void main()
{
    int i, data;
    listNode *head, *p;
    head = Creat();
    int A[N] = {1, 3, 5, 2, 4};
    printf("please input 5 element of the list: \n");
    for(i = 0; i < N; i++)
    {
//        scanf("%d", &data);
        data = A[i];
        insert(head, data);
    }
    
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

}

listNode *Creat()
{
    listNode *p;
    p = (listNode *)malloc(sizeof(listNode));
    p->next = NULL;
    return p;
}

void insert(listNode *head, int d)
{
    listNode *p;
    p = (listNode *)malloc(sizeof(listNode));
    p->next = NULL;
    p->data = d;
    if(head->next == NULL)
        head->next = p;
    else 
    {
        p->next = head->next;
        head->next = p;
    }
}
