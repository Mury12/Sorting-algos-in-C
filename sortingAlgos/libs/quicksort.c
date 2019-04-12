#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "quicksort.h"
#define null NULL
#define true 1
#define false 0



void quickSort(int v[], int start, int end, Data * cmp)
{
    if(start < end){
        cmp->cmp++;
        int pivot = arraySplit(v, start, end, cmp);

        quickSort(v, start, pivot-1, cmp);
        quickSort(v, pivot+1, end, cmp);
    }
}

int arraySplit(int v[], int start, int end, Data * cmp)
{
    int pivot = v[start];
    int pos = start;
    int i, aux;
    
    for(i = start+1; i <= end; i++){
        if(v[i] < pivot){
            cmp->cmp++;
            pos++;
            if(i != pos){
                swap(&v[i], &v[pos], cmp);
            }
        }
    }

    swap(&v[start], &v[pos], cmp);
    
    return pos;
}

void dualPivotQuickSort(int v[], int low, int high, Data *cmp)
{
    if(low < high){
        /**
         * @var int lp is the left pivot
         * @var int rp is the right pivot
         */
        int lp, rp;

        rp = partition(v, low, high, &lp, cmp);
        dualPivotQuickSort(v, low, lp-1, cmp);
        dualPivotQuickSort(v, lp+1, rp-1, cmp);
        dualPivotQuickSort(v, rp+1, high, cmp);
    }
}

int partition(int v[], int low, int high, int *lp, Data * cmp)
{
    /**
     * Swap the first and last elements if first is greater than the last element.
     */ 
    if(v[low] > v[high]){
        swap(&v[low], &v[high], cmp);
    }

    /**
     * @var int j é o indice do pivô da esquerda
     */
    int j = low + 1;

    /**
     * @var int g is the right pivot index.
     * @var int k is the first element behind the left pivot.
     * @var int p é o pivo da esquerda.
     * @var int q é o pivô da direita.
     */ 
    int g = high - 1, k = low + 1, p = v[low], q = v[high];

    /**
     * Continua até que os pivôs da esquerda e direita se encontrem
     */ 
    while(k<=g){

        /**
         * Checks if element in next pivot position is lower than the element before then swap them.
         */
        cmp->cmp++; 
        if (v[k] < p){
            swap(&v[k], &v[j], cmp);
            j++;
        }

        /**
         * If the k element isn't lower than the first comparison, checks if it's greater than the right pivot then,
         * locates right-to-left position to swap and g becomes the position before this new position.
         */ 
        else if(v[k] >= q){
            cmp->cmp++;
            while(v[g] > q && k < g){
                g--;
                cmp->cmp++;
            }
            swap(&v[k], &v[g], cmp);
            g--;

            /**
             * Checks if the swapped v[k] element is lower than the current left pivot then swap them.
             */ 
            if(v[k] < p){
                swap(&v[k], &v[j], cmp);
                j++;
            }
            cmp->cmp++;
        }
        cmp->cmp++;
        k++;
    }
    j--;
    g++;

    swap(&v[low], &v[j], cmp);
    swap(&v[high], &v[g], cmp);
    /**
     * Indirectly returns the left global pivot position to lp by reference.
     */ 
    *lp = j;

    /**
     * This is the current left global pivot position. 
     */
    return g;
}