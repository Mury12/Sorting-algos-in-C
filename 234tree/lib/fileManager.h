#ifndef FILEMANAGER_H
#define FILEMANAGER_H

typedef struct Array{
    int *v, size;
}Array;

/**
 * Conta as ocorrências numéricas de um arquivo com um numero por linha
 * @param filename é o nome do arquivo (default data.txt)
 * @returnsa quantidade de ocorrências
 */
int count(char filename[]);

/**
 * Lẽ o arquivo de origem e armazena em um vetor.
 * @param v é o ponteiro para o vetor que será preenchido
 * @param filename é o nome do arquivo que será criado
 * @returnstrue ou false, além de preencher o vetor original.
 */
int read(int *v, char filename[]);

/**
 * Escreve um vetor em um arquivo.
 * @param v é o ponteiro para o vetor
 * @param filename é o nome do arquivo que será criado
 * @returnstrue ou false
 */
int write(int *v, int size, char filename[]);

/**
 * Cria um arquivo com o nome proposto com uma quantidade definida de números aleatórios, um por linha.
 * @param filename é o nome do arquivo a ser criado
 * @returnstrue ou false
 */
int * createRandomValuesFile(char filename[]);

// void writeProfilingResults(Data *cmp, char name[40]);


#endif /* FILEMANAGER_H */

