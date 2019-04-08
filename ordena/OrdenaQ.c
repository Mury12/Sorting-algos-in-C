/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ordena.c
 * Author: Gabriel
 *
 * Created on 20 de março de 2019, 15:02
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Ordena.h"

void Ordena(){
    
    int op,i,qtdd,inicio=0;   
    
    printf("----------------------------------------------\n");
    printf("Quantos elementos tem no arquivo que se pretende inserir?\n");
    scanf("%d",&qtdd);
    printf("----------------------------------------------\n");
    int *vet = (int *) malloc (qtdd*sizeof(int));
    FILE * arqA;
    arqA = fopen("aleatorios.txt","r");
    
    if (arqA == NULL){
        printf("Erro ao Abrir o arquivo");
        exit(1);
    }
    //Linha que coloca os dados do arquivo pra dentro do vetor
        for(i=0;i<qtdd;++i){
            fscanf(arqA,"%d",&vet[i]); 
        }
            fclose(arqA);    
            
            
                printf("\n----------------------------------------------\n");
            
                printf("MENU DE SELECAO DE METODOS DE ORDENACAO\n");
                printf("----------------------------------------------\n");
                
                do{
                    printf("Selecione um dos metodos de ordenacao\n");
                    scanf("%d",&op);
                    printf("----------------------------------------------\n");
                    
                    switch(op){
                        case(1):
                            bubbleSort(vet, qtdd);
                        break;
            
                        case(2):
                            bubbleSortInt(vet, qtdd);
                        break;
                    
                        case(3):
                            SelectionSort(vet, qtdd);
                        break;
                        case(4):
                            InsertionSort(vet, qtdd);
                        break;
                        case(5):
                            MergeSort(vet,inicio,qtdd);
                        break;
                        case(6):
                            QuickSort(vet,inicio,qtdd);
                        break;    
                    }
                }while(op!=0);
               
                free(vet);
    }
        
    
                    
    

void bubbleSort(int *vet, int qtdd){
    int i,j,aux;
   
    for (i=0;i<qtdd;i++){
        printf("%d-",vet[i]);
    }
    
    for(i=0;i<qtdd;i++){
        for(j=0;j<qtdd-1;j++){
            if(vet[j]>vet[j+1]){
                aux = vet[j];
                vet[j]= vet[j+1];
                vet[j+1]=aux;
            }
        }
    }
    printf("\n----------------------------------------------\n");
    printf("Ordenados\n");
        for (i=0;i<qtdd;i++){
            printf("%d-",vet[i]);
        }
     printf("\n----------------------------------------------\n");
    
}

void bubbleSortInt(int *vet, int qtdd){
    int i,j,aux;
    int troca=0,quant=0;
    
    for (i=0;i<qtdd;i++){
        printf("%d-",vet[i]);
    }
    
    for(i=0;i<qtdd;i++){
        j=0;
        troca=0;
        while(j<(qtdd-i)){
            if(vet[j]> vet[j+1]){
                aux=vet[j];
                vet[j]=vet[j+1];
                vet[j+1] = aux;
                troca=1;
            }
            j++;
            
        }
    }
    printf("\n----------------------------------------------\n");
    printf("Ordenados\n");
    for (i=0;i<qtdd;i++){
        printf("%d-",vet[i]);
    }
     printf("\n----------------------------------------------\n");
    
}

void SelectionSort(int *vet, int qtdd){
       int i, j, min, aux;
  
  for (i = 0; i < (qtdd - 1); i++) {
    /* O minimo é o primeiro número não ordenado ainda */
    min = i;
    for (j = i+1; j < qtdd; j++) {
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
      if (vet[j] < vet[min]) {
   min = j;
      }
    }
    /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
    if (i != min) {
      aux = vet[i];
      vet[i] = vet[min];
      vet[min] = aux;
    }
  }
    
    printf("\n----------------------------------------------\n");
    printf("Ordenados\n");
    for (i=0;i<qtdd;i++){
        printf("%d-",vet[i]);
        
    }
    printf("\n----------------------------------------------\n");

}

void InsertionSort(int *vet, int qtdd){
    int i, marcador,pos,aux;
    for(marcador=1;marcador<qtdd;marcador++){
        pos = marcador -1;
        aux=vet[marcador];
        while((pos>=0)&& (aux<vet[pos])){
            vet[pos+1]=vet[pos];
            pos = pos-1;
        }
        vet[pos+1]=aux;      
    }
    for (i=0;i<qtdd;i++){
        printf("%d-",vet[i]);    
    }
    printf("\n----------------------------------------------\n");

}






