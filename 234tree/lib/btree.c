#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#define null NULL
#define CAP 3
#define BTREE 1
#define RBLCK 2


void init(Tree_234 * t)
{
    t->root = null;
    t->count = 0;
    t->height = 0;
    t->tree = BTREE;
}
//Inserts a node
void insert(Tree_234 * t, int data)
{
    Node_234 *n, *m, *aux;
    if(t->root == null)
    {
        n = allocate(data);

        printf(" Raiz nula iniciada \n");
        t->root = n;
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
                Node_234 *m = search_insert(t, n, data);
                insert_elem(m, data);
            }else{
                insert_elem(aux, data);
            }
        }else{
            Node_234 *m;
            m = search_insert(t, t->root, data);
            printf("No para insercao: |%02d|%02d|%02d| \n", m->data[0], m->data[1], m->data[2]);

            if(m->fill == CAP){
                split_node(m);
                m = search_insert(t, t->root, data);
            }
            insert_elem(m, data);

        }
    }
    t->count++;
}
int insert_elem(Node_234 * n, int data)
{
    Node_234 * aux;
    aux = n;
    int r=0;
    if(aux->fill < CAP){
        int i=0;
        while(aux->data[i] != -1 && i < CAP){
            i++;
        }
        while(data < aux->data[i-1] && i > 0){
            int a;
            Node_234 * b;

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
    r=0;
    while(r<CAP){
        if(aux->data[r] == data) break;
        r++;
    }
    return r;
}

Node_234 * search_insert(Tree_234 * t, Node_234 *n, int data)
{
    Node_234 *aux;
    int i=0;
    aux = n;

    //preemptive split
    if(aux->fill == CAP){
        //preemptive split
        if(!aux->parent){//raíz
            //split
            n = split_node(aux);
            t->root = n;
            t->height++;
        }else{
            n = split_node(aux);
        }
        if(n->parent)
            aux = n->parent;
        else
            aux = t->root;
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
}
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
void print_t(Tree_234 t, int order)
{
    printf("\n|---NO---| ->  |FILHO 01| - |FILHO 02| - |FILHO 03| - |FILHO 04| \n");
    print_n(t.root, 0);
    printf("\nAltura: %d\tElementos: %d\tTipo: %s\n", t.height, t.count, tree_type(&t));
}
//Imprime um nó na tela
//|PAI| -> |F0| - |F1| - |F2| - |F3|
//|F0|  -> |f0| - |f1| - |f2| - |f3|
//|f0|  -> |ff0| ...
//|F1|  -> ...
void print_n(Node_234 * n, int order)
{
    int i=0, nc = get_num_childs(n);
    if(!n || nc == 0 ) return;

    printf("|%02d|%02d|%02d| -> ", n->data[0], n->data[1], n->data[2]);
    while(i < nc && n->childs[i]){
        if(i>0) printf("-");
        printf(" |%02d|%02d|%02d| ", n->childs[i]->data[0], n->childs[i]->data[1], n->childs[i]->data[2]);
        i++;
    }
    printf("\n");
    i=0;
    while(i < nc && n->childs[i]){
        print_n(n->childs[i],0);
        i++;
    }


}

//Aloca um nó
Node_234 * allocate(int data)
{
    Node_234 * n = malloc(sizeof(Node_234));

    if(n){
        n->data[0] = data;
        n->data[1] = -1;
        n->data[2] = -1;
        n->fill = 1;
        n->childs[0] = n->childs[1] = n->childs[2] = n->childs[3] = null;
        n->parent = null;
    }
    return n;
}
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

//Divide o nó e retorna o nó pai a/->b<-\c
Node_234 * split_node(Node_234 * aux)
{
    printf("\nNo cheio, split\n");
    //n é o nó que será pai, m o nó da direita
    //aux vira filho 0
    Node_234 *n, *m;
    aux->fill = 1;
    Node_234 * p = aux->parent;


    if(aux->parent){
        int i=0, idx, n_childs=0;
        if(p->fill < CAP){

            idx = insert_elem(aux->parent, aux->data[1]);
            printf("\n Promovido %d, ", aux->data[1]);
            printf("posicionado em %d\n", idx);

            n_childs = get_num_childs(p);
            //valor da direita
            n = allocate(aux->data[2]);

            i=n_childs-1;

            //move de 1 posição os filhos no vetor
            while(i>idx){
                p->childs[i+1] = p->childs[i];
                i--;
            }
            Node_234 * z = p->childs[idx];
            if(n->data[0] > p->data[idx]){
                p->childs[idx+1] = n;
            }else
            if(z->data[0] > p->data[idx]){
                p->childs[idx] = n;
                p->childs[idx+1] = z;
            }
            //Set pai de n
            n->parent = p;

            //Se não é nó folha, acerta as referências
            if(aux->childs[0]){
                n->childs[0] = aux->childs[2];
                n->childs[1] = aux->childs[3];
                n->childs[0]->parent = n->childs[1]->parent = n;
                aux->childs[2] = aux->childs[3] = null;
            }

        }

    }else{
        //Nó que sobe
        n = allocate(aux->data[1]);
        //Filho da direita
        m = allocate(aux->data[2]);

        if(get_num_childs(aux) == 4){
            m->childs[0] = aux->childs[2];
            m->childs[1] = aux->childs[3];

            m->childs[0]->parent = m;
            m->childs[1]->parent = m;

            n->childs[2] = n->childs[3] = null;
            aux->childs[2] = aux->childs[3] = null;

        }
        //Ajusta as referencias dos filhos de n
        n->childs[0] = aux;
        n->childs[1] = m;
        aux->parent = m->parent = n;
    }
    //esvazia as posições que saíram
    aux->data[1] = aux->data[2] = -1;
    return n;
}

char * tree_type(Tree_234 *t)
{
    if(t->tree == BTREE) return "BTREE";
    else return "REDBLACK";
}

//Retorna o número de filhos de um nó
int get_num_childs(Node_234 *n)
{
    int n_childs=0, i=0;
    while(n->childs[i] != null && i <= CAP){
        n_childs++;
        i++;
    }
    return n_childs;
}