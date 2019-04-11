#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/utils.h"
#include "libs/fileManager.h"
#include "libs/selection.h"
#include "libs/insertion.h"
#include "libs/merge.h"
#include "libs/quicksort.h"

#define null NULL
#define true 1
#define false 0

int main() 
{

    int size;
    char filename[40] = "data.txt";
    // printf("\n Digite o nome do arquivo (deixe em branco para data.txt): ");
    // scanf(" %s", filename);

    if(strcmp(filename, "")) strcpy(filename, "data.txt");

    createRandomValuesFile(filename);

    size = count(filename);
    int v[size];

    read(v, filename);
    
    printv(v, size);

    dualPivotQuickSort(v, 0, size);

    printv(v, size);

    return true;
}

