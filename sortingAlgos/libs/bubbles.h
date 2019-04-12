#ifndef BUBBLES_H
#define BUBBLES_H

/**
 * Ordena um vetor pelo método da bolha comum.
 * @param v é o ponteiro para o vetor a ser ordenado
 * @param size é o tamanho do vetor
 * @param cmp é o ponteiro para a estrutura utilizada para contabilizar métricas.
 */ 
void bubbleSort(int v[], int size, Data * cmp);

/**
 * Ordena um vetor pelo método da bolha comum.
 * @param v é o ponteiro para o vetor a ser ordenado
 * @param size é o tamanho do vetor
 * @param cmp é o ponteiro para a estrutura utilizada para contabilizar métricas.
 */ 
void smartBubble(int v[], int size, Data * cmp);

#endif /* BUBBLES_H */

