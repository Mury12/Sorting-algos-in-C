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
    t->height = 0;
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
                    t->height++;
                }
                Node *m = search_insert(t, n, data);
                insert_elem(m, data);
            }else{
                insert_elem(aux, data);
            }
        }else{
            Node *m;
            m = search_insert(t, t->root, data);
            printf("No para insercao:\n\t|%02d|%02d|%02d| \n", m->data[0], m->data[1], m->data[2]);

            if(m->fill == CAP){
                split_node(m);
                m = search_insert(t, t->root, data);
            }
            insert_elem(m, data);
            return;
        }
    }

}
int insert_elem(Node * n, int data)
{
    Node * aux;
    aux = n;
    int r;
    if(aux->fill < CAP){
        int i=0;
        while(aux->data[i] != -1 && i < CAP){
            i++;
        }
        r=i;
        while(data < aux->data[i-1] && i > 0){
            int a;
            Node * b;

            //ordena a inserção
            a = aux->data[i-1];
            aux->data[i-1] = data;
            aux->data[i] = a;
            i--;
        }
        aux->data[i] = data;
        aux->fill++;
        printf("Adicionando elemento %d: |%02d|%02d|%02d| \n", data, n->data[0], n->data[1], n->data[2]);
    }
    return r;
}

Node * search_insert(Tree * t, Node *n, int data)
{
    Node *aux;
    int i=0;
    aux = n;

    //preemptive split
    if(aux->fill == CAP){
        //preemptive split
        if(!aux->parent){//raíz
            //split
            n = split_node(aux);
            t->root = n;
        }else{
            //precisa acertar as referencias
            n = split_node(aux);
        }
        t->height++;
        aux = n;
    }

    if(!aux->childs[0]) return aux;

    for(i=0; i<CAP; i++){
        if(aux->data[i] == -1 || data <= aux->data[i]){
            break;
        }
    }
    if(data > aux->data[i] && aux->childs[i+1]){
        return search_insert(t, aux->childs[i+1], data);
    }else{
        return search_insert(t, aux->childs[i], data);
    }


    // while((data > aux->data[i] && aux->data[i] == -1) && i < CAP){
    //     i++;
    // }

    // if(data > aux->data[i]){
    //     if(data > aux->data[i+1] && aux->childs[i+2]){
    //         printf("\n\n-----%d\n", aux->data[i+2]);
    //         if(data > aux->data[i+2] && aux->childs[i+3]){
    //             return search_insert(t, aux->childs[i+3], data);
    //         }else{
    //             return search_insert(t, aux->childs[i+2], data);
    //         }
    //     }else{
    //         printf("\n\n-----%d\n", aux->data[i+1]);
    //         return search_insert(t, aux->childs[i+1], data);
    //     }
    // }else{
    //     printf("\n\n-----%d\n", aux->data[i]);
    //     return search_insert(t, aux->childs[i], data);
    // }


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
void print_t(Tree t, int order)
{
    print_n(t.root, 0);
}
//Prints the tree nodes
void print_n(Node * n, int order)
{
    int i=0, nc = get_num_childs(n);
    if(!n || nc == 0 ) return;

    printf("|%02d|%02d|%02d| -> ", n->data[0], n->data[1], n->data[2]);
    while(i < nc && n->childs[i]){
        printf("- |%02d|%02d|%02d| ", n->childs[i]->data[0], n->childs[i]->data[1], n->childs[i]->data[2]);
        i++;
    }
    printf("\n");
    i=0;
    while(i < nc && n->childs[i]){
        print_n(n->childs[i],0);
        i++;
    }


}
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
    //n é o nó que será pai, m o nó da direita
    //aux vira filho 0
    Node *n, *m;
    aux->fill = 1;
    Node * p = aux->parent;


    if(aux->parent){

        int i=0, idx, n_childs=0;
        if(p->fill < CAP){

            idx = insert_elem(aux->parent, aux->data[1]);
            printf("\n No cheio, promovido %d\n", aux->data[1]);
            printf("Posicionado em %d\n", idx);

            n_childs = get_num_childs(p);
            //valor da direita
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

        }
            //Se o pai está cheio, ele tem 4 filhos
            //ajustar referencias antes do split


    }else{
        n = allocate(aux->data[1]);
        m = allocate(aux->data[2]);

        printf("\n---filhos %d", get_num_childs(aux));
        if(get_num_childs(aux) == 4){
            m->childs[0] = aux->childs[2];
            m->childs[1] = aux->childs[3];

            m->childs[0]->parent = m;
            m->childs[1]->parent = m;

            n->childs[2] = n->childs[3] = null;
            aux->childs[2] = aux->childs[3] = null;

        }
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