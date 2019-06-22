#include <stdio.h>
#include <stdlib.h>
#include "lib/btree.h"
#include "lib/rbtree.h"



void test_rb_tree()
{
    RB_Tree t;
    init_rb(&t);

    int di=0, d;
    int da[50] = {14, 57, 29, 85, 6, 3, 89, 55, 22, 70, 62, 20, 5, 77, 39, 83, 10, 38, 30, 76, 16, 72, 90, 87, 24, 11, 25, 56, 58, 74, 69, 18, 71, 82, 28, 59, 33, 2, 80, 51, 37, 40, 92, 63, 78, 9, 48, 95, 93, 21};
    printf("\n  Tipo: - %d elementos \n", t.count);
    // while(di<25){
    //     printf("\n\n--Próximo: %d\n", da[di]);
    //     // getchar();
    //     insert_rb(&t, da[di]);
    //     di++;
    // }
    //     print_rb(t, 1);

    while(1){
        scanf(" %d", &d);
        insert_rb(&t, d);
        printf("\n------\n");
        print_rb(t, 1);
    }

    printf("\n\n\n");
    print_rb(t, 1);
}

void test_234_tree()
{
    Tree_234 t;
    init(&t);
    int di=0, d;
    int da[50] = {14, 57, 29, 85, 6, 3, 89, 55, 22, 70, 62, 20, 5, 77, 39, 83, 10, 38, 30, 76, 16, 72, 90, 87, 24, 11, 25, 56, 58, 74, 69, 18, 71, 82, 28, 59, 33, 2, 80, 51, 37, 40, 92, 63, 78, 9, 48, 95, 93, 21};
    printf("\n  Tipo: %s - %d elementos \n", tree_type(&t), t.count);
    while(di<25){
        printf("\n\n--Próximo: %d\n", da[di]);
        // getchar();
        insert(&t, da[di]);
        di++;
    }
        print_t(t, 0);

    while(1){
        scanf(" %d", &d);
        insert(&t, d);
        printf("\n------\n");
        print_t(t, 0);
    }

    printf("\n\n\n");
    print_t(t, 0);
}


int main(int argc, char ** argv[])
{
    // test_234_tree();
    test_rb_tree();

return 0;

}

