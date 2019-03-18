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
    int tam, metodoOrdenacao;
    char nomeArq[30];
    FILE *arq;
    
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", &nomeArq);
    arq = fopen(nomeArq, "r");
    if (!arq){
        printf("\nErro ao abrir o arquivo \n");
        return 1;
    }
}

