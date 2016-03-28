#include <stdio.h>
#include <stdlib.h>
#define N 11
void min_max(int *);
void min_max_fast(int *);
void main()
{
    int A[N], i = 0;
    while (i < N)
    {
        A[i]  = rand() % 10;
        i++;
    }

    min_max_fast(A);
}

void min_max_fast(int *array)
{
    int min, max;
    int i;
    if(N % 2 == 0)
    {
        if(array[0] > array[1])
        {
            min = array[1];
            max = array[0];
        }
        else
        {
            min = array[0];
            max = array[1];
        }
        i = 2;
    }
    else 
    {
        min = array[0];
        max = array[0];
        i = 1;
    }
    while(i < N)
    {
        if(array[i] > array[i+1])
        {
            if(array[i] > max) max = array[i];
            if(array[i+1] < min) min = array[i+1];
        }
        else
        {
            if(array[i+1] > max) max = array[i+1];
            if(array[i] < min) min = array[i];
        }
        i += 2;
    }
    for (i = 0; i < N; i++)
        printf("%d ", array[i]);
    printf("\n min = %d, max = %d\n", min, max);

}

void min_max(int *array)
{
    int min, max;
    min = array[0];
    max = array[0];
    int i = 0;
    while(i < N)
    {
        if(array[i] > max) max = array[i];
        if(array[i] < min) min = array[i];
        printf("%d ", array[i]);
        i++;

    }
    printf("\nmin = %d, max = %d\n", min, max);
}
