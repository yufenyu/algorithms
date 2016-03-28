//result if fault

#include <stdio.h>
#include <stdlib.h>

#define N 8

void exchange(int *a, int *b);
int quickSort(int *B, int p, int r);
void partition(int *B, int p, int r);
void main()
{
    int A[8] = {2, 8, 7, 1, 3, 5, 6, 4};
    partition(A, 0, N - 1);

}

void partition(int *B, int p, int r)
{
    int q, i;
    if(p < r)
    {
        q = quickSort(B, p, r);
        partition(B, p, q - 1);
        partition(B, q + 1, r);
        for(i = 0; i < N; i++)
        {
            printf("%d ", B[i]);
        }
        printf("\n");

    }
    
}
int quickSort(int *B, int p, int r)
{
    int j, i = p -1;
    for(j = p; j < r - 1; j++)
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
//one time for quicksort
void main1()
{
    int A[8] = {2, 8, 7, 1, 3, 5, 6, 4};
    int j = 0;
    int i = j - 1;
    int r = N - 1;
    for(j = 0; j < N -1; j++)
    {
        if(A[j] < A[r])
        {
            exchange(&A[i+1], &A[j]);
            i++;
        }
    }
    exchange(&A[i+1], &A[r]);
    for(i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

