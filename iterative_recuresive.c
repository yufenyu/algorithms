#include <stdio.h>

int iterative(int n);
int recuresive(int n);

void main()
{
    printf("please input a number: \n");
    int n;
    scanf("%d", &n);
    int result;
    result = iterative(n);
    printf("n! use by iterative is: %d\n", result);
    result = recuresive(n);
    printf("n! use by recuresive is: %d\n", result);
}

int iterative(int n)
{   
    int r = 1;
    while(n != 1)
    {
        r = r * n;
        n--;
    }
    return r;
}

int recuresive(int n)
{
    if(n == 1)
        return 1;
    return n * recuresive(n - 1);
}
