#include <iostream>
using namespace std;

int main()
{
    int A[4] = {1, 0, 1, 0};
    int B[4] = {0, 1, 1, 0};
    int C[5];
    int j = 4;
    for(int i = 3; i >= 0; i++)
    {
        C[j--] = (A[i] + B[i] + (A[i-1] + B[i-1]) / 2) % 2;
    }
    for(int i = 0; i <= 4; i++)
        cout << A[i] << " ";

    cout << endl;
}
