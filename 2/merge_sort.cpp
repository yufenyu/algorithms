#include <iostream>
using namespace std;
const int N = 8;
void merge(int A[], int p, int q, int r);
void merge_sort(int A[], int p, int r);
int main()
{
    int A[N] = {2, 4, 5, 7, 1, 2, 3, 6};
    merge_sort(A, 0, N - 1);
    for(int k = 0; k < N; k++)
        cout << A[k] << " ";
    cout << endl;
}
void merge_sort(int A[], int p, int r)
{
    if(p < r)
    {
        int q = (r + p) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}
void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;//cout << "n1 = " << n1 << endl;
    int n2 = r - q;//cout << "n2 = " << n2 << endl;
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];
    for(int i = 0; i < n1; i++)
        L[i] = A[i + p];
    L[n1] = 22222;
    
    for(int i = 0; i < n2; i++)
        R[i] = A[q + 1 + i];
    R[n2] = 22222;

    int i = 0, j = 0;
    for(int k = p; k <= r; k++)
    {
        if(L[i] < R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}
/*
int main()
{
    int A[N] = {2, 4, 5, 7, 1, 2, 3, 6};
    //merge(A, );
    int *L = new int[4];
    int *R = new int[4];
    for(int i = 0; i < 4; i++)
    {
        L[i] = A[i];
        R[i] = A[4+i];
    }
    int i = 0, j = 0, k = 0;
    while(i < 4 && j < 4)
    {
        if(L[i] < R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while(i < 4)
    {
        A[k++] = L[i++];
    }
    while(j < 4)
    {
        A[k++] = R[j++];
    }
    for(int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
}
*/
