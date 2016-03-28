#include <iostream>
using namespace std;
void merge_sort(int A[], int p, int r);
void merge(int A[], int p, int q, int r);

int main()
{
    int A[8] = {3, 41, 52, 26, 38, 57, 9, 49};

    merge_sort(A, 0, 7);
    for(int i = 0; i < 8; i++)
        cout << A[i] << " ";
    cout << endl;
}

void merge_sort(int A[], int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = new int[n1];
    int *R = new int[n2];
    for(int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for(int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];
    int k = p, i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(L[i] < R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while(i < n1)
        A[k++] = L[i++];
    while(j < n2)
        A[k++] = R[j++];
    delete [] L;
    delete [] R;
}

