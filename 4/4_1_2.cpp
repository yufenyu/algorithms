#include <iostream>
using namespace std;

int main()
{
    int A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    for(int i = 0; i < 16; i++)
        cout << A[i] << " ";
    cout << endl;
    int sum;
    int max_low, max_high, max_sum = -22222;
    for(int i = 0; i < 16; i++)
    {
        for(int j = i+1; j < 16; j++)
        {
            sum = 0;
            for(int h = i; h <= j; h++)
            {
                sum += A[h];
            }
            if(max_sum < sum)
            {
                max_sum = sum;
                max_low = i;
                max_high = j;
            }
        }
    }
    for(int i = max_low; i <= max_high; i++)
        cout << A[i] << " ";
    cout << "\n" << "max sum is " << max_sum << endl;
}
