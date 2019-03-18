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
void sort(int v[], int size)
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