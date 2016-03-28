#include <iostream>
using namespace std;
const int N = 8;
int Minimum(int A[]);
void Min_Max(int A[]);
int main()
{
    int A[8] = {2, 8, 7, 1, 3, 5, 6, 4};
    for(int i = 0; i < 8; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "min = " << Minimum(A) << endl;
    Min_Max(A);
}

int Minimum(int A[])
{
    int min = A[0];
    for(int i = 0; i < 8; i++)
        if(A[i] < min)
            min = A[i];
    return min;
}

void Min_Max(int A[])
{
    int i = 0;
    int min, max;
    //初始化min和max，并且统一后面的算法
    if(N % 2 == 0)
    {
        if(A[i] > A[i+1])
        {
            min = A[i+1];
            max = A[i];
        }
        else
        {
            min = A[i];
            max = A[i+1];
        }
        i += 2;
    }
    else
    {
        min = A[i];
        max = A[i];
        i += 1;
    }
    while(i < N)
    {
        if(A[i] > A[i+1])
        {
            if(min > A[i+1])
                min = A[i+1];
            if(max < A[i])
                max = A[i];
        }
        else
        {
            if(min > A[i])
                min = A[i];
            if(max < A[i+1])
                max = A[i+1];
        }
        i += 2;
    }
    cout << "min = " << min << endl;
    cout << "max = " << max << endl;

}
