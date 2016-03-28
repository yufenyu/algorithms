#include <stdio.h>

#define N 20

int S[N], top = 0;

bool stack_empty(void);
bool push(int x);
bool pop(int *x);

void main()
{
    stack_empty(S);
    int a = 1;
    push(a);
    int b;
    pop(&b);
}

bool stack_empty()
{
    if(top == 0)
        return true;
    else
        return false;
}

bool push(int x)
{
    if(top == N)
        return false;
    else
    {
        S[++top] = x;
        return true;
    }
}

bool pop(int *x)
{
    if(top == 0)
        return false;
    else
    {
        *x = S[top--];
        return true;
    }
}
