#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libs/btree.h"
#include "libs/list.h"
#include "libs/hashtable.h"

void main()
{
    Hashtable t;

    initTable(&t);

    int i;

    for(i = 0; i <= 50; i++){
        pushHashtable(&t, i);
    }

    printh(t);
    removeValue(&t, 47);
    printh(t);

}