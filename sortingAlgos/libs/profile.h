
#ifndef PROFILE_H
#define PROFILE_H
#include "utils.h"

/**
 * Administra o profiling dos algoritmos
 */
int profile();

/**
 * Realiza um teste com o Quick Sort de 2 pivos e guarda o resultado em um arquivo
 */ 
void profileDualQuickSort();

/**
 * Realiza um teste com o Quick Sort e guarda o resultado em um arquivo
 */ 
void profileQuickSort();

/**
 * Realiza um teste com o Merge Sort e armazena em um arquivo.
 */ 
void profileMergeSort();


/**
 * Realiza um teste com o Insertion Sort e armazena em um arquivo.
 */ 
void profileInsertionSort();


/**
 * Realiza um teste com o Selection Sort e armazena em um arquivo.
 */ 
void profileSelectionSort();


/**
 * Escreve na tela os dados do teste.
 */ 
void printProfilingData(char name[30], Data * cmp);
#endif /* PROFILE */
