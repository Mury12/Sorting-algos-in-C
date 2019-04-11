
#include <stdio.h>
#include <stdlib.h>
#define null NULL
#define true 1
#define false 0



/**
 * Prints an array
 * @param int v[] array
 * @param int size array size
 */
void printv(int v[], int size)
{
    int i;
    printf("\n\n");
    
    for(i = 0; i < size; i++){
        printf(" %d ", v[i]);
    }
        printf("\n\n");
}

/**
 * Swaps two values by reference
 * @param int *a pointer to the first val
 * @param int *b pointer to the second val
 */ 
void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
