#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#define null NULL
#define true 1
#define false 0

void quickSort(int v[], int start, int end)
{
    if(start < end){
        
        int pivot = arraySplit(v, start, end);

        quickSort(v, start, pivot-1);
        quickSort(v, pivot+1, end);
    }
}

int arraySplit(int v[], int start, int end)
{
    int pivot = v[start];
    int pos = start;
    int i, aux;
    
    for(i = start+1; i <= end; i++){
        if(v[i] < pivot){
            pos++;
            if(i != pos){
                aux = v[i];
                v[i] = v[pos];
                v[pos] = aux;
            }
        }
    }
    aux = v[start];
    v[start] = v[pos];
    v[pos] = aux;
    return pos;
}