#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#define null NULL

l_Node * nodeAlloc(int p)
{
    l_Node *n;
    
    n = malloc(sizeof(l_Node));

    if(n){
        n->p = p;
        n->next = null;
    }
    return n;
}

void initl(List * l)
{
    l->first = null;
}

void pushList(List * l, int p)
{
    l_Node *aux, *prev, *n;

    n = nodeAlloc(p);

    if(n){
        aux = l->first;
        prev = null;
        
        while(aux && aux->p < p){
            prev = aux;
            aux = aux->next;
        }
        if(!prev){
            n->next = l->first;
            l->first = n;
        }else{
            n->next = aux;
            prev->next = n;
        }
    }
}

void removeList(List * l, int p)
{
    l_Node * aux, *prev, *n;

    aux = l->first;

    while(aux && aux->p != p){
        prev = aux;
        aux = aux->next;
    }    

    if(aux->next && prev){
        prev->next = aux->next;
        aux = null;
        free(aux);

        printf("\n Removido node %d.\n", p);
    }else{
        if(!aux->next && prev){
            prev->next = null;
            aux = null;
            free(aux);
            printf("\n Removido node %d.\n", p);
        }else{
            printf("\n Valor %d nao encontrado.\n", p);
        }
    }
    

}

void printl(List l)
{
    l_Node *prev, *n, *min;
    n = min = l.first;
    prev = null;
    
    while(n){
        printf(" %d ", n->p);
        prev = n;
        n = n->next;
    }

}
