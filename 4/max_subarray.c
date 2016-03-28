#include <stdio.h>
#define N 16
/*
struct result
{
    int max_low;
    int max_high;
    int max_sum;
}r, left, right, cross;

struct result find_max_cross_subarray(int low, int high, int A[]);
struct result find_max_subarray(int low, int high, int A[]);

void main()
{
    int A[N] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};    
    r = find_max_subarray(0, N - 1, A);
    int i;
    for(i = r.max_low; i < r.max_high; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\nmax_sum is %d\n", r.max_sum);

printf("yes\n");
}

struct result find_max_cross_subarray(int low, int high, int A[])
{
    struct result c;
    int mid = (low + high) / 2;
    int i, j;
    
    int left_max = -1111111;
    int sum = 0;
    for(i = mid; i >= 0; i--)
    {
        sum += A[i];
        if(sum > left_max)
        {
            left_max = sum;
            c.max_low = i;
        }
    }

    int right_max = -1111111;
    sum = 0;
    for(j = mid + 1; j < N; j++)
    {
        sum += A[j];
        if(sum > right_max)
        {
            right_max = sum;
            c.max_high = j;
        }
    }
    c.max_sum = right_max + left_max;
    return c;
}

struct result find_max_subarray(int low, int high, int A[])
{
    int mid = (low + high) / 2;
    left = find_max_subarray(low, mid, A);
    cross = find_max_cross_subarray(low, high, A);
    right = find_max_subarray(mid + 1, high, A);

    if((left.max_sum > cross.max_sum) && (left.max_sum > right.max_sum))
        return left;
    else if((right.max_sum > cross.max_sum) && (right.max_sum > left.max_sum))
        return right;
    else
        return cross;
}
*/
