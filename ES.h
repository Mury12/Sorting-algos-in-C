/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ES.h
 * Author: lucas
 *
 * Created on 18 de Março de 2019, 14:20
 */

#ifndef ES_H
#define ES_H

//A função lê um arquivo de entrada e aloca os elementos em um vetor
//A função lê numeros inteiros apenas

int lerArquivo(int vet[], FILE *arqEntrada, int tam);

void escreveArquivo(int vet[], FILE *arqSaida, int tam);

void imprimeVetor(int vet[], int tam);

void gerarAleatorio();
        


#endif /* ES_H */

