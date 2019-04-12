
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define null NULL
#define true 1
#define false 0




void printv(int v[], int size)
{
    int i;
    printf("\n\n");
    
    for(i = 0; i < size; i++){
        printf(" %d ", v[i]);
    }
        printf("\n\n");
}


void swap(int *a, int *b, Data * cmp)
{
    int aux = *a;
    *a = *b;
    *b = aux;

    cmp->changes++;
}
