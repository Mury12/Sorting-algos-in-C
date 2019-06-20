#include <stdlib.h>
#include <stdio.h>
#include "libs/tree.h"

void main ()
{
    Tree t;
    int in;
    init (&t);

    while(in != -1){
        printf("\n");
        scanf("%d", &in);
        insert(&t, in);
        print_t(t, 1);
    }


    // Node * n = next(t.root);
    // printf("\n\n Buscando nó antecessor..\n Pai: %d Valor: %d \n\n", n->parent->data, n->data);
    return;
}