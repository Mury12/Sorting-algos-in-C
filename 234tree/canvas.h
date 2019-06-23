
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
int choice();

/**
 * Corpo da aplicação, controlador das funções selecionadas.
 * @return true ou false.
 */
int body();

/**
 * Mostra o menu de navegação para a escolha das opções.
 */
void navigation(int which);

#endif /* CANVAS_H */