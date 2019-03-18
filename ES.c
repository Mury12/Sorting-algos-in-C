/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "ES.h"

int lerArquivo(int vet[], FILE *arqEntrada, int tam){
    int i=0;
    while(!feof(arqEntrada)){
        fscanf(arqEntrada, "%d", &vet[i]);
        i++;
        //Testa se o arquivo de entrada tem mais elementos
        //do que o que foi alocado para o vetor
        if(i >= tam){
            return 1;
        }
    }
    //Testa se o arquivo de entrada tem menos elementos
    //do que o que foi alocado para o vetor
    if(i != tam){
        return 1;
    }
    return 0;
}

void escreveArquivo(int vet[], FILE *arqSaida, int tam){
    int i;
    for (i = 0; i < tam; i++){
        fprintf(arqSaida, "%d\n", vet[i]);
    }
    return;
}

void imprimeVetor(int vet[], int tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("%d\n", vet[i]);
    }
    return;
}