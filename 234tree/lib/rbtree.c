#include <stdlib.h>
#include <stdio.h>
#include "rbtree.h"

#define null NULL
#define BLK 0
#define RED 1
#define BTREE 1
#define RBLCK 2
#define LEFT 1
#define RIGHT 2


void init_rb(RB_Tree * t)
{
    t->root = NULL;
    t->count = 0;
    t->height = 0;
    t->tree = RBLCK;
}
//Inserção binária simples
RB_Node * ord_insert(RB_Tree * t, int data)
{
    RB_Node * aux, * n;

    n = allocate_rb(data);
    printf("\n %s \n", get_node_color(n));
    if(t->root == null){
        printf(" Raiz nula iniciada \n");
        change_color(n, BLK);
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
    rb_fixup(t, n);
    return n;
}

void rb_fixup(RB_Tree * t, RB_Node * n)
{
    //x = nó resultado da inserção normal
    RB_Node *y, *uncle;

    if(n == t->root || !n || n->parent == t->root) return;

    if(n->parent->parent){
        uncle = get_self_side(n->parent) == RIGHT
                ? n->parent->parent->left
                : n->parent->parent->right;
    }else uncle = null;
//Caso 1 L

    if(n->parent && get_color_code(uncle) == RED && n->parent->color == RED){

        change_color(n->parent, BLK);
        change_color(uncle,  BLK);
        change_color(uncle->parent,  RED);
        change_color(t->root, BLK);
        return rb_fixup(t, n->parent->parent);
    }

//Caso 2 L
    if(n->parent && get_color_code(uncle) == BLK){
        if(get_self_side(n) == LEFT && get_self_side(n->parent) == LEFT){
            rotateRight_rb(t, n->parent);
            change_color(t->root, BLK);
            return rb_fixup(t, n->right);
        }
        if(get_self_side(n) == RIGHT && get_self_side(n->parent) == RIGHT){
            rotateLeft_rb(t, n->parent);
            change_color(t->root, BLK);
            return rb_fixup(t, n->left);
        }

//Caso 3 L
        if(get_self_side(n) == LEFT && get_self_side(n->parent) == RIGHT){
            change_color(n->parent,BLK);
            rotateRight_rb(t, n);
            change_color(t->root, BLK);
            return rb_fixup(t, n->right);
        }
        if(get_self_side(n) == RIGHT && get_self_side(n->parent) == LEFT){
            change_color(n->parent,BLK);
            rotateLeft_rb(t, n);
            change_color(t->root, BLK);
            return rb_fixup(t, n->left);
        }
    }

    return;
}
//Removes a node
/**
 * Retira um nó com um conteudo data de uma árvore t.
 */
RB_Tree * remove_rb(RB_Tree * t, int data)
{
    if(!t->root) return t;
    int root_val = t->root->data;
    RB_Node *n = search_rb(t, data);
    if(n){
        if(n->color == BLK){
            RB_Node *aux;
            if(n != t->root){
                aux = get_self_side(n) == LEFT
                    ? n->parent->right
                    : n->parent->left;
                aux = !aux ? n->parent : aux;
            }
                t = remove_rb_node(t, n);
                if(data != root_val){
                    rb_fixup(t, aux);
                }
        }else{
            t = remove_rb_node(t, n);
        }
        t->count--;
    }else{
        printf("\n\t---VALOR NAO ENCONTRADO.\n");
    }
    return t;
}

/**
 * Remove um nó n da árvore t
 */
RB_Tree * remove_rb_node(RB_Tree *t, RB_Node *n)
{
    RB_Node *aux = n;
    int data = n->data;

    printf("\n\t---EXCLUINDO NO %d \n", n->data);

    if(!leaf(n)){

        if(aux->left){
            aux = aux->left;
            while(aux->right){
                aux = aux->right;
            }
        }else{
            aux->parent->left = aux->right;
        }
        if(get_self_side(aux) == LEFT){
            aux->parent->left = null;
        }else{
            aux->parent->right = null;
        }
        swap_rb_nodes(n, aux);

        free(aux);
    }else{
        if(n->parent->data > n->data){
            aux->parent->left = aux->left ? aux->left : null;
        }else{
            aux->parent->right = aux->left ? aux->left : null;
        }
        free(n);
    }


    printf("\n\t---NO COM VALOR %d REMOVIDO. \n", data);

    return t;
}

//Updates balance factor

//Rotates left
void rotateLeft_rb(RB_Tree * t, RB_Node * n)
{
    printf("\n--Nó %d desbalanceado, rotacao a esquerda.\n", n->data);
    RB_Node *aux;
    if(n == t->root) return;
    //Se o pai de N for raíz, n se tornará raíz
    if(n->parent == t->root) t->root = n;

    aux = n->parent;

    int color;
    color = n->color;
    change_color(n, get_color_code(n->parent));
    n->parent ? change_color(n->parent, color) : 0;
    //Pai recebe o filho a direita do nó que sobe
    n->parent->right = n->left;
    n->left = n->parent;

    //Atualiza o avô
     if(n->parent->parent){
        if(get_self_side(n->parent) == RIGHT){
            n->parent->parent->right = n;
        }else{
            n->parent->parent->left = n;
        }
    }
    n->parent = aux->parent;
    aux->parent = n;

    if(n == t->root) n->parent = null;
}
//Rotates right
void rotateRight_rb(RB_Tree * t, RB_Node * n)
{
    printf("\n--Nó %d desbalanceado, rotacao a direita.\n", n->data);
    RB_Node *aux;
    if(n == t->root) return;
    //Se o pai de N for raíz, n se tornará raíz
    if(n->parent == t->root) t->root = n;
    aux = n->parent;

    int color;
    color = n->color;
    change_color(n, get_color_code(n->parent));
    n->parent ? change_color(n->parent,color) : 0;
    //Pai recebe o filho a direita do nó que sobe
    n->parent->left = n->right;
    n->right = n->parent;

    if(n->parent->parent){
        if(get_self_side(n->parent) == RIGHT){
            n->parent->parent->right = n;
        }else{
            n->parent->parent->left = n;
        }
    }
    n->parent = aux->parent;
    aux->parent = n;

    if(n == t->root) n->parent = null;

}

void print_rb(RB_Tree t, int order)
{
    printf("\nRaiz: %d %s", t.root->data, get_node_color(t.root));
    print_n_rb(t.root, order);
    printf("\n\n");
    print_n_rb(t.root, 4);
    printf("\n\n");
    printf("\t-------------------------------------------------------------\n");
    printf("\t|         RED-BLACK  RAIZ: %d %s   ELEMENTOS: %d           |\n", t.root->data, get_node_color(t.root), t.count);
    printf("\t|                  (X)->RED [X]->BLACK                      |\n");
    printf("\t-------------------------------------------------------------\n");
}
//Recursively prints the nodes
void print_n_rb(RB_Node * n, int order)
{
    if(!n) return;

    switch(order){
        case 1:
            print_n_rb(n->left, order);
            // printf(" \n %d - %s", n->data, get_node_color(n));
            printf("\n---------- \n");
            if( get_color_code(n) == BLK)
            printf("\n---[%02d]--- \n", n->data);
            else
            printf("\n---(%02d)--- \n", n->data);

            if(n->left){
                if( get_color_code(n->left) == BLK)
                    printf("[%02d]<", n->left->data);
                else
                    printf("(%02d)<", n->left->data);
            }else printf("---le");
            if(n->right){
                if( get_color_code(n->right) == BLK)
                    printf(">[%02d]", n->right->data);
                else
                    printf(">(%02d)", n->right->data);
            }else printf("af---");

            print_n_rb(n->right, order);
            break;
        case 2:
            printf(" \n %d - %s", n->data, get_node_color(n));
            print_n_rb(n->left, order);
            print_n_rb(n->right, order);
            break;
        case 3:
            print_n_rb(n->left, order);
            print_n_rb(n->right, order);
            printf(" \n %d - %s", n->data, get_node_color(n));
            break;
        case 4:
            print_n_rb(n->left, order);
            if(get_color_code(n) == BLK)
            printf("[%d] ", n->data);
            else
            printf("(%d) ", n->data);
            print_n_rb(n->right, order);
    }
}

//Alocates a node
RB_Node * allocate_rb(int data)
{
    RB_Node * n = malloc(sizeof(RB_Node));
    n->data   = data;
    n->color  = RED;
    n->left   = null;
    n->right  = null;
    n->parent = null;

    return n;
}
//Searches a value in the tree
RB_Node * search_rb(RB_Tree *t, int data)
{
    RB_Node *n = t->root;
    while(n->data != data){
        if(data > n->data && n->right){
            n = n->right;
        }else{
            if(n->left){
                n = n->left;
            }else{
                return null;
            }
        }
    }
    return n;
}
//Gets the bigger value
RB_Node * maxval_rb(RB_Tree * t)
{
    RB_Node * max;
    max = t->root;

    while(max->right)
    {
        max = max->right;
    }
    return max;
}
//Gets the lwoest value
RB_Node * minval_rb(RB_Tree * t)
{
    RB_Node * min;
    min = t->root;

    while(min->left)
    {
        min = min->right;
    }
    return min;
}
//Next value
RB_Node * next_rb(RB_Node * n);
//Tracks the next node value
RB_Node * find_next_rb(RB_Node * n);
//Previous value
RB_Node * previous_rb(RB_Node * n);
//Tracks the previous node value
RB_Node * find_previous_rb(RB_Node * n);

RB_Node * swap_rb_nodes(RB_Node * n, RB_Node * t)
{
    int aux;

    aux = n->data;

    // printf("\n n %d t %d", n->data, t->data);

    n->data = t->data;
    t->data = aux;
    // printf("\n n %d t %d", n->data, t->data);

    return t;
}

char * get_node_color(RB_Node * n)
{
    if(n->color == BLK || !n) return "BLK";
    else return "RED";
}

int get_color_code(RB_Node * n)
{
    return !n ? BLK : n->color;
}

int get_self_side(RB_Node * self)
{
    if(self->parent){
        return self == self->parent->right ? RIGHT : LEFT;
    }
    return 0;
}

void invert_color(RB_Node * self)
{
    if(self){
        if(self->parent){
            self->color = get_color_code(self) == RED
                        ? BLK
                        : RED;
        }
    }
}

void change_color(RB_Node * n, int color)
{
    n ? n->color = color : 0;
    // printf("\n\t\t %d color changed to %s\n", n->data, get_node_color(n));
}

/**
 * Retorna 1 se o nó é folha ou 0 caso contrário
 */
int leaf(RB_Node *n)
{
    if(n->left || n->right) return 0;
    return 1;
}