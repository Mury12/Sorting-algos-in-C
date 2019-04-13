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
    
    for(i = start+1; i < end; i++){
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

void dualPivotQuickSort(int v[], int left, int right, Data *cmp)
{
    if(left < right){
        /**
         * @var int lp é o pivô da esquerda
         * @var int rp é o pivô da direita
         */
        int lp, rp;

        rp = splitArray(v, left, right, &lp, cmp);
        dualPivotQuickSort(v, left, lp-1, cmp);
        dualPivotQuickSort(v, lp+1, rp-1, cmp);
        dualPivotQuickSort(v, rp+1, right, cmp);
    }
}

int splitArray(int v[], int left, int right, int *lp, Data * cmp)
{
    /**
     * Compara o primeiro e último elemento e os troca
     */ 
    if(v[left] > v[right]){
        swap(&v[left], &v[right], cmp);
    }
    cmp->cmp++;

    /**
     * @var int j é o indice do pivô da esquerda
     */
    int j = left + 1;

    /**
     * @var int g is the right pivot index.
     * @var int k is the first element behind the left pivot.
     * @var int p é o pivo da esquerda.
     * @var int q é o pivô da direita.
     */ 
    int g = right - 1, k = left + 1, p = v[left], q = v[right];

    /**
     * Continua até que os pivôs da esquerda e direita se encontrem
     */ 
    while(k<=g){

        /**
         * Verifica se o elemento n v[k] é menor que o pivô da esquerda
         */
        if (v[k] < p){
            swap(&v[k], &v[j], cmp);
            j++;
        }

        /**
         * Se o elemento v[k] não for menor que o pivô da esquerda, checa se é maior que o pivô da direita.
         */ 
        else if(v[k] >= q){
            while(v[g] > q && k < g){
                g--;
                cmp->cmp++;
            }
            swap(&v[k], &v[g], cmp);
            g--;

            /**
             * Verifica se o elemento trocado v[k] é menor que o atual pivô e os troca.
             */ 
            if(v[k] < p){
                swap(&v[k], &v[j], cmp);
                j++;
            }
            cmp->cmp++;
        }
        cmp->cmp+=2;
        k++;
    }
    j--;
    g++;

    swap(&v[left], &v[j], cmp);
    swap(&v[right], &v[g], cmp);
    /**
     * Retorna a posição do pivô da esquerda por referência
     */ 
    *lp = j;

    /**
     * Retorna a posição a posição do pivô da direita
     */
    return g;
}