#include <stdio.h>
#include <stdlib.h>
#include "lib/btree.h"

int main(int argc, char ** argv[])
{
    Tree t;
    init(&t);
    int di=0, d;
    int da[16] = {10,22,13,41,15,0,2,9,52,14,24,32,80,7,4,27};
    printf("\n  Tipo: %s - %d elementos \n", tree_type(&t), t.count);
    while(di<16){
        printf("\n\n--Próximo: %d", da[di]);
        getchar();
        insert(&t, da[di]);
        print_t(t, 0);
        di++;
    }

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
return 0;

}


