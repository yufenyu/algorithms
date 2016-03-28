#include <stdio.h>
#define RED 1
#define BLACK 2
typedef struct node
{
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
}T;

void left_rotate(T *root, T *x)
{
    T *y = x->right;
    x->right = y->left;
    if(y->left)
        y->left->p = x;
    y->p = x->p;
    if(!x->p)
        root = y;
    else if(x->p->left == x)
        x->p->left = y;
    else
        x->p->right =y;
    y->left = x;
    x->p =y;
}

void right_rotate(T *root, T *y)
{
    T *x = y->left;
    y->left = x->right;
    if(x->right)
        x->right->p = y;
    x->p = y->p;
    if(!y->p)
        root = x;
    else if(y->p->right == y)
        y->p->right = x;
    else 
        y->p->left = x;
    x->right = y;
    y->p = x;
}
void rb_insert(T *root, T *z)
{
    T *y = NULL;
    T *x = root;
    while(x)
    {
        y = x;
        if(z->key < x->key)
           x = x->left;
        else
            x = x->right;
    }
    z->p = y;
    if(!y) root = z;
    else if(z->key < y->key)
        y->left = z;
    else 
        y->right = z;
    z->left = NULL;
    z->right = NULL;
    z->color = RED;
    rb_insert_fixup(root, z);
}

