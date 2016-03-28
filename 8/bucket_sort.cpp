//未调试出来

#include <iostream>
using namespace std;
const int N = 10;
struct Node
{
    double data;
    Node * next;
};
void Insert(Node *L, Node *node)
{
    if(L == NULL)
        L = node;
    else
    {
        node->next = L->next;
        L->next = node;
    }
}


void Sort(Node *L)
{
    if(L != NULL)
    {
        Node *P = L->next;
        //findPrevious P to delete
        Node *Pre = L;
        while(P != NULL)
        {
            Node *Q = L;
            while(Q->next->data < P->data)
                Q = Q->next;
            if(Q == Pre)
            {
                Pre = P;
                P = P->next;
            }
            else
            {
                Pre->next = P->next;
                P->next = Q->next;
                Q->next = P;
                P = Pre->next;
            }
        }
    }
}
void bucket_sort(double A[]);
int main()
{
    double A[N] = {0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
    for(int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
    bucket_sort(A);
}
void bucket_sort(double A[])
{
    Node *B[N];
    for(int i = 0; i < N; i++)
        B[i] = NULL;
    for(int i = 0; i < N; i++)
    {
        int cursor = A[i] * 100 / 10;
        Node *node = new Node;
        node->data = A[i];
        node->next = NULL;
        Insert(B[cursor], node);
    }
    cout << B[1]->data << " " << B[1]->next->data << endl;
    for(int i = 0; i < N; i++)
        Sort(B[i]);
    for(int i = 0; i< N; i++)
    {
        Node *P = B[i];
        while(P != NULL)
        {
            cout << P->data << " ";
            P = P->next;
        }
    }
}
