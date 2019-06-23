
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
    navigation(234);
    return body();
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
int body()
{
    int which = 234;
    int in;
    Tree_234 t_234;
    init(&t_234);
    RB_Tree t_rb;

    while(1){
        printf("\n\n\t ESCOLHA UMA OPCAO: ");
        switch(choice()){
            case 1:
                printf("\n\tINSERIR ELEMENTO NA ARVORE\n");
                printf("\n\tDIGITE UM NUMERO: ");
                scanf("%d", &in);
                Node_234 * n_234;
                insert(&t_234, in);
            break;
            case 2:

            break;

            case 3:
                which == 234
                ? print_t(t_234,0)
                : print_rb(t_rb, 1);
            break;
            case 4:
                if(which != 234) return 1;
                //converter para rubro negra
                if(t_234.root){
                    t_rb = convert_234_rb(&t_234);
                    which = 0;
                }else{
                    printf("\n\tA ARVORE ESTA VAZIA. CONVERSAO ABORTADA.\n");
                }
                break;
            case 5:
                return 1;
            default:
                printf("\nOPCAO INVALIDA!\n");

        }
        navigation(which);
    }

    return 1;
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
    printf("\t|     4 - SAIR                                               |\n");
    printf("\t--------------------------------------------------------------\n");
    }
}
