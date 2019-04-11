#ifndef FILEMANAGER_H
#define FILEMANAGER_H

typedef struct Array{
    int *v, size;
}Array;

int count(char filename[]);
int read(int *v, char filename[]);
int write(char filename[]);
int createRandomValuesFile(char filename[]);

#endif /* FILEMANAGER_H */

