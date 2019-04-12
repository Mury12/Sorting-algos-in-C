
#ifndef CANVAS_H
#define CANVAS_H

/**
 * Inicia a aplicação e seus recursos.
 * @return true ou false
 */ 
int start();

/**
 * Interação de seleção de algoritmo de ordenação
 * @return true ou false;
 */ 
int select();

/**
 * Corpo da aplicação, controlador das funções selecionadas.
 * @return true ou false.
 */ 
int body();

/**
 * Realiza a ordenação do vetor de acordo com a escolha do usuário no menu de navegação.
 * @param choice numero referente ao algorítmo de ordenação
 * @param v é o ponteiro para o vetor a ser ordenado.
 * @param size é o tamanho do vetor.
 */ 
int sort(int choice, int *v, int size);

/**
 * Mostra o menu de navegação para a escolha das opções.
 */ 
void navigation();

#endif /* CANVAS_H */
