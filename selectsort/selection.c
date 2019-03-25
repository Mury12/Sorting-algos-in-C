#include <stdio.h>
#include <stdlib.h>
#include "selection.h"
#define null NULL
#define true 1
#define false 0
/**
 * 
 * @param v
 * @param size
 */
void selectionSort(int v[], int size)
{
    int j=0, l, i=0, aux;
        
    for(j = 0; j<size; j++){
        l = j;
        for(i=j+1; i<size; i++){
            
            
            if(v[i] < v[l] && v[i] != v[l]){
                l = i;
            }
            
        }
        aux = v[l];
        v[l] = v[j];
        v[j] = aux;

    }
        printf("\n Ordered by selection Sort");

    
}

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

void printv(int v[], int size)
{
    int i;
    printf("\n\n");
    
    for(i = 0; i< 5; i++){
        printf(" %d ", v[i]);
    }
        printf("\n\n");

}
