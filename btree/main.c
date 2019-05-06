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
    int c;
    //ARVORE
    init(&t);

    while(1){
        scanf("%d", &c);
        push(&t, c);
        printTree(t, 1);
    }

    //printTree(t, 0);

    //printTree(t, 0);
    //printTree(t, 1);
    //printTree(t, 0);

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