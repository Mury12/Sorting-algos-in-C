#include <stdio.h>
#include <stdlib.h>
#include "selection.h"
#define null NULL
#define true 1
#define false 0

void insertionSort(int v[], int size) {
    int aux, i, j;

    for (i = 1; i < size; i++) {
        j=i-1;
        aux = v[i];
        while(j>=0 && aux< v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;

    }
    printf("\n Ordered by insertion Sort");

}