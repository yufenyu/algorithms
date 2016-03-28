#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int randomized_select(int A[], int p, int r, int k);
int randomized_quickSort(int A[], int p, int r);
int quickSort(int A[], int p, int r);
void exchange(int A[], int p ,int r);
int main()
{
    int A[8] = {2, 8, 7, 1, 3, 5, 6, 4};
    for(int i = 0; i < 8; i++)
        cout << A[i] << " ";
    cout << endl;
    int k;
    cout << "input k little number " << endl;
    int result = randomized_select(A, 0, 7, k);
    cout << "k number is " << result << endl;
}

int randomized_select(int A[], int p, int r, int k)
{
    if(p == r)
        return A[p];
    int q = randomized_quickSort(A, p, r);
    int h = q - p + 1;
    if(h == k)
        return A[q];
    if(k < h)
        randomized_select(A, p, q-1, k);
    else
        randomized_select(A, q+1, r, k);
}

int randomized_quickSort(int A[], int p, int r)
{
    int i = rand() % 8;
    exchange(A, i, r);
    return quickSort(A, p, r);
}

int quickSort(int A[], int p, int r)
{
    int i = p -1;
    int key;
    for(int j = p; j < r; j++)
    {
        if(A[j] <= key)
        {
            i++;
            exchange(A, i, j);
        }
    }
    exchange(A, i+1, r);
    return i+1;
}
void exchange(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
