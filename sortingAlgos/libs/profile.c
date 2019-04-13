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
#define _MAX_MULT_VALUE_ 3

int profile()
{
        double count=1;

        Data cmp;
        cmp.changes=0;
        cmp.cmp=0;
        char name[30];

        cmp.start = clock();

        printf("\n\t---Profiling Dual Pivot Quick Sort---\n");
        profileDualQuickSort();


        printf("\n\t---Profiling Quick Sort---\n");
        profileQuickSort();


        printf("\n\t---Profiling Merge Sort---\n");
        profileMergeSort();


        printf("\n\t---Profiling Insertion Sort---\n");
        profileInsertionSort();


        printf("\n\t---Profiling Selection Sort---\n");
        profileSelectionSort();

        cmp.end = clock();
        cmp.diff[0] =  (double)(cmp.end - cmp.start) / CLOCKS_PER_SEC;

        printf("\n\n--- Tempo total de execução do teste: %lfs\n\n", cmp.diff[0]);

    return true;
}

void profileDualQuickSort()
{
    int i, j;
    int size;
    Data cmp;
    for(i=0; i<_MAX_MULT_VALUE_; i++){
            
            size = pow(15, i+1);
            int v[size];
            printf("\nProfiling %d elementos\n", size);

            for(j=0; j<30; j++){   

                cmp.changes=0;
                cmp.cmp=0;
                randomArray(v, size);

                int diff;
                cmp.start = clock();

                dualPivotQuickSort(v, 0, size, &cmp);
                cmp.end = clock();
                diff = (double)(cmp.end - cmp.start);
                cmp.vdiff[j] = diff;


                write(v, size, "dual_pivot_arrays.txt");
            }

            cmp.tChanges[i] = cmp.changes;
            cmp.cmpt[i] = cmp.cmp;
            cmp.size[i] = size;
            cmp.diff[i] = avg(cmp.vdiff, 30);
        }
        char name[40] = "Dual Pivot QuickSort Results";
        printProfilingData(name, &cmp);
}

void profileQuickSort()
{
    int i, j;
    int size;
    Data cmp;

    for(i=0; i<_MAX_MULT_VALUE_; i++){
            
            size = pow(15, i+1);
            int v[size];
            printf("\nProfiling %d elementos\n", size);

            for(j=0; j<30; j++){                
                
                cmp.changes=0;
                cmp.cmp=0;

                randomArray(v, size);

                write(v, size, "dual_pivot_arrays_unordered.txt");
                
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
        char name[30] = "Quick Sort Results RANDOM";
        printProfilingData(name, &cmp);
}

void profileMergeSort()
{
    int i, j;
    int size;
    Data cmp;

    for(i=0; i<_MAX_MULT_VALUE_; i++){
            
            size = pow(15, i+1);
            int v[size];
            printf("\nProfiling %d elementos\n", size);

            for(j=0; j<30; j++){                
                
                cmp.changes=0;
                cmp.cmp=0;

                randomArray(v, size);
               
                write(v, size, "merge_sort_arrays_unordered.txt");

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
        char name[30] = "Merge Sort Results  RANDOM";
        printProfilingData(name, &cmp);
}

void profileInsertionSort()
{
    int i, j;
    int size;
    Data cmp;
   
    for(i=0; i<_MAX_MULT_VALUE_; i++){
            
            size = pow(15, i+1);
            int v[size];
            printf("\nProfiling %d elementos\n", size);

            for(j=0; j<30; j++){                
                
                cmp.changes=0;
                cmp.cmp=0;

                randomArray(v, size);
                
                write(v, size, "insertion_sort_arrays_unordered.txt");

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
        char name[30] = "Insertion Sort Results  RANDOM";
        printProfilingData(name, &cmp);
}

void profileSelectionSort()
{
    int i, j;
    int size;
    Data cmp;

    for(i=0; i<_MAX_MULT_VALUE_; i++){
            
            size = pow(15, i+1);
            int v[size];
            printf("\nProfiling %d elementos\n", size);

            for(j=0; j<30; j++){
                cmp.changes=0;
                cmp.cmp=0;

                randomArray(v, size);
                
                write(v, size, "insertion_sort_arrays_unordered.txt");

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

        char name[30] = "Selection Sort Results  RANDOM";
        printProfilingData(name, &cmp);
}

void printProfilingData(char name[30], Data * cmp)
{
    int i;
    printf("\n\n------------------------------ %s ------------------------------\n\n", name);
    
    for(i=0; i<_MAX_MULT_VALUE_; i++){
        
        printf("Tamanho do vetor: %d\n\tExecucoes: 30\n", cmp->size[i]);
        printf("\tComparacoes: %d\n", cmp->cmpt[i]);
        printf("\tTrocas: %d\n", cmp->tChanges[i]);
        printf("\tTempo medio: %.0lf ticks\n\n", cmp->diff[i]);

    }

    printf("\n\n-------------------------------------------------------------------------\n\n");

    writeProfilingResults(cmp, name);

}
