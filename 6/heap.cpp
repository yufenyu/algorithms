#include <iostream>
using namespace std;

void max_heapify(int A[], int i);
void build_max_heap(int A[]);
void heapSort(int A[]);
void exchange(int A[], int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}
int parent(int i)
{
    return i / 2;
}

int left(int i)
{
    return 2 * i;
}

int right(int i)
{
    return 2 * i + 1;
}
int main()
{

//    int A[11] = {0, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
//    max_heapify(A, 2);
    int A[11] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    for(int i = 1; i < 11; i++)
        cout << A[i] << " ";
    cout << endl;
    /*
    build_max_heap(A);
    
    for(int i = 1; i < 11; i++)
        cout << A[i] << " ";
    cout << endl;
    */
    heapSort(A);
}

void heapSort(int A[])
{
    build_max_heap(A);
    for(int i = 10; i >= 1; i--)
    {
        cout << A[1] << endl;
        A[1] = 0;
        exchange(A, 1, i);
        max_heapify(A, 1);
    }
}
void build_max_heap(int A[])
{
    for(int i = 5; i >=1; i--)
    {
        max_heapify(A, i);
    }
}

void max_heapify(int A[], int i)
{
    int l = left(i);
    int r = right(i);
    int largest;
    if(l < 11 && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if(r < 11 && A[r] > A[largest])
        largest = r;

    if(largest != i)
    {
        exchange(A, largest, i);
        max_heapify(A, largest);
    }

        
}
