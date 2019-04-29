#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "list.h"
#define HASHTABLE_SIZE 10

typedef struct Hashtable{
    List table[HASHTABLE_SIZE];
}Hashtable;

void initTable(Hashtable * t);
void pushHashtable(Hashtable * t, int v);
void removeValue(Hashtable * t, int v);
int hash(int data);
void printh(Hashtable t);


#endif