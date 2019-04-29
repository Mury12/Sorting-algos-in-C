#ifndef BTREE_H
#define BTREE_H

typedef struct Node{
    int data, set;
    struct Node *right, *left, *parent;
}Node;

typedef struct Tree{
    Node * root;
    int dataCount;
}Tree;

void init(Tree * t);
Node * alloc(int i);
void push(Tree *t, int data);
void pushNode(Node * curr, Node *n);
Tree * pop(Tree * t, int data);
Tree * removeNode(Tree *t, Node *n);

int smallest(Tree * t);
int greatest(Tree * t);

void printTree(Tree t, int format);
void printNode(Node * n, int format);

Node * search(Tree *t, int data);

int leaf(Node *n);
Node * swap(Node * n, Node * t);


#endif