#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils.h"
#include "fileManager.h"
#define null NULL
#define true 1
#define false 0

int count(char filename[])
{
    /**
     * @var *f é ponteiro para o arquivo;
     */
    FILE *f;

    /**
     * @var size é o contador do numero de elementos do arquivo
     */
    int size = 0;

    f = fopen(filename, "r");

    if(!f){
        fclose(f);
        return false;
    }


    /**
     * Faz a contagem do número de elementos do arquivo
     */
    while(!feof(f)){
        int a;
        fscanf(f, "%d", &a);
        size++;
    }


    /**
     * Encerra a função caso o arquivo tenha 0 elementos.
     */
    if(size <= 0){
        fclose(f);
        return false;
    }

    fclose(f);
    return size;

}

int read(int * v, char filename[40])
{
    /**
     * @var *f é ponteiro para o arquivo;
     */
    FILE *f;

    int i=0;

    /**
     * Abre um arquivo para leitura "r" = read
     */
    f = fopen(filename, "r");

    /**
     * Encerra a função caso haja problemas ao abrir o arquivo.
     */
    if(!f){
        fclose(f);
        return false;
    }



    /**
     * Faz a leitura dos elementos e insere no vetor.
     */
    while(!feof(f)){
        fscanf(f, "%d", &v[i]);
        i++;
    }

    /**
     * Retorna o vetor e seu tamanho para a estrutura por referência.
     */

    return true;
}

int write(int *v, int size,  char filename[])
{
    FILE *f;
    int i;
    f = fopen(filename, "w+");
    if(!f) return false;

    for(i=0; i<size; i++){
        fprintf(f, "%d ", v[i]);
    }
    fprintf(f, "\n");

    return true;
}

// void writeProfilingResults(Data *cmp, char filename[40])
// {
//     FILE *f;
//     int i;
//     f = fopen(filename, "w+");
//     if(!f) return;

//         fprintf(f, "\n\n------------------------------ %s ------------------------------\n\n", filename);

//     for(i=0; i<5; i++){

//         fprintf(f,"Tamanho do vetor: %d\n\tExecucoes: 30\n", cmp->size[i]);
//         fprintf(f,"\tComparacoes: %d\n", cmp->cmpt[i]);
//         fprintf(f,"\tTrocas: %d\n", cmp->tChanges[i]);
//         fprintf(f,"\tTempo medio: %.0lf ticks\n\n", cmp->diff[i]);

//     }

//     fprintf(f, "\n\n-------------------------------------------------------------------------\n\n");

// }


int createRandomValuesFile(char filename[])
{

    FILE *f;
    /**
     * @var size é o número de elementos que será inserido no arquivo.
     */
    int size;
    int i, val;
    srand(time(null));

    printf("Quantos elementos? ");
    scanf("%d", &size);

    f = fopen(filename, "w");

    if(!f){
        fclose(f);
        return false;
    }

    for(i=0; i<size; i++){
        /**
         * Gera valores aleatórios entre 0 e 100;
         */
        val = rand()%100;
        fprintf(f, "%d", val);

        i != size-1? fprintf(f, "\n") : true;
    }

    printf("\n%d elementos inseridos no arquivo %s.\n\n", size, filename);

    fclose(f);

    return true;
}
