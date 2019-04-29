#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "btree.h"

#define null NULL

/**
 * Inicia a árvore a partir da definição de arvore t.
 */
void init(Tree * t)
{
    t->dataCount=0;
    t->root = null;
}

/**
 * Aloca um nó para um dado inteiro.
 */ 
Node * alloc(int i)
{
    Node *n;

    n = malloc(sizeof(Node));

    if(n){
        n->data = i;
        n->set = 1;
        n->parent = null;
        n->left = null;
        n->right = null;
    }
    return n;
}

/**
 * Insere um nó na árvore t
 */
void push(Tree *t, int data)
{
    Node *n;
    n = alloc(data);
    
    if(!n) return;

    if(!t->root){
        t->root = n;
    }else{
        if(n->data > t->root->data){
            if(!t->root->right){
                t->root->right = n;
                n->parent = t->root;
            }else{
                pushNode(t->root->right, n);
            }
        }else{
            if(!t->root->left){
                t->root->left = n;
                n->parent = t->root;
            }else{
                pushNode(t->root->left, n);
            }
        }
    }
}

/**
 * Insere um nó na sequência do nó atual.
 */ 
void pushNode(Node * curr, Node *n)
{
    if(!curr){
        curr = n;
    }else{
        if(n->data > curr->data){
            if(!curr->right){
                curr->right = n;
                        n->parent = curr;   

            }else{
                pushNode(curr->right, n);
            }
        }else{
            if(!curr->left){
                curr->left = n;
                        n->parent = curr;   

            }else{
                pushNode(curr->left, n);
            }
        }
    }
}

/**
 * Retira um nó com um conteudo data de uma árvore t.
 */
Tree * pop(Tree * t, int data)
{
    if(!t->root) return t;

    Node *n = search(t, data);
    if(n){
        t = removeNode(t, n);
    }else{
        printf("\n No nao encontrado.\n");
    }
    return t;
}

/**
 * Remove um nó n da árvore t
 */ 
Tree * removeNode(Tree *t, Node *n)
{
    Node *aux = n;

    printf("\n Excluindo no com valor %d \n", n->data);
    
    if(!leaf(n)){

        if(aux->left){
            aux = aux->left;
            while(aux->right){
                aux = aux->right;
            }
        }else{
            aux->parent->left = aux->right;
            printf("\n nao tem esquerda em %d", aux->data);
        }
        swap(n, aux);
        

        printf("\n aux %d", aux->data);

        
    }else{
        if(n->parent->data > n->data){
            aux->parent->left = aux->left ? aux->left : null;
        }else{
            aux->parent->right = aux->left ? aux->left : null;
        }
        free(n);
    }


    printf("\n No com valor %d removido. \n", aux->data);

    return t;
}

/**
 * Coloca o nó t na posição de n
 */ 

Node * swap(Node * n, Node * t)
{
    int aux;

    aux = n->data;

    printf("\n n %d t %d", n->data, t->data);

    n->data = t->data;
    t->data = aux;
    printf("\n n %d t %d", n->data, t->data);

    return t;
}

/**
 * Recupera o menor registro da árvore.
 */
int smallest(Tree * t)
{
    if(t->root){
        Node * n = t->root;
        while(n->left){
            n = n->left;
        }
        return n->data;
    }
}

/**
 * Recupera o maior registro da árvore.
 */
int greatest(Tree * t)
{
    if(t->root){
        Node * n = t->root;
        while(n->right){
            n = n->right;
        }
        return n->data;
    }
}


/**
 * Imprime uma árvore em ordem crescente
 */ 
void printTree(Tree t, int format)
{
    printf("\n\n --- Arvore Binaria ---\n");
    if(!t.root){
         printf("Árvore vazia.\n\n");
         return;
    }else printNode(t.root, format);
    printf("\n\nFim da arvore.\n---------------------------\n");
}

/**
 * Imprime o valor do nó em ordem crescente.
 */ 
void printNode(Node * n, int format)
{
    if(n){
        if(format == 1){
            printNode(n->left, format);
            printf("\n-------- \n");
            printf("\n---%02d--- \n", n->data);
            if(n->left) printf("%02d<-", n->left->data);
            else printf("--le");
            if(n->right) printf("->%02d", n->right->data);
            else printf("af--");
            printNode(n->right, format);
        }else{
            printNode(n->left, format);
            printf(" %02d ", n->data);
            printNode(n->right, format);
        }
    }
}


/**
 * Procura um elemento na árvore t.
 */ 
Node * search(Tree *t, int data)
{
    Node *n = t->root;
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

/**
 * Retorna 1 se o nó é folha ou 0 caso contrário
 */ 
int leaf(Node *n)
{
    if(n->left || n->right) return 0;
    return 1;
}