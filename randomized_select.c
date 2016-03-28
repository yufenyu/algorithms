#include <stdio.h>
#include <stdlib.h>
#define N 8
void exchange(int *a, int *b);
int partition(int *B, int p, int r);
int randomized_partition(int *B, int p, int r);
int randomized_select(int *B, int p, int r, int i);
void main()
{
    int A[N], i;
    for(i = 0; i < N; i++)
    {
        A[i] = rand() % 20;
        printf("%d ", A[i]);
    }
    printf("\n");
    i = 2;
    int Ai = randomized_select(A, 0, N - 1, i);
    printf("%d little is %d\n", i, Ai);

}

int randomized_select(int *B, int p, int r, int i)
{
    int k;
    if (p == r)
        return B[p];
    int q = randomized_partition(B, p, r);
    k = q - p + 1;
    if(i == k)
        return B[q];
    else if(i < k)
        return randomized_select(B, p, q - 1, i);
    else
        return randomized_select(B, q + 1, p, i - k);
}

void exchange(int *a, int *b)
{
    int temp;
    temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

int randomized_partition(int *B, int p, int r)
{
    int i = rand() % (N - 1);
    exchange(&B[i], &B[r]);
    return partition(B, p, r);
}
int partition(int *B, int p, int r)
{
    int j, i = p - 1, temp;
    for(j = 0; j < r - 1; j++)
    {
        if(B[j] < B[r])
        {
            exchange(&B[i+1], &B[j]);
            i++;
        }
    }
    exchange(&B[i+1], &B[r]);
    return (i + 1);
}
