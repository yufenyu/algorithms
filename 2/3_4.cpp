#include <iostream>
using namespace std;
void insert(int A[], int p);
void recursion_sort(int A[], int p);

int main()
{
    int A[8] = {3, 41, 52, 26, 38, 57, 9, 49};
    for(int i = 0; i < 8; i++)
        cout << A[i] << " ";
    cout << endl;
    
    recursion_sort(A, 8);
    for(int i = 0; i < 8; i++)
        cout << A[i] << " ";
    cout << endl;
}

void recursion_sort(int A[], int p)
{
    if(p > 0)
    {
        recursion_sort(A, p - 1);
        insert(A, p);
    }
}
void insert(int A[], int n)
{
    int key = A[n];
    int i = n - 1;
    while(i >= 0 && A[i] > key)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = key;
}
