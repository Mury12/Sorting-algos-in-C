#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#define null NULL
#define BLACK 0
#define RED 1
#define CAP 3
#define BTREE 1
#define RBLCK 2


void init(Tree * t)
{
    t->root = null;
    t->count = 0;
    t->tree = BTREE;
}
//Inserts a node
void insert(Tree * t, int data)
{
    Node *n, *m, *aux;
    if(t->root == null)
    {
        n = allocate(data);

        printf(" Raiz nula iniciada \n");
        t->root = n;
        t->count++;
    }else{
        aux = t->root;
        //Nó folha
        if(!aux->childs[0]){
            if(aux->fill == CAP){
                //preemptive split
                if(!aux->parent){//raíz
                    //split
                    n = split_node(aux);
                    t->root = n;
                }
                int n_childs = get_num_childs(n);
                while(n_childs>1){
                    printf("\t");
                    n_childs--;
                }
                printf("|%02d|%02d|%02d| \n", n->data[0], n->data[1], n->data[2]);
                printf("|%02d|%02d|%02d|-", n->childs[0]->data[0], n->childs[0]->data[1], n->childs[0]->data[2]);
                printf("|%02d|%02d|%02d| \n", n->childs[1]->data[0], n->childs[1]->data[1], n->childs[1]->data[2]);

                Node *m = search_insert(n, data);
                insert_elem(m, data);

            }else{
                insert_elem(aux, data);
            }
        }else{
            Node *m;
            m = search_insert(t->root, data);
            printf("No para insercao:\n\t|%02d|%02d|%02d| \n", m->data[0], m->data[1], m->data[2]);

            if(m->fill == CAP){
                split_node(m);
                m = search_insert(t->root, data);
            }
            insert_elem(m, data);
                int n_childs = get_num_childs(t->root);
                while(n_childs>1){
                    printf("\t");
                    n_childs--;
                }
            printf("|%02d|%02d|%02d| \n", t->root->data[0], t->root->data[1], t->root->data[2]);
            printf("|%02d|%02d|%02d|", t->root->childs[0]->data[0], t->root->childs[0]->data[1], t->root->childs[0]->data[2]);
            printf("\t|%02d|%02d|%02d|", t->root->childs[1]->data[0], t->root->childs[1]->data[1], t->root->childs[1]->data[2]);
            if(t->root->childs[2]){
                printf("\t|%02d|%02d|%02d|", t->root->childs[2]->data[0], t->root->childs[2]->data[1], t->root->childs[2]->data[2]);
            }
            if(t->root->childs[3]){
                printf("\t|%02d|%02d|%02d|", t->root->childs[3]->data[0], t->root->childs[3]->data[1], t->root->childs[3]->data[2]);
            }

            return;
        }
    }

}
int insert_elem(Node * n, int data)
{
    Node * aux;
    aux = n;

    if(aux->fill < CAP){
        int i=0;
        while(aux->data[i] != -1 && i < CAP){
            i++;
        }

        while(data < aux->data[i-1] && i > 0){
            int a;
            Node * b;
            //ainda precisa trocar a ordem do vetor de childs

            a = aux->data[i-1];
            aux->data[i-1] = data;
            aux->data[i] = a;
            i--;
        }
        aux->data[i] = data;
        aux->fill++;
        printf("Adicionando elemento %d: |%02d|%02d|%02d| \n", data, n->data[0], n->data[1], n->data[2]);
        return i;
    }
}

Node * search_insert(Node *n, int data)
{
    Node *aux;
    int i=0;
    aux = n;


    if(!aux->childs[0]) return aux;
    while((data > aux->data[i] && aux->data[i] == -1) && i < CAP){
        i++;
    }

    if(data > aux->data[i]){
        if(data > aux->data[i+1]){
            printf("\n\n-----%d\n", aux->data[i+2]);
            if(data > aux->data[i+2]){
                return search_insert(aux->childs[i+3], data);
            }else{
                return search_insert(aux->childs[i+2], data);
            }
        }else{
            printf("\n\n-----%d\n", aux->data[i+1]);
            return search_insert(aux->childs[i+1], data);
        }
    }else{
        printf("\n\n-----%d\n", aux->data[i]);
        return search_insert(aux->childs[i], data);
    }


}
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
Node * allocate(int data)
{
    Node * n = malloc(sizeof(Node));

    if(n){
        n->data[0] = data;
        n->data[1] = -1;
        n->data[2] = -1;
        n->fill = 1;
        n->childs[0] = n->childs[1] = n->childs[2] = n->childs[3] = null;
        n->rb = null;
        n->parent = null;
    }
    return n;
}
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

//Divide o nó e retorna o nó pai a/->b<-\c
Node * split_node(Node * aux)
{
    printf("\nNo cheio, split\n");
    Node *n, *m;
    aux->fill = 1;


    if(aux->parent){
        Node * p = aux->parent;

        int i=0, idx, n_childs=0;
        if(p->fill < CAP){
            idx = insert_elem(aux->parent, aux->data[1]);
            printf("\n No cheio, promovendo %d\n", aux->data[1]);
            printf("Posicionado em %d\n", i);

            n_childs = get_num_childs(p);
            n = allocate(aux->data[2]);

            i=n_childs-1;
            printf("\n %d filhos\n", n_childs);
            //move de 1 posição os filhos no vetor
            while(i>idx){
                p->childs[i+1] = p->childs[i];
                i--;
            }
            p->childs[idx+1] = n;
            n->parent = p;

        }else{
            split_node(aux->parent);
        }

    }else{
        n = allocate(aux->data[1]);
        m = allocate(aux->data[2]);
        n->childs[0] = aux;
        n->childs[1] = m;
        aux->parent = m->parent = n;
    }
        aux->data[1] = aux->data[2] = -1;
    return n;
}

char * tree_type(Tree *t)
{
    if(t->tree == BTREE) return "BTREE";
    else return "REDBLACK";
}

int get_num_childs(Node *n)
{
    int n_childs=0, i=0;
    while(n->childs[i] != null && i <= CAP){
        n_childs++;
        i++;
    }
    return n_childs;
}