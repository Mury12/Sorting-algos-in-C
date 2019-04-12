#ifndef FILEMANAGER_H
#define FILEMANAGER_H

typedef struct Array{
    int *v, size;
}Array;

int count(char filename[]);
int read(int *v, char filename[]);
int write(int *v, char filename[]);
int createRandomValuesFile(char filename[]);
void showMenu();
#endif /* FILEMANAGER_H */

