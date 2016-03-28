#include <stdio.h>
#include <limits.h>
int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int max(int a, int b)
{
    return a > b ? a : b;
}
int cut_rod(int *p, int n)
{
    if(n == 0)
        return 0;
    int q = INT_MIN;
    int i;
    for(i = 1; i <= n; i++){
        q = max(q, p[i]+cut_rod(p, n-i));
    }
    return q;

}
int memoized_cut_rod(int *p, int n)
{
    int i, r[n+1];
    for(i = 0; i <= n; i++)
    {
        r[i] = INT_MIN;
    }
    return memoized_cut_rod_rux(p, r, n);
}

int memoized_cut_rod_rux(int *p, int *r, int n)
{
    int q, i;
    if(r[n] > INT_MIN) return r[n];
    if(n == 0) q = 0;
    else {
        q = INT_MIN;
        for(i = 1; i <= n; i++) {
            q = max(q, p[i]+memoized_cut_rod_rux(p, r, n-i));
        }
        r[n] = q;
    }
    return q;
    
}

int bottom_up_cut_rod(int *p, int n)
{
    int i, j, r[n+1], q;
    r[0] = 0;
    for(i = 1; i <= n; i++) {
        q = INT_MIN;
        for(j = 1; j <= i; j++) {
            q = max(q, p[j]+r[i-j]);
        }
        r[i] = q;
    }
    return r[n];
}


int extended_bottom_up_cut_rod(int *p, int n)
{
    int i, j, q;
    int r[n+1], s[n+1];
    r[0] = 0;
    s[0] = 0;
    for(i = 1; i <= n; i++) {
        q = INT_MIN;
        for(j = 1; j <= i; j++) {
            if(q < p[j]+r[i-j]) {
                s[i] = j;
                q = p[j]+r[i-j];
            }
        }
        r[i] = q;
    }
    for(i = 1; i <= n; i++)
        printf("%d ", r[i]);
    printf("\n");
    for(i = 1; i <= n; i++)
        printf("%d ", s[i]);
    return r[n];
}
/*
int fibi(int n)
{
    if(n == 0 || n == 1) return 1;
    int F[n+1]; 
    F[0] = 1;
    F[1] = 1;
    int i;
    for(i = 2; i <= n; i++)
    {
        F[i] = F[i-1] + F[i-2];
    }
    return F[n];
}

int fun(int *F, int n)
{
    if(n == 0 || n == 1){
        F[n] = 1;
    }
    else F[n] = fun(F, n-1) + fun(F, n-2);
    return F[n];
}

*/
int main()
{
    //int res = cut_rod(p, 10);
    //int res = memoized_cut_rod(p, 10);
    //int res = bottom_up_cut_rod(p, 10);
    int res = extended_bottom_up_cut_rod(p, 10);
    printf("res = %d\n", res);
}
