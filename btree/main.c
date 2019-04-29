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

    push(&t, 25);
    push(&t, 23);
    push(&t, 21);
    push(&t, 22);
    push(&t, 24);
    push(&t, 27);
    push(&t, 29);
    push(&t, 31);
    push(&t, 26);
    push(&t, 28);
    push(&t, 30);

    printTree(t, 0);
    pop(&t, 3);
    //printTree(t, 0);
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