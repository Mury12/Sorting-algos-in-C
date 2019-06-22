#include <stdlib.h>
#include <stdio.h>
#include "rbtree.h"
#define null NULL
#define BLK 0
#define RED 1
#define BTREE 1
#define RBLCK 2



void init_rb(RB_Tree * t)
{
    t->root = NULL;
    t->count = 0;
    t->height = 0;
    t->tree = RBLCK;
}
//Inserts a node

RB_Node * ord_insert(RB_Tree * t, int data)
{
    RB_Node * aux, * n;

    n = allocate_rb(data);
    printf("\n %s \n", get_node_color(n));
    if(t->root == null){
        printf(" Raiz nula iniciada \n");
        t->root = n;
        return n;
    }

    aux = t->root;
    printf("Adicionando novo nó: %d \n", n->data);

    while(1){
        if(data < aux->data && aux->left){
            aux = aux->left;
        }else if(data >= aux->data && aux->right){
                aux = aux->right;
        }else break;
    }

    if(data > aux->data){
        printf("Nó adicionado à direita de %d \n", aux->data);
        aux->right = n;
    }else{
        printf("Nó adicionado à esquerda de %d \n", aux->data);
        aux->left = n;
    }

    n->parent = aux;
    t->count++;

    return n;
}

void insert_rb(RB_Tree * t, int data)
{
    RB_Node * x = ord_insert(t, data), *y;

    if(x == t->root) return;

    x->color = RED;

        while(x != t->root){
            if(x->parent->parent){
                if(x->parent->parent->left && x->parent == x->parent->parent->left){
                    if(x->parent->parent->right){
                        y = x->parent->parent->right;
                        if(y->color == RED){
                            x->parent->parent->color = RED;
                            x->parent->color = BLK;
                            y->color = BLK;
                            x = x->parent->parent;
                        }else{
                            if(x == x->parent->right){
                                x = x->parent;
                                rotateLeft_rb(t, x);
                            }
                            x->parent->color = BLK;
                            x->parent->parent->color = RED;
                            rotateRight_rb(t, x);
                        }
                    }
                }else{
                    if(x->parent->parent->left){
                        y = x->parent->parent->left;
                        if(y->color == RED){
                            x->parent->parent->color = RED;
                            x->parent->color = BLK;
                            y->color = BLK;
                            x = x->parent->parent;
                        }else{
                            if(x == x->parent->left){
                                x = x->parent;
                                rotateRight_rb(t, x);
                            }
                            x->parent->color = BLK;
                            x->parent->parent->color = RED;
                            rotateLeft_rb(t, x);
                        }
                    }
                }
                x = x->parent;
            }else{
                x->color = RED;
            }
        }

    t->root->color = BLK;
}
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
void rotateLeft_rb(RB_Tree * t, RB_Node * n)
{
    printf("\n--Nó %d desbalanceado, rotacao esquerda.\n", n->data);
    RB_Node * aux;
    //aux recebe filho direito de n
    aux = n->right;

    n->right = aux->left;

    if(aux->left){
        aux->left->parent = n;
    }
    aux->parent = n->parent;

    if(!n->parent){
        t->root = aux;
    }else
    if(n = n->parent->left){
        n->parent->left = aux;
    }else{
        n->parent->right = aux;
    }

    aux->left = n;
    n->parent = aux;
}
//Rotates right
void rotateRight_rb(RB_Tree * t, RB_Node * n)
{
    printf("\n--Nó %d desbalanceado, rotacao esquerda.\n", n->data);
    RB_Node * aux;
    //aux recebe filho direito de n
    aux = n->left;

    n->left = aux->right;

    if(aux->right){
        aux->right->parent = n;
    }
    aux->parent = n->parent;

    if(!n->parent){
        t->root = aux;
    }else
    if(n = n->parent->right){
        n->parent->right = aux;
    }else{
        n->parent->left = aux;
    }

    aux->right = n;
    n->parent = aux;
}

void print_rb(RB_Tree t, int order)
{
    print_n_rb(t.root, order);
    printf("\n");
}
//Recursively prints the nodes
void print_n_rb(RB_Node * n, int order)
{
    if(n == null) return;

    switch(order){
        case 1:
            print_n_rb(n->left, order);
            printf(" \n %d - %s", n->data, get_node_color(n));
            print_n_rb(n->right, order);
            break;
        case 2:
            printf(" %d ", n->data);
            print_n_rb(n->left, order);
            print_n_rb(n->right, order);
            break;
        case 3:
            print_n_rb(n->left, order);
            print_n_rb(n->right, order);
            printf(" %d ", n->data);
            break;
    }
}
//Gets the tree height
void getHeight_rb(RB_Tree * t);

//Alocates a node
RB_Node * allocate_rb(int data)
{
    RB_Node * n = malloc(sizeof(RB_Node));
    n->data   = data;
    n->color  = BLK;
    n->left   = null;
    n->right  = null;
    n->parent = null;

    return n;
}
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

char * get_node_color(RB_Node * n)
{
    if(n->color == BLK) return "BLK";
    else return "RED";
}