#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "canvas.h"
#include "libs/utils.h"
#include "libs/fileManager.h"
#include "libs/bubbles.h"
#include "libs/selection.h"
#include "libs/insertion.h"
#include "libs/merge.h"
#include "libs/quicksort.h"

#define null NULL
#define true 1
#define false 0

int start()
{
    // navigation();
    profile();
    // return body();
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

    // createRandomValuesFile(filename);



    size = count(filename);
    
    if(!size){
        printf("ARQUIVO INVÁLIDO.");
        return false;
    }
    /**
     * Aloca o vetor com o tamanho necessário
     */ 
    int *v = (int*)malloc(size * sizeof(int));
    
    read(v, filename);
    
    
    if(sort(choice, v, size)){
        printf("\n\nARQUIVO ORDENADO A PARTIR DO ALGORITMO %s\n\n", mobs[choice-1]);
        return true;
    }
    return false;

}

int sort(int choice, int * v, int size)
{
        Data cmp;
        cmp.changes=0;
        cmp.cmp=0;
        cmp.start = clock();
        int diff = 0;
        printv(v, size);        

        switch(choice){
            
            case 1:
                bubbleSort(v, size, &cmp);
                break;
            case 2:
                smartBubble(v, size, &cmp);
                break;
            case 3:
                selectionSort(v, size, &cmp);
                break;
            case 4:
                insertionSort(v, size, &cmp);
                break;
            case 5:
                mergeSort(v, 0, size, &cmp);
                break;
            case 6:
                quickSort(v, 0, size, &cmp);
                break;
            case 7:
                dualPivotQuickSort(v, 0, size, &cmp);
                break;
        }
        
        cmp.end = clock();
        diff = (double)(cmp.end - cmp.start);


    printv(v, size);

    printf("Comparações: %lld\tTrocas: %lld\tTamanho do Vetor: %d\n", cmp.cmp, cmp.changes, size);
    printf("Tempo decorrido: %d ticks", diff);
    return true;
}

void navigation()
{    
    printf("\n\n");
    printf("\t|------------------------------------------------------------|\n");
    printf("\t|                  ALGORITMOS DE ORDENACAO                   |\n");
    printf("\t|-------------------------------|----------------------------|\n");
    printf("\t|          ITERATIVOS           |");
    printf(   "          RECURSIVOS        |\n");

    printf("\t|-------------------------------|----------------------------|\n");
    
    printf("\t|     1 - BUBBLE SORT\t ");
    printf("\t|     5 - MERGE SORT\t     |\n");
    printf("\t|     2 - SMART BUBBLE\t ");
    printf("\t|     6 - QUICK SORT\t     |\n");
    printf("\t|     3 - SELECTION SORT ");
    printf("\t|     7 - QUICK SORT 2 PIVOS |\n");
    printf("\t|     4 - INSERTION SORT");
    printf("\t|\t                     |\n");
    printf("\t--------------------------------------------------------------\n");
    printf("\n\n\t ESCOLHA UMA OPCAO: ");
}

int profile()
{
        double count=1;
        int i, j;
        int size;
        Data cmp;
        cmp.changes=0;
        cmp.cmp=0;

        for(i=0; i<5; i++){
            
            size = pow(15, i+1);
            int v[size];

            randomArray(v, size);

            for(j=0; j<30; j++){

                int diff;
                cmp.start = clock();

                mergeSort(v, 0, size, &cmp);

                cmp.end = clock();
                diff = (double)(cmp.end - cmp.start);
                cmp.vdiff[j] = diff;
            }

            cmp.tChanges[i] = cmp.changes;
            cmp.cmpt[i] = cmp.cmp;
            cmp.size[i] = size;
            cmp.diff[i] = avg(cmp.vdiff, 30);
        }

        char name[30] = "Quick Sort";
        printProfilingData(name, &cmp);

    return true;
}

double avg(double *v, int size)
{
    int i, c=0;

    for(i=0; i<size; i++){
        c+=v[i];
    }

    return (c/size);
}

void randomArray(int *v, int size)
{
    int i;
    srand(clock());
        for(i=0; i<size; i++){
            int val;    
            val = rand()%100;
            v[i] = val;
    }
}

void printProfilingData(char name[30], Data * cmp)
{
    int i;
    printf("\n\n------------------------------ %s ------------------------------\n\n", name);
    
    for(i=0; i<5; i++){
        
        printf("Tamanho do vetor: %d", cmp->size[i]);
        printf("\tComparacoes: %d\n", cmp->cmpt[i]);
        printf("\tTrocas: %d\n", cmp->tChanges[i]);
        printf("\tTempo medio: %0lf ticks\n\n", cmp->diff[i]);

    }

    printf("\n\n-------------------------------------------------------------------------\n\n");
}