
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

    /**
     * Tempos de início e fim de um único teste
     */
    clock_t start, end;

    /**
     * Vetor com o tamanho  dos vetores testados
     */
    int size[5];
    /**
     * Vetor com o total de comparações para cada tamanho de vetor
     */
    int cmpt[5];
    /**
     * Vetor com o total de trocas para cada tamanho de vetor
     */
    int tChanges[5];
    /**
     * Vetor com a média de tempo para cada tamanho de vetor
     */
    double diff[5];
    /**
     * Vetor com os tempos da execução de um único teste
     */
    double vdiff[30];
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
 * Cria um vetor aleatório com os parametros indicados.
 */
void randomArray(int *v, int size);

/**
 * Tira a média de números em um vetor.
 */
double avg(double *v, int size);



#endif /* UTILS_H */