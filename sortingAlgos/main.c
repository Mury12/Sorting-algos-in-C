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
#include "libs/fileManager.h"
#include "libs/utils.h"
#include "libs/selection.h"
#include "libs/insertion.h"
#include "libs/merge.h"
#include "libs/quicksort.h"
#define null NULL
#define true 1
#define false 0
/*
 * 
 */
int main() 
{
    int v[] = {5, 4, 3, 2, 1, 10, 98, 98, 31, 56, 97, 1521, 231, 2, 0};
    int vsize = sizeof(v)/sizeof(int);
    printv(v, vsize);
    
    quickSort(v, 0, vsize);
    
    printv(v, vsize);

    
    return true;
}

