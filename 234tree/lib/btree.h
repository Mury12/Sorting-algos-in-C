#ifndef BTREE_H
#define BTREE_H

struct node_234{
    int data[3];
    int fill;
    struct node_234 * childs[4];
    struct node_234 * parent;
};
struct tree_234{
    struct node_234 * root;
    int count;
    int height;
    int tree;
};

typedef struct node_234 Node_234;
typedef struct tree_234 Tree_234;

void init(Tree_234 * t);
//Inserts a node
void insert(Tree_234 * t, int data);
//Insere o nó e retorna o indice
int insert_elem(Node_234 * n, int data);
//Removes a node
void remove_n(Tree_234 * t, int data);
void remove_btree(Node_234 * n);
void remove_rb(Node_234 * n);
//Updates balance factor
void updateBF(Node_234 * n, Tree_234 * t);
//Balances a subtree
void balance(Node_234 * n);
//Swapp a with b
void swap(Node_234 * a, Node_234 * b);
//Copy a value to b;
void copy(Node_234 * a, Node_234 * b);

//Rotates left
void rotateLeft(Node_234 * n);
//Rotates right
void rotateRight(Node_234 * n);

//Prints a tree
void print_t(Tree_234 t, int order);
//Prints the tree nodes
void print_n(Node_234 * n, int order);
//Gets the tree height
void getHeight(Tree_234 * t);

//Alocates a node
Node_234 * allocate(int data);
//Searches a value in the tree
Node_234 * search(Tree_234 * t, int data);
//Searches the node
Node_234 * search_n(Node_234 * n, int data);
//Gets the bigger value
Node_234 * maxval(Tree_234 * t);
//Gets the lwoest value
Node_234 * minval(Tree_234 * t);
//Next value
Node_234 * next(Node_234 * n);
//Tracks the next node value
Node_234 * find_next(Node_234 * n);
//Previous value
Node_234 * previous(Node_234 * n);
//Tracks the previous node value
Node_234 * find_previous(Node_234 * n);
//Promotes a child node one level above
Node_234 * promoteChild(Node_234 * n);

Node_234 * split_node(Node_234 * aux);
Node_234 * search_insert(Tree_234 * t, Node_234 *n, int data);

char * tree_type(Tree_234 *t);
int get_num_childs(Node_234 *n);

#endif