/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ordena.c
 * Author: Gabriel
 *
 * Created on 26 de março de 2019, 08:42
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Ordena.h"

void MergeSort(int *vet, int inicio, int qtdd){
    int meio = (inicio+qtdd)/2;
    if (inicio<meio){
        MergeSort(vet,inicio,meio);
        MergeSort(vet,inicio,meio);
        MergeSort(vet,meio+1,qtdd);
        Merge(vet, inicio, meio, qtdd);
       }
}
    
    void Merge(int *vet, int inicio, int meio, int qtdd) {
    int com1 = inicio, com2 = meio+1, comAux = 0, tam = qtdd-inicio+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= qtdd){
        if(vet[com1] < vet[com2]) {
            vetAux[comAux] = vet[com1];
            com1++;
        } else {
            vetAux[comAux] = vet[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vet[com1];
        comAux++;
        com1++;
    }

    while(com2 <= qtdd) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vet[com2];
        comAux++;
        com2++;
    }

    for(comAux = inicio; comAux <= qtdd; comAux++){    //Move os elementos de volta para o vetor original
        vet[comAux] = vetAux[comAux-inicio];
    }
    
    free(vetAux);
     
        printf("\n----------------------------------------------\n");
    printf("Ordenados\n");
        for (int i=0;i<qtdd;i++){
            printf("%d-",vet[i]);
        }
     printf("\n----------------------------------------------\n");
    
    
}

    void QuickSort(int *vet,int inicio, int qtdd){
        if(inicio<qtdd){
            int pivo = Particiona(vet,inicio,qtdd);
            QuickSort(vet,inicio,pivo-1);
            QuickSort(vet,pivo+1,qtdd);
        }
        
        printf("\n----------------------------------------------\n");
    printf("Ordenados\n");
        for (int i=0;i<qtdd;i++){
            printf("%d-",vet[i]);
        }
     printf("\n----------------------------------------------\n");
    
    }
    
    int Particiona(int *vet,int inicio,int qtdd){
        int pivo,pos=inicio,i,aux;
        pivo=vet[inicio];
        for(i=inicio+1;i<=qtdd;i++){
            if(vet[i]<pivo){
                pos=pos+1;
                if(i!=pos){
                    aux=vet[i];
                    vet[i]=vet[pos];
                    vet[pos]=aux;
                }    
            }   
        }
        aux=vet[inicio];
        vet[inicio]=vet[pos];
        vet[pos]=aux;
        return pos;
    }
    