#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hash(int k)
{
    return (k)%11;
}

void main()
{
    int k;

    while(1){
        printf("\n.: ");
        scanf("%d", &k);

        printf("\n\t %d \n", hash(k));

    }
}