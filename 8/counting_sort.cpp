#include <iostream>
using namespace std;
void counting_sort(int A[], int B[], int k);
int main()
{
    int A[12] = {0, 6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2}; 
    for(int i = 1; i < 12; i++)
        cout << A[i] << " ";
    cout << endl;
    int *B = new int[12];
    
    counting_sort(A, B, 6);
    
    for(int i = 1; i < 12; i++)
        cout << B[i] << " ";
    cout << endl;

}

void counting_sort(int A[], int B[], int k)
{
    int *C = new int[k+1];
    for(int i = 1; i <= k; i++)
        C[i] = 0;
    for(int i = 1; i < 12; i++)
        C[A[i]] += 1;
    for(int i = 1; i <= k; i++)
        C[i] += C[i-1];
    for(int i = 11; i >= 1; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]] -= 1;
    }
}
