
#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "lib/utils.h"
#include "lib/fileManager.h"
#include "lib/btree.h"
#include "lib/rbtree.h"
#include "lib/rb_btree.h"

/**
 * Inicia a aplicação e seus recursos.
 * @return true ou false
 */
int start()
{
    int * v, size;
    char filename[40];

    printf("\n\t--O ARQUIVO DEVE POSSUIR UM NUMERO");
    printf("\n\t--INTEIRO POSITIVO POR LINHA.");
    printf("\n\t--CASO O ARQUIVO NAO EXISTA, SERA");
    printf("\n\t--CRIADO UM ARQUIVO COM NUMEROS");
    printf("\n\t--ALEATORIOS.");
    printf("\n\t--DIGITE O NOME DO ARQUIVO (default->list): ");
    // scanf(" %s", filename);

    size = count("list");
    if(!size){
        v = createRandomValuesFile(filename);
        size = count(filename);
    }else{
        v = (int*)malloc(size * sizeof(int));
    }
    printf("\n----%d", size);
    read(v, "list");

    return body(v, size);
}

/**
 * Interação de seleção de algoritmo de ordenação
 * @return true ou false;
 */
int choice()
{
    int choice;
    scanf("%d", &choice);
    return choice;
}

/**
 * Corpo da aplicação, controlador das funções selecionadas.
 * @return true ou false.
 */
int body(int * v, int size)
{
    int which = 234;
    int in;
    Tree_234 t_234;
    init(&t_234);
    RB_Tree t_rb;
    Node_234 * find;

    int i;
    for(i=0; i<size; i++){
        insert(&t_234, v[i]);
    }



    system("cls");
    system("clear");

    // find = search_234_rm(t_234.root, 204);
    // printf("\n\n\t |%d|%d|%d|\n", find->data[0],find->data[1],find->data[2]);

    navigation(which);

    while(1){
        printf("\n\n\t ESCOLHA UMA OPCAO: ");
        switch(choice()){
            case 1:
                printf("\n\tINSERIR ELEMENTO NA ARVORE\n");
                printf("\n\tDIGITE UM NUMERO: ");
                scanf("%d", &in);
                which == 234
                    ? insert(&t_234, in)
                    : ord_insert(&t_rb, in);
                break;
            case 2:
                    printf("\n\tINSERIR ELEMENTO NA ARVORE\n");
                    printf("\n\tDIGITE UM NUMERO: ");
                    scanf("%d", &in);
                    which == 234
                            ? remove_234(&t_234, in)
                            : remove_rb(&t_rb, in);
                break;

            case 3:
                which == 234
                ? print_t(t_234,0)
                : print_rb(t_rb, 1);
            break;
            case 4:
                if(which != 234){
                    which = 234;
                    printf("\n\t---RETORNANDO PARA 2-3-4 TREE");
                    break;
                 }
                //converter para rubro negra
                if(t_234.root){
                    t_rb = convert_234_rb(&t_234);
                    which = 0;
                }else{
                    printf("\n\t---A ARVORE ESTA VAZIA. CONVERSAO ABORTADA.\n");
                }
                break;
            case 5:
                return 1;
            default:
                printf("\n\t---OPCAO INVALIDA!\n");

        }
        navigation(which);
    }
}

/**
 * Mostra o menu de navegação para a escolha das opções.
 */
void navigation(int which)
{
    printf("\n\n");
    printf("\t|------------------------------------------------------------|\n");
    printf("\t|                    CONVERSOR DE ÁRVORE                     |\n");
    printf("\t|               2-3-4-TREE --> RED BLACK TREE                |\n");
    printf("\t|-------------------------------|----------------------------|\n");
    if(which == 234){
    printf("\t|------OPCOES ARVORE 2-3-4------|----------------------------|\n");
    printf("\t|-------------------------------|----------------------------|\n");
    printf("\t|     1 - INSERIR ELEMENTO                                   |\n");
    printf("\t|     2 - REMOVER ELEMENTO                                   |\n");
    printf("\t|     3 - IMPRIMIR                                           |\n");
    printf("\t|     4 - CONVERTER PARA RUBRO-NEGRA                         |\n");
    printf("\t|     5 - SAIR                                               |\n");
    printf("\t--------------------------------------------------------------\n");
    }else{
    printf("\t|---OPCOES ARVORE RUBRO-NEGRA---|----------------------------|\n");
    printf("\t|-------------------------------|----------------------------|\n");
    printf("\t|     1 - INSERIR ELEMENTO                                   |\n");
    printf("\t|     2 - REMOVER ELEMENTO                                   |\n");
    printf("\t|     3 - IMPRIMIR                                           |\n");
    printf("\t|     4 - RETORNAR 2-3-4                                     |\n");
    printf("\t|     5 - SAIR                                               |\n");
    printf("\t--------------------------------------------------------------\n");
    }
}
