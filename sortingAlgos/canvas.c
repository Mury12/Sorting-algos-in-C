#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "canvas.h"
#include "libs/utils.h"
#include "libs/fileManager.h"
#include "libs/selection.h"
#include "libs/insertion.h"
#include "libs/merge.h"
#include "libs/quicksort.h"

#define null NULL
#define true 1
#define false 0

int start()
{
    printf("\n\n");
    printf("\t-------------------------------\n");
    printf("\t----ALGORITMOS DE ORDENACAO----\n");
    printf("\t-------------------------------\n");
    
    printf("\n\n\t ESCOLHA UMA OPCAO: \n\n");

    printf("\t-------------------------------\n");
    printf("\t-----------ITERATIVOS----------\n");
    printf("\t-------------------------------\n");

    printf("\t 1 - BUBBLE SORT \n");
    printf("\t 2 - SMART BUBBLE \n");
    printf("\t 3 - SELECTION SORT \n");
    printf("\t 4 - INSERTION SORT \n\n");
    
    printf("\t-------------------------------\n");
    printf("\t-----------RECURSIVOS----------\n");
    printf("\t-------------------------------\n");

    printf("\t 5 - MERGE SORT \n");
    printf("\t 6 - QUICK SORT \n");
    printf("\t 7 - QUICK SORT DOIS PIVOS \n\n");

    return body();
}

int choseSorts()
{

    int choice;
    printf("\t_");
    scanf("%d", &choice);

    return choice < 1 || choice > 7 ? false: choice;

}

int body()
{
    int choice = choseSorts();

    while(!choice){
        printf("\n\tOPCAO INVALIDA! DIGITE NOVAMENTE: ");
        choice = choseSorts();
    }

    char mobs[7][30] = {
        "BUBBLE SORT", "SMART BUBBLE", "SELECTION SORT", 
        "INSERTION SORT", "MERGE SORT", "QUICK SORT", 
        "QUICK SORT DOIS PIVOS"
    };

    printf("\tVOCE ESCOLHEU %s.\n\n", mobs[choice-1]);

    int size;
    char filename[40];

    printf("\n Digite o nome do arquivo (default data.txt): ");
    scanf(" %s", filename);

//    createRandomValuesFile(filename);

    size = count(filename);
    
    if(!size){
        printf("ARQUIVO INVÁLIDO.");
        return false;
    }
    int v[size];

    read(v, filename);
    
    return sort(choice, v, size);

    printf("\n\nARQUIVO ORDENADO A PARTIR DO ALGORITMO %s\n\n", mobs[choice-1]);

}

int sort(int choice, int * v, int size)
{

        switch(choice){
            
            case 1:

                break;
            case 2:

                break;
            case 3:
                selectionSort(v, size);
                break;
            case 4:
                insertionSort(v, size);
                break;
            case 5:
                mergeSort(v, 0, size);
                break;
            case 6:
                quickSort(v, 0, size);
                break;
            case 7:
                dualPivotQuickSort(v, 0, size);
                break;
            
        }

    printv(v, size);

return true;
}