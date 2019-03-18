/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aluno
 *
 * Created on 18 de Março de 2019, 13:56
 */

#include <stdio.h>
#include <stdlib.h>
#include "selection.h"
#define null NULL
#define true 1
#define false 0
/*
 * 
 */
int main() 
{
    int v[5] = {5, 4, 3, 2, 1};
    
    printv(v, 5);
    
    sort(v,5);
    
    printv(v, 5);

    
    return true;
}

