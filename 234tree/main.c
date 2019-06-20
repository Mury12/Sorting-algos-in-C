#include <stdio.h>
#include <stdlib.h>
#include "lib/btree.h"

void main()
{
    Tree t;
    init(&t);
    int d;

    printf("\n  Tipo: %s - %d elementos \n", tree_type(&t), t.count);

    while(1){
        scanf("%d", &d);
        insert(&t, d);
    }

    // insert(&t, 11);
    // insert(&t, 8);

    // printf("\n  Raiz: |%02d|%02d|%02d|\n", t.root->data[0], t.root->data[1], t.root->data[2]);


}


