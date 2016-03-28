#include <stdio.h>

typedef struct node
{
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
}T, *TreePtr;
void inOrder_tree(T *root);
T *tree_search(T *root, int x);
T *iterator_tree_search(T *root, int x);
T *tree_minimum(T *root);


void inOrder_tree(T *root)
{
    if(root)
    {
        if(root->left)
            inOrder_tree(root->left);
        printf("%d ", root->key);
        if(root->right)
            inOrder_tree(root->right);
    }
}

T *tree_search(T *root, int x)
{
    if(!root || root->key == x)
        return root;
    else if(x < root->key)
        return tree_search(root->left, x);
    else
        return tree_search(root->right, x);
}

T *iterative_tree_search(T *root, int x)
{
    while(root && root->key != x)
    {
        if(x < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

T * tree_minimum(T *root)
{
    while(root->left)
        root = root->left;
    return root;
}

T *tree_maxmum(T *root)
{
    while(root->right)
        root = root->right;
    return root;
}

T *tree_successor(T *x)//x的后继
{
    if(x->right)
        return tree_minimum(x->right);
    T *y = x->p;
    while(x == y->right && y)
    {
        x = y;
        y = y.p;
    }
    return y;
}

T *tree_predecessor(T *x)//x的前躯
{
    if(x->left)
        return tree_maxmum(x->left);
    T *y = x->p;
    while(y && x == y->left)
    {
        x = y;
        y = y.p;
    }
    return y;
}

T *tree_insert(T *root, T *z)
{
    y = NULL;
    x = root;
    while(x)
    {
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z.p = y;
    if(!y) 
        root = z;
    else if(z.key < y.key)
        y.left = z;
    else
        y.right =z;
    }
}
/**
以v为根的子树替换以u为子树的树
**/
void transplant(T *root, T *u, T *v)
{
    if(u->p == NULL)
        root = v;
    else if(u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;
    if(v) v.p = u.p;
}
void tree_delete(T *root, T *z)
{
    if(!z->right)
        transplant(root, z, z->left);
    else if(!z->left)
        transplant(root, z, z->right);
    else y = tree_minimum(z.right)
    {
        if(y->p != z)
        {
            transplant(T, y, y->right);
            y->right = z->right;
            z->right->p = y;
        }
        transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
    }
}
