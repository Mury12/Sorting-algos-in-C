
#ifndef QUICKSORT_H
#define QUICKSORT_H
/**
 * Estado inicial do método Quick Sort. Realiza a divisão dos vetores em pequenas seções.
 * @param int v[] array to sort
 * @param int start first element
 * @param int end last element
 * @param cmp é o ponteiro para a estrutura utilizada para contabilizar métricas.
 */ 
void quickSort(int v[], int start, int end, Data * cmp);

/**
 * Ordena uma seção de números e retorna a posição do pivô.
 * @param int v[] vetor para ordenar.
 * @param int start primeiro elemento da seção.
 * @param int end último elemento da seção
 * @param cmp é o ponteiro para a estrutura utilizada para contabilizar métricas.
 * @returns a posição do atual pivô
 */ 
int arraySplit(int v[], int start, int end, Data * cmp);

/**
 * Estado inicial do método Quick Sort. Realiza a divisão dos vetores em pequenas seções.
 * O método de dois pivôs divide o vetor em três partes ao invés de duas.
 * @param int v[] vetor para ordenar
 * @param int left é o primeiro elemento do vetor
 * @param int right é o último elemento do vetor
 * @param cmp é o ponteiro para a estrutura utilizada para contabilizar métricas.
 */ 
void dualPivotQuickSort(int v[], int left, int right, Data * cmp);

/**
 * Ordena uma seção de números e retorna a posição dos pivôs.
 * @param int v[] vetor para ordenar.
 * @param int left primeiro elemento da seção.
 * @param int right último elemento da seção
 * @param int *lp ponteiro para o pivô da esquerda
 * @param cmp é o ponteiro para a estrutura utilizada para contabilizar métricas.
 * @returns a posição do atual pivô
 */ 
int splitArray(int v[], int left, int right, int *lp, Data * cmp);

#endif /* QUICKSORT_H */

