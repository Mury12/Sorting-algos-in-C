
#ifndef UTILS_H
#define UTILS_H
#include <time.h>
 
struct Data{
    /**
     * @var cmp representa o número de comparações realizadas.
     */ 
    long long int cmp;
    /**
     * @var changes representa o número de trocas efetuadas
     */ 
    long long int changes;

    clock_t start, end;
    double diff;
};
/**
 * Estrutura que armazena as métricas de desempenho dos algorítmos.
 * @var cmp representa o número de comparações realizadas.
 * @var changes representa o número de trocas efetuadas
 */ 
typedef struct Data Data;

/**
 * Realiza a impressão de um array na tela
 * @param v[] array
 * @param size array size
 */
void printv(int v[], int size);
/**
 * Troca dois elementos de um vetor por referência
 * @param *a ponteiro para o primeiro valor
 * @param *b ponteiro para o segundo valor
 * @param cmp é o ponteiro para a estrutura de armazenamento de métricas
 */ 
void swap(int *a, int *b, Data * cmp);

#endif /* UTILS_H */