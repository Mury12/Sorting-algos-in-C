#ifndef TREE_H
#define TREE_H


struct Node{
    int data;
    int bf;
    struct Node * left;
    struct Node * right;
    struct Node * parent;
};

struct Tree{
    struct Node * root;
    int elems, height;
};
typedef struct Tree Tree;
typedef struct Node Node;

void init(Tree * t);
//Inserts a node
void insert(Tree * t, int data);
//Removes a node
void remove_n(Tree * t, int data);
//Updates balance factor
void updateBF(Node * n, Tree * t);
//Balances a subtree
void balance(Node * n);
//Swapp a with b
void swap(Node * a, Node * b);
//Copy a value to b;
void copy(Node * a, Node * b);

//Rotates left
void rotateLeft(Node * n);
//Rotates right
void rotateRight(Node * n);

//Prints a tree
void print_t(Tree t, int order);
//Prints the tree nodes
void print_n(Node * n, int order);
//Gets the tree height
void getHeight(Tree * t);

//Alocates a node
Node * allocate(int data);
//Searches a value in the tree
Node * search(Tree * t, int data);
//Searches the node
Node * search_n(Node * n, int data);
//Gets the bigger value
Node * maxval(Tree * t);
//Gets the lwoest value
Node * minval(Tree * t);
//Next value
Node * next(Node * n);
//Tracks the next node value
Node * find_next(Node * n);
//Previous value
Node * previous(Node * n);
//Tracks the previous node value
Node * find_previous(Node * n);
//Promotes a child node one level above
Node * promoteChild(Node * n);

#endif