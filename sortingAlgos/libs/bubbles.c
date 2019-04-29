#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "bubbles.h"

#define null NULL
#define true 1
#define false 0

void bubbleSort(int * v, int size, Data * cmp)
{
    int i, j;

    for(i=0; i<size; i++){
        for(j=0; j<size-1; j++){
            if(v[j]>v[j+1]){
                swap(&v[j], &v[j+1], cmp);
            }
            cmp->cmp++;
        }
    }

}

void smartBubble(int * v, int size, Data * cmp)
{
    int i, j, c;

    for(i=0; i<size; i++){
        c=0;
        for(j=size-1; j>=i; j--){
            if(v[j]>v[j+1]){
                swap(&v[j], &v[j+1], cmp);
                c++;
            }
        cmp->cmp++;
        }
        
        if(c==0) break;
        
    }
}
