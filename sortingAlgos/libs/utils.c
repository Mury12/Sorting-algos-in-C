
#include <stdio.h>
#include <stdlib.h>
#define null NULL
#define true 1
#define false 0

/**
 * Prints a array
 * @param int v[] array
 * @param int size array size
 */
void printv(int v[], int size)
{
    int i;
    printf("\n\n");
    
    for(i = 0; i< size; i++){
        printf(" %d ", v[i]);
    }
        printf("\n\n");
}
