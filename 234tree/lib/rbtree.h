#ifndef RBTREE_H
#define RBTREE_H


struct rb_node{
    int data;
    struct rb_node * left, * right, *parent;
    int color;
};

struct rb_tree{
    struct rb_node * root;
    int count;
    int height;
    int tree;
};
typedef struct rb_node RB_Node;
typedef struct rb_tree RB_Tree;

void init_rb(RB_Tree * t);
//Inserts a node
RB_Node * ord_insert(RB_Tree * t, int data);
void insert_rb(RB_Tree * t, int data);
//Insere o nó e retorna o indice
int insert_elem_rb(RB_Node * n, int data);
//Removes a node
void remove_n_rb(RB_Tree * t, int data);
void remove_btree_rb(RB_Node * n);
void remove_rb_rb(RB_Node * n);
//Updates balance factor
void updateBF_rb(RB_Node * n, RB_Tree * t);
//Balances a subtree
void balance_rb(RB_Node * n);
//Swapp a with b
void swap_rb(RB_Node * a, RB_Node * b);
//Copy a value to b;
void copy_rb(RB_Node * a, RB_Node * b);

//Rotates left
void rotateLeft_rb(RB_Tree * t, RB_Node * n);
//Rotates right
void rotateRight_rb(RB_Tree * t, RB_Node * n);

//Prints a tree
void print_rb(RB_Tree t, int order);
//Prints the tree nodes
void print_n_rb(RB_Node * n, int order);
//Gets the tree height
void getHeight_rb(RB_Tree * t);

//Alocates a node
RB_Node * allocate_rb(int data);
//Searches a value in the tree
RB_Node * search_rb(RB_Tree * t, int data);
//Searches the node
RB_Node * search_n_rb(RB_Node * n, int data);
//Gets the bigger value
RB_Node * maxval_rb(RB_Tree * t);
//Gets the lwoest value
RB_Node * minval_rb(RB_Tree * t);
//Next value
RB_Node * next_rb(RB_Node * n);
//Tracks the next node value
RB_Node * find_next_rb(RB_Node * n);
//Previous value
RB_Node * previous_rb(RB_Node * n);
//Tracks the previous node value
RB_Node * find_previous_rb(RB_Node * n);
//Promotes a child node one level above
RB_Node * promoteChild_rb(RB_Node * n);

RB_Node * split_node_rb(RB_Node * aux);
RB_Node * search_insert_rb(RB_Tree * t, RB_Node *n, int data);

char * get_node_color(RB_Node * n);

#endif