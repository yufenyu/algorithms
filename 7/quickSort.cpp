#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int partition(int A[], int p, int r);
void exchange(int A[], int i, int j);
void quickSort(int A[], int p, int r);
void randomized_partition(int A[], int p, int r);
int main()
{
    int A[8] = {2, 8, 7, 1, 3, 5, 6, 4};
    for(int i = 0; i < 8; i++)
        cout << A[i] << " ";
    cout << endl;
    int q = partition(A, 0, 7);
    cout << q << endl;
    for(int i = 0; i < 8; i++)
        cout << A[i] << " ";
    cout << endl;

    quickSort(A, 0, 7);
    for(int i = 0; i < 8; i++)
        cout << A[i] << " ";
    cout << endl;

}

void quickSort(int A[], int p, int r)
{
    if(p < r)
    {
        //int q = partition(A, p, r);
        int q = randomized_partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int randomized_partition(int A[], int p, int r)
{
    srand((unsigned)time(NULL));
    int i = rand() % 8;
    exchange(A, i, r);
    return partition(A, p, r);
}
int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for(int j = p; j < r; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(A, i, j);
        }
    }
    exchange(A, i + 1, r);
    return i + 1;
}

void exchange(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
