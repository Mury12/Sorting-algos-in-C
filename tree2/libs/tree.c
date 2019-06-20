#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#define null NULL
#define true 1
#define false 0


void init(Tree * t)
{
    t->root = null;
    t->elems = 0;
    t->height = -1;
}

//Inserts a node
void insert(Tree * t, int data)
{
    Node * aux, * n;

    n = allocate(data);

    if(t->root == null){
        printf(" Raiz nula iniciada \n");
        t->root = n;
        return;
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
    t->elems++;
    updateBF(n,t);
}

//Removes a node
void remove_n(Tree * t, int data)
{
    Node * n = search(t, data);
    if(!n){
        printf("\n Nó com valor %d não existe.\n", data);
        return;
    }

    Node * aux;

    //Verifica os 3 casos do nó: Folha, 1 filho ou 2 filhos.
    if(!n->left && !n->right){
        printf("\n No %d e folha.\n", data);
        if(n->parent->left == n) n->parent->left = null;
        else n->parent->right = null;
        free(n);
    }else if(n->right && !n->left){
        printf("\n No %d tem um filho à direita.\n", data);
        if(n->parent->left == n) n->parent->left = n->right;
        else n->parent->right = n->right;
        free(n);
    }else if(n->left && !n->right){
        printf("\n No %d tem um filho à esquerda.\n", data);
        if(n->parent->left == n) n->parent->left = n->left;
        else n->parent->right = n->parent->left;
        free(n);
    }else if(n->left && n->right){
        printf("\n No %d tem dois filhos.\n", data);
        aux = next(n);
        copy(aux, n);
        free(aux);
    }
    t->elems--;
    printf("\n Nó com valor %d removido.\n", data);
    print_t(*t, 1);
}
//Updates balance factor
void updateBF(Node * n, Tree * t)
{
    if(!n || !n->parent) return;
    n->parent->left == n ? n->parent->bf-- : n->parent->bf++;
    if(n->parent->bf == -1 || n->parent->bf == 1) updateBF(n->parent, t);

    if(n->parent->bf == 2){
        if(n->bf == -1){
            rotateRight(n->left);
            rotateLeft(n);
        }else rotateLeft(n);
    }else if(n->parent->bf == -2){
        if(n->bf == 1){
            rotateLeft(n->right);
            rotateRight(n);
        }else rotateRight(n);
    }
    if(!n->parent) t->root = n;
}
//Balances a subtree
void balance(Node * n)
{

}
//Swapp a with b
void swap(Node * a, Node * b)
{
    Node aux;

    aux = *a;
    a = b;
    b = &aux;
}
//Copy b value to a;
void copy(Node * a, Node * b)
{
    Node aux;
    aux = *a;
    a->data = b->data;
    b->data = aux.data;
}

//Rotates left
void rotateLeft(Node * n)
{
    printf("\n Rotacionando para a esquerda o nó %d\n", n->data);

    Node * aux = n->parent;

    //Nó a esquerda de n torna-se no a direita do pai;
    n->parent->right = n->left;
    //Nó pai se torna filho à esquerda de n
    n->left = n->parent;
    //No pai do pai de N torna-se pai de N
    n->parent = aux->parent;
    if(aux->parent) aux->parent->right = n;
    //N se torna pai do ex pai
    aux->parent = n;
    aux->bf = 0;
    if(aux->left) aux->bf--;
    if(aux->right) aux->bf++;
    n->bf = 0;

}
//Rotates right
void rotateRight(Node * n)
{
    printf("\n Rotacionando para a direita o nó %d\n", n->data);

        Node * aux = n->parent;

    //Nó a esquerda de n torna-se no a direita do pai;
    n->parent->left = n->right;
    //Nó pai se torna filho à esquerda de n
    n->right = n->parent;
    //No pai do pai de N torna-se pai de N
    n->parent = aux->parent;
    if(aux->parent) aux->parent->left = n;
    //N se torna pai do ex pai
    aux->parent = n;
    aux->bf = 0;
    if(aux->left) aux->bf--;
    if(aux->right) aux->bf++;
    n->bf = 0;

}


//Prints a tree
void print_t(Tree t, int order)
{
    print_n(t.root, order);
    printf("\n");
}
//Recursively prints the nodes
void print_n(Node * n, int order)
{
    if(n == null) return;

    switch(order){
        case 1:
            print_n(n->left, order);
            printf(" \n bf node %d is %d ", n->data, n->bf);
            print_n(n->right, order);
            break;
        case 2:
            printf(" %d ", n->data);
            print_n(n->left, order);
            print_n(n->right, order);
            break;
        case 3:
            print_n(n->left, order);
            print_n(n->right, order);
            printf(" %d ", n->data);
            break;
    }
}

//Gets the tree height
void getHeight(Tree * t);

//Alocates a node
Node * allocate(int data)
{
    Node * n = malloc(sizeof(Node));

    if(n){
        n->data = data;
        n->left = null;
        n->right = null;
        n->bf = 0;
    }
    return n;
}

Node * search_n(Node * n, int data)
{
    if(!n || n->data == data) return n;
    if(data < n->data) search_n(n->left, data);
    else search_n(n->right, data);
}
//Searches a value in the tree
Node * search(Tree * t, int data)
{
    return search_n(t->root, data);
}
//Gets the bigger value
Node * maxval(Tree * t)
{
    return find_previous(t->root);
}
//Gets the lwoest value
Node * minval(Tree * t)
{
    return find_next(t->root);
}
//Next value
Node * next(Node * n)
{
    return find_next(n->right);
}
Node * find_next(Node * n)
{
    if(!n->left) return n;
    else find_next(n->left);
}
//Previous value
Node * previous(Node * n){
    return find_previous(n->left);
}
Node * find_previous(Node * n)
{
    if(!n->right) return n;
    else find_previous (n->right);
}
//Promotes a child node one level above
Node * promoteChild(Node * n)
{

}
