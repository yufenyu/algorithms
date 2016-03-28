#include <iostream>
using namespace std;

int binary(int A[], int low, int high, int value);
int main()
{
    int A[8] = {3, 4, 6, 8, 9, 11, 12, 15};
    int result = binary(A, 0, 7, 11);
    cout << "11 in A is " << result << endl;
    int low = 0, high = 7, mid;
    int value = 15;
    result = -1;
    while(low <= high)//??
    {
        mid = (low + high) / 2;
        if(A[mid] == value)
        {
            result = mid;
            break;
        }
        else if (A[mid] > value)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << "15 in A is " << result << endl;
}

int binary(int A[], int low, int high, int value)
{
    if(low <= high)
    {
        int mid = (low + high) / 2;
        if(A[mid] == value)
            return mid;
        else if(A[mid] > value)
            binary(A, low,  mid - 1, value);
        else if(A[mid] < value)
            binary(A, mid + 1, high, value);
        else 
            return -1;
    }

   
}
