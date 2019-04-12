#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "selection.h"
#define null NULL
#define true 1
#define false 0
/**
 * 
 * @param v
 * @param size
 */
void selectionSort(int v[], int size, Data * cmp)
{
    int j=0, l, i=0, aux;
        
    for(j = 0; j<size; j++){
        l = j;
        for(i=j+1; i<size; i++){
            
            if(v[i] < v[l] && v[i] != v[l]){
                l = i;
                cmp->cmp++;
            }
            
        }
        swap(&v[l], &v[j], cmp);
        
    }    
}
