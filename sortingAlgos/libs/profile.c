#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "utils.h"
#include "fileManager.h"
#include "selection.h"
#include "insertion.h"
#include "merge.h"
#include "quicksort.h"
#include "profile.h"

#define null NULL
#define true 1
#define false 0
#define _ARRAY_BASE_SIZE_ 13

int __mult_factor= 3;
int __array_base = 13;

int profile()
{
        setProfilingBase();

        double count=1;

        Data cmp;
        cmp.changes=0;
        cmp.cmp=0;
        char name[50];

        cmp.start = clock();

        printf("\n\t---Profiling Dual Pivot Quick Sort---\n");
        profileDualQuickSort(false);


        printf("\n\t---Profiling Quick Sort---\n");
        profileQuickSort(false);


        printf("\n\t---Profiling Merge Sort---\n");
        profileMergeSort(false);


        printf("\n\t---Profiling Insertion Sort---\n");
        profileInsertionSort(false);


        printf("\n\t---Profiling Selection Sort---\n");
        profileSelectionSort(false);

        cmp.end = clock();
        cmp.diff[0] =  (double)(cmp.end - cmp.start) / CLOCKS_PER_SEC;

        printf("\n\n--- Tempo total de execução do teste: %lfs\n\n", cmp.diff[0]);

    return true;
}

void profileDualQuickSort(int worstcase)
{
    int i, j;
    int size;
    Data cmp, a;
    for(i=0; i<__mult_factor; i++){
            
            size = pow(__array_base, i+1);
            int v[size];
            printf("\nProfiling %d elementos\n", size);

            for(j=0; j<30; j++){   

                cmp.changes=0;
                cmp.cmp=0;
                randomArray(v, size);
                write(v, size, "quick_sort_arrays_unordered.txt");

                worstcase ? dualPivotQuickSort(v, 0, size, &a): true;

                int diff;
                cmp.start = clock();

                dualPivotQuickSort(v, 0, size, &cmp);
                cmp.end = clock();
                diff = (double)(cmp.end - cmp.start);
                cmp.vdiff[j] = diff;


                write(v, size, "dual_pivot_arrays_ordered.txt");
            }

            cmp.tChanges[i] = cmp.changes;
            cmp.cmpt[i] = cmp.cmp;
            cmp.size[i] = size;
            cmp.diff[i] = avg(cmp.vdiff, 30);
        }
        char name[40] = "Dual Pivot QuickSort Results";
        printProfilingData(name, &cmp);
}

void profileQuickSort(int worstcase)
{
    int i, j;
    int size;
    Data cmp, a;

    for(i=0; i<__mult_factor; i++){
            
            size = pow(__array_base, i+1);
            int v[size];
            printf("\nProfiling %d elementos\n", size);

            for(j=0; j<30; j++){                
                
                cmp.changes=0;
                cmp.cmp=0;

                randomArray(v, size);
                write(v, size, "quick_sort_arrays_unordered.txt");

                worstcase ? dualPivotQuickSort(v, 0, size, &a): true;

                
                int diff;
                cmp.start = clock();

                quickSort(v, 0, size, &cmp);
                cmp.end = clock();
                diff = (double)(cmp.end - cmp.start);
                cmp.vdiff[j] = diff;


                write(v, size, "dual_pivot_arrays_ordered.txt");
            }


            cmp.tChanges[i] = cmp.changes;
            cmp.cmpt[i] = cmp.cmp;
            cmp.size[i] = size;
            cmp.diff[i] = avg(cmp.vdiff, 30);
        }
        char name[50] = "Quick Sort Results RANDOM";

        if(worstcase){
            strcpy(name,"Quick Sort Results ORDENADO");
        }
        printProfilingData(name, &cmp);
}

void profileMergeSort(int worstcase)
{
    int i, j;
    int size;
    Data cmp, a;

    for(i=0; i<__mult_factor; i++){
            
            size = pow(__array_base, i+1);
            int v[size];
            printf("\nProfiling %d elementos\n", size);

            for(j=0; j<30; j++){                
                
                cmp.changes=0;
                cmp.cmp=0;

                randomArray(v, size);
                write(v, size, "merge_sort_arrays_unordered.txt");
                worstcase ? dualPivotQuickSort(v, 0, size, &a): true;

                

                int diff;
                cmp.start = clock();

                mergeSort(v, 0, size, &cmp);
                cmp.end = clock();
                diff = (double)(cmp.end - cmp.start);
                cmp.vdiff[j] = diff;


                write(v, size, "merge_sort_arrays_ordered.txt");
            }


            cmp.tChanges[i] = cmp.changes;
            cmp.cmpt[i] = cmp.cmp;
            cmp.size[i] = size;
            cmp.diff[i] = avg(cmp.vdiff, 30);
        }
        char name[50] = "Merge Sort Results RANDOM";

        if(worstcase){
            strcpy(name,"Merge Sort Results ORDENADO");
        }
        printProfilingData(name, &cmp);
}

