#include <iostream>
using namespace std;
const int N = 16;
struct Result
{
    int low;
    int high;
    int sum;
};

Result find_max_crossing_subarray(int A[], int low, int mid, int high);
Result find_maximun_subarray(int A[], int low, int high);
int main()
{
    int A[N] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    for(int i = 0; i < 16; i++)
        cout << A[i] << " ";
    cout << endl;

    Result r = find_maximun_subarray(A, 0, 15);
    
    
    for(int i = r.low; i <= r.high; i++)
        cout << A[i] << " ";
    cout << endl;
}


Result find_maximun_subarray(int A[], int low, int high)
{
    Result max;
    if(low == high)
    {   
        max.low = low;
        max.high = high;
        max.sum = A[low];
        return max;
    }
    else
    {

        int mid = (low + high) / 2;
        Result left = find_maximun_subarray(A, low, mid);
        Result right = find_maximun_subarray(A, mid+1, high);
        Result cross = find_max_crossing_subarray(A, low, mid, high);
        if(max.sum < right.sum)
            max = right;
        if(max.sum < cross.sum)
            max = cross;
        return max;
    }
}

Result find_max_crossing_subarray(int A[], int low, int mid, int high)
{
    Result r;
    int left_sum = -22222;
    int left_max;
    int sum = 0;
    for(int i = mid; i >= low; i--)
    {
        sum = sum + A[i];
        if(sum > left_sum)
        {
            left_max = i;
            left_sum = sum;
        }
    }
    int right_sum = -22222;
    int right_max;
    sum = 0;
    for(int i = mid + 1; i <= high; i++)
    {
        sum = sum + A[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            right_max = i;
        }
    }

    r.sum = left_sum + right_sum;
    r.low = left_max;
    r.high = right_max;
    return r;


}

