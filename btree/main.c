#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libs/btree.h"
#include "libs/list.h"
#include "libs/hashtable.h"

void main()
{
    Hashtable h;
    Tree t;

    //ARVORE
    init(&t);

    push(&t, 10);
    push(&t, 20);
    push(&t, 5);
    push(&t, 7);
    push(&t, 6);


    printTree(t, 1);
    printTree(t, 0);

    //printTree(t, 0);
    printTree(t, 1);
    printTree(t, 0);

    ///HASHTABLE
   /* initTable(&h);

    int i;

    for(i = 0; i <= 50; i++){
        pushHashtable(&h, i);
    }

    printh(h);
    removeValue(&h, 0);
    printh(h);*/

}