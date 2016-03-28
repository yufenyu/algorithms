#include <iostream>

using namespace std;

void choose_sort(int A[]);
void choose_sort2(int A[]);

int main()
{
    int A[7] = {1, 2, 4, 11, 6, 3, 0};
//    choose_sort(A);
    for(int i = 0; i < 7; i++)
        cout << A[i] << " ";
    cout << endl;

    choose_sort2(A);
    
    for(int i = 0; i < 7; i++)
        cout << A[i] << " ";
    cout << endl;
}

void choose_sort(int A[])
{
    int min;
    int m, i, j;
    for(i = 0; i < 6; i++)
    {
        min = A[i];
        for(j = i + 1; j < 7; j++)
        {
            if(A[j] < min)
            {
                min = A[j];
                m = j;
            }
        }
        int temp = A[i];
        A[i] = A[m];
        A[m] = temp;
    }
}

int min(int l, int h, int A[])
{
    int m = l;
    for(int i = l; i < h; i++)
    {
        if(A[i] < A[m])
            m = i;
    }
    return m;
}
void exchange(int i, int j, int A[])
{
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
void choose_sort2(int A[])
{
    for(int i = 0; i < 7; i++)
    {
        int j = min(i, 7, A);
        exchange(i, j, A);
    }

}
