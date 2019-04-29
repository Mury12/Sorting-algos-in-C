
#ifndef PROFILE_H
#define PROFILE_H
#include "utils.h"

/**
 * Administra o profiling dos algoritmos
 */
int profile();

/**
 * Administra o profiling no pior caso do quick sort, sendo ordenado.
 */ 
int worstCaseProfile();

/**
 * Realiza um teste com o Quick Sort de 2 pivos e guarda o resultado em um arquivo
 */ 
void profileDualQuickSort(int worstcase);

/**
 * Realiza um teste com o Quick Sort e guarda o resultado em um arquivo
 */ 
void profileQuickSort(int worstcase);

/**
 * Realiza um teste com o Merge Sort e armazena em um arquivo.
 */ 
void profileMergeSort(int worstcase);


/**
 * Realiza um teste com o Insertion Sort e armazena em um arquivo.
 */ 
void profileInsertionSort(int worstcase);


/**
 * Realiza um teste com o Selection Sort e armazena em um arquivo.
 */ 
void profileSelectionSort(int worstcase);


/**
 * Escreve na tela os dados do teste.
 */ 
void printProfilingData(char name[30], Data * cmp);

void setProfilingBase();

#endif /* PROFILE */
