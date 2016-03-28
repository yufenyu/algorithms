#include <stdio.h>
#include <limits.h>

int func_aux(int *F, int n){
    if(F[n] > INT_MIN) return F[n];
    int q;
    if(n == 0) q = 0;
    if(n == 1) q = 1;
    q = func_aux(F, n-1) + func_aux(F, n-2);
    F[n] = q;
    return q;
}
int func(int n)
{
    int i, F[n+1];
    for(i = 0; i <= n; i++)
    {
        F[i] = INT_MIN;
    }
    return func_aux(F, n);
}

void main()
{
    int res = func(5);
    printf("res = %d\n", res);
}
