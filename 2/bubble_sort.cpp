#include <iostream>
using namespace std;
void bubbleSort(int A[]);
void exchange(int i, int j, int A[]);
int main()
{
    int A[8] = {3, 41, 52, 26, 38, 57, 9, 49};
    for(int i = 0; i < 8; i++)
        cout << A[i] << " ";
    cout << endl;
    bubbleSort(A);
    for(int i = 0; i < 8; i++)
        cout << A[i] << " ";
    cout << endl;
}

void bubbleSort(int A[])
{
    for(int i = 1; i < 8; i++)
    {
        for(int j = 7; j >= i + 1; j--)
        {
            if(A[j] < A[j-1])
                exchange(j, j-1, A);
        }
    }
}

void exchange(int i, int j, int A[])
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
