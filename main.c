/* 
 * File:   main.c
 * Author: Lucas Mello
 *
 * Created on 12 de Março de 2019, 09:40
 */

#include <stdio.h>
#include <stdlib.h>
#include "ES.h"
#include "selection.h"
int main() {
    int *vet;
    int tam, metodoOrdenacao, aux;
    char nomeArq[30];
    FILE *arq;
    
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", &nomeArq);
    arq = fopen(nomeArq, "r");
    if (!arq){
        printf("\nErro ao abrir o arquivo \n");
        return 1;
    }
    printf("Digite a quantidade de elementos do arquivo : ");
    scanf("%d", &tam);
    vet = (int*)malloc(tam*sizeof(int));
    aux =  lerArquivo(vet, arq, tam);
    fclose(arq);
    if (aux == 1){
        printf("\nTamanho do arquivo incompativel com o tamanho do vetor alocado\n");
        printf("\nO programa será encerrado\n");
        return 1;
    }
    
    //MENU
    printf("\nAlgoritmos de Ordenacao\n");
    printf("\n 1 - Bolha");
    printf("\n 2 - Bolha Inteligente");
    printf("\n 3 - Selecao");
    printf("\n Digite a opcao desejada : ");
    scanf("%d", &metodoOrdenacao);
    
    switch(metodoOrdenacao){
        case 1:
            bolha(vet, tam);
        break;
    }

    //escrever o vetor ordenado no arquivo
    
    return(0);

}

