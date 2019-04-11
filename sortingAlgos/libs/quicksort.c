#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
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
                swap(&v[i], &v[pos]);
            }
        }
    }

    swap(&v[start], &v[pos]);

    return pos;
}

void dualPivotQuickSort(int v[], int low, int high)
{
    if(low < high){
        /**
         * @var int lp is the left pivot
         * @var int rp is the right pivot
         */
        int lp, rp;

        rp = partition(v, low, high, &lp);
        dualPivotQuickSort(v, low, lp-1);
        dualPivotQuickSort(v, lp+1, rp-1);
        dualPivotQuickSort(v, rp+1, high);
    }
}

int partition(int v[], int low, int high, int *lp)
{
    /**
     * Swap the first and last elements if first is greater than the last element.
     */ 
    if(v[low] > v[high]){
        swap(&v[low], &v[high]);
    }

    /**
     * @var int j isthe left pivot index.
     */
    int j = low + 1;

    /**
     * @var int g is the right pivot index.
     * @var int k is the first element behind the left pivot.
     * @var int p is the left pivot.
     * @var int q is the right pivot.
     */ 
    int g = high - 1, k = low + 1, p = v[low], q = v[high];

    /**
     * While the left pivot position is less than right pivot position
     */ 
    while(k<=g){

        /**
         * Checks if element in next pivot position is lower than the element before then swap them.
         */ 
        if (v[k] < p){
            swap(&v[k], &v[j]);
            j++;
        }

        /**
         * If the k element isn't lower than the first comparison, checks if it's greater than the right pivot then,
         * locates right-to-left position to swap and g becomes the position before this new position.
         */ 
        else if(v[k] >= q){

            while(v[g] > q && k < g){
                g--;
            }
            swap(&v[k], &v[g]);
            g--;

            /**
             * Checks if the swapped v[k] element is lower than the current left pivot then swap them.
             */ 
            if(v[k] < p){
                swap(&v[k], &v[j]);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;

    swap(&v[low], &v[j]);
    swap(&v[high], &v[g]);
    /**
     * Indirectly returns the left global pivot position to lp by reference.
     */ 
    *lp = j;

    /**
     * This is the current left global pivot position. 
     */
    return g;
}