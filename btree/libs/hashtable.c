#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hashtable.h"

#define null NULL

/**
 * Função de hash |7x| % HASHTABLE_SIZE
 */  
int hash(int data)
{
    int hash;

    hash =(int) (sqrt(pow((double)(7*data), 2)))%HASHTABLE_SIZE;
    return hash;
}

/**
 * Inicializa as listas da tabela
 */ 
void initTable(Hashtable * t)
{
    int i;
    
    for(i = 0; i < HASHTABLE_SIZE; i++){
        initl(&t->table[i]);
    }

    printf("\nHashtable initialized successfully.\n");
}

/**
 * Insere um valor na tabela
 */ 
void pushHashtable(Hashtable * t, int v)
{
    int idx = hash(v);

    pushList(&t->table[idx], v);

}

/**
 * Remove um valor da tabela
 */ 
void removeValue(Hashtable *t, int v)
{
    int idx = hash(v);

    removeList(&t->table[idx], v);

}

/**
 * Imprime a tabela
 */ 
void printh(Hashtable t)
{
    int i = 0;

    printf("---------------HASH TABLE---------------\n");
    for(i = 0; i < HASHTABLE_SIZE; i++){
        printf("H(%d)", i);
        printl(t.table[i]);
        printf("\n----------------------------------------\n");

    }

    printf("\n");
}