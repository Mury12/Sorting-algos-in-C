#ifndef BTREE_H
#define BTREE_H


struct rb_node{
    struct node * left, * right;
    int color;
};
struct node{
    int data[3];
    int fill;
    struct node * childs[4];
    struct node * parent;
    struct rb_node * rb;
};
struct tree{
    struct node * root;
    int count;
    int tree;
};

struct rb_node;
struct node;
struct tree;
typedef struct node Node;
typedef struct rb_node RB_Node;
typedef struct tree Tree;

void init(Tree * t);
//Inserts a node
void insert(Tree * t, int data);
//Insere o nó e retorna o indice
int insert_elem(Node * n, int data);
//Removes a node
void remove_n(Tree * t, int data);
void remove_btree(Node * n);
void remove_rb(Node * n);
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

Node * split_node(Node * aux);
Node * search_insert(Node *n, int data);

char * tree_type(Tree *t);
int get_num_childs(Node *n);

#endif