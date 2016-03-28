#include <iostream>
using namespace std;
#define N 6
void insert_sort(int A[]);
void insert_sort_descend(int A[]);
int find_key(int v, int A[]);

int main()
{
    int A[6] = {5, 2, 7, 6, 1, 3};
    for(int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
    int result = find_key(5, A);
    cout << "key 5 in A is" << result << endl;
    insert_sort(A);
    for(int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
    insert_sort_descend(A);
    for(int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
}

int find_key(int v, int A[])
{
    for(int i = 0; i < N; i++)
        if(A[i] == v) return (i+1);
    else return -1;
}
void insert_sort_descend(int A[])
{
    int i;
    int key;
    for(int j = 1; j < N; j++)
    {
        key = A[j];
        i = j - 1;
        while(A[i] < key && i >= 0)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}
void insert_sort(int A[])
{
    int i;
    int key;
    for(int j = 1; j < N; j++)
    {
        key = A[j];
        i = j - 1;
        while(i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }

}
