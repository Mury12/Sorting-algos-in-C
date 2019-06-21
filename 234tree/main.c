#include <stdio.h>
#include <stdlib.h>
#include "lib/btree.h"

void main()
{
    Tree t;
    init(&t);
    int d;

    printf("\n  Tipo: %s - %d elementos \n", tree_type(&t), t.count);
    insert(&t, 1);
    insert(&t, 2);
    insert(&t, 3);
    insert(&t, 4);
    insert(&t, 5);

    while(1){
        scanf(" %d", &d);
        insert(&t, d);
        printf("\n------\n");
        print_t(t, 0);
    }

    printf("\n\n\n");
    print_t(t, 0);

    // insert(&t, 11);
    // insert(&t, 8);

    // printf("\n  Raiz: |%02d|%02d|%02d|\n", t.root->data[0], t.root->data[1], t.root->data[2]);


}