void profileInsertionSort(int worstcase)
{
    int i, j;
    int size;
    Data cmp, a;
   
    for(i=0; i<__mult_factor; i++){
            
            size = pow(__array_base, i+1);
            int v[size];
            printf("\nProfiling %d elementos\n", size);

            for(j=0; j<30; j++){                
                
                cmp.changes=0;
                cmp.cmp=0;

                randomArray(v, size);
                write(v, size, "insertion_sort_arrays_unordered.txt");
                worstcase ? dualPivotQuickSort(v, 0, size, &a): true;

                

                int diff;
                cmp.start = clock();

                insertionSort(v, size, &cmp);
                cmp.end = clock();
                diff = (double)(cmp.end - cmp.start);
                cmp.vdiff[j] = diff;


                write(v, size, "insertion_sort_arrays_ordered.txt");
            }


            cmp.tChanges[i] = cmp.changes;
            cmp.cmpt[i] = cmp.cmp;
            cmp.size[i] = size;
            cmp.diff[i] = avg(cmp.vdiff, 30);
        }
        char name[50] = "Insertion Sort Results RANDOM";


        if(worstcase){
            strcpy(name,"Insertion Sort Results ORDENADO");
        }
        printProfilingData(name, &cmp);
}

void profileSelectionSort(int worstcase)
{
    int i, j;
    int size;
    Data cmp, a;

    for(i=0; i<__mult_factor; i++){
            
            size = pow(__array_base, i+1);
            int v[size];
            printf("\nProfiling %d elementos\n", size);

            for(j=0; j<30; j++){
                cmp.changes=0;
                cmp.cmp=0;

                randomArray(v, size);
                write(v, size, "insertion_sort_arrays_unordered.txt");
                worstcase ? dualPivotQuickSort(v, 0, size, &a): true;

               

                int diff;
                cmp.start = clock();

                selectionSort(v, size, &cmp);
                cmp.end = clock();
                diff = (double)(cmp.end - cmp.start);
                cmp.vdiff[j] = diff;


                write(v, size, "insertion_sort_arrays_ordered.txt");
            }


            cmp.tChanges[i] = cmp.changes;
            cmp.cmpt[i] = cmp.cmp;
            cmp.size[i] = size;
            cmp.diff[i] = avg(cmp.vdiff, 30);
        }

        char name[50] = "Selection Sort Results RANDOM";

        if(worstcase){
            strcpy(name, "Selection Sort Results ORDENADO");
        }
        printProfilingData(name, &cmp);
}

void printProfilingData(char name[50], Data * cmp)
{
    int i;
    printf("\n\n------------------------------ %s ------------------------------\n\n", name);
    
    for(i=0; i<__mult_factor; i++){
        
        printf("Tamanho do vetor: %d\n\tExecucoes: 30\n", cmp->size[i]);
        printf("\tComparacoes: %d\n", cmp->cmpt[i]);
        printf("\tTrocas: %d\n", cmp->tChanges[i]);
        printf("\tTempo medio: %.0lf ticks\n\n", cmp->diff[i]);

    }

    printf("\n\n-------------------------------------------------------------------------\n\n");

    writeProfilingResults(cmp, name);

}

int worstCaseProfile()
{
        setProfilingBase();

        double count=1;

        Data cmp;
        cmp.changes=0;
        cmp.cmp=0;
        char name[50];

        cmp.start = clock();

        printf("\n\t---Profiling Dual Pivot Quick Sort PIOR CASO---\n");
        profileDualQuickSort(true);


        printf("\n\t---Profiling Quick Sort---\n");
        profileQuickSort(true);


        printf("\n\t---Profiling Merge Sort---\n");
        profileMergeSort(true);


        printf("\n\t---Profiling Insertion Sort---\n");
        profileInsertionSort(true);


        printf("\n\t---Profiling Selection Sort---\n");
        profileSelectionSort(true);

        cmp.end = clock();
        cmp.diff[0] =  (double)(cmp.end - cmp.start) / CLOCKS_PER_SEC;

        printf("\n\n--- Tempo total de execução do teste: %lfs\n\n", cmp.diff[0]);

    return true;
}

void setProfilingBase()
{
    while(true){
        printf("\t\n Digite o tamanho base do vetor, entre 5 e 14:");
        scanf("%d", &__array_base);
        if(__array_base >= 5 && __array_base <= 14) break;
    }
    while(true){
        printf("\t\n Digite o numero de variações de tamanho para um vetor de até %d^n elementos, entre 2 e 5:", __array_base);
        scanf("%d", &__mult_factor);
        if(__mult_factor >= 2 && __mult_factor <= 5) break;
    }
}