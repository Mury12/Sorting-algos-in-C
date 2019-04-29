#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "merge.h"
#define null NULL
#define true 1
#define false 0

void merge(int v[], int left, int mid, int right, Data * cmp)
{
    int i, j, k;
    int lsize = mid - left + 1;
    int rsize = right - mid;

    int l[lsize],  r[rsize];

    for (i=0; i<lsize; i++){
        l[i] = v[left+i];
    }

    for (i=0; i<rsize; i++){
        r[i] = v[mid+1+i];
    }

    i = j = 0;
    k = left;
    
    while(i < lsize && j < rsize){
        if(l[i] <= r[j]){
            v[k] = l[i];
            cmp->changes++;
            i++;
        }else{
            v[k] = r[j];
            cmp->changes++;
            j++;
        }
        k++;
        cmp->cmp++;
    }

    while(i < lsize){
        v[k] = l[i];
        i++;k++;
    }

    while(j < rsize){
        v[k] = r[j];
        j++;
        k++;
    }

}

void mergeSort(int v[], int left, int right, Data *cmp)
{
    int mid = (left+right)/2;

    if(left < right){
        cmp->cmp++;

        mergeSort(v, left, mid, cmp);
        mergeSort(v,mid+1, right, cmp);

        merge(v, left, mid, right, cmp);

    }
}