#include <stdio.h>

int FindGreatestSumOfSubArray(int *array, int len) {
    if(len == 0) return 0;

    int i, sum[len];
    sum[0] = array[0];
    for(i = 1; i < len; i++) {
        if(sum[i-1] > 0) {
            sum[i] = array[i] + sum[i-1];
        } else {
            sum[i] = array[i];
        }
    }
    return sum[len-1];
}

void main()
{
    int array[8] = {1,-2,3,10,-4,7,2,-5};
    int res = FindGreatestSumOfSubArray(array, 8);
    printf("%d\n", res);
}
