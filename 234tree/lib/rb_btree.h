/**
 * Esta biblioteca é responsável por realizar a conversão de uma
 * árvore 234 para uma árvore rubro-negra. O processo de conversão
 * utilizado segue 4 casos:
 *
 * 1: Se o nó é uma folha;
 * 2: Se o nó tem dois filhos;
 * 3: Se o nó tem tres filhos; e
 * 4: Se o nó tem quatro filhos.
 *
 * Em cada um dos casos, o algoritmo varre todas as decendências do atual
 * nó e os transforma em 1, 2 ou 3 nós da rubro negra, seguindo os 3 parametros:
 *
 * 1: Se o nó tem um elemento, este elemento se torna um nó pai e seus decendentes
 * tornam-se seu próprios decendentes;
 * 2: Se o nó tem dois elementos, o item da direita torna-se um nó pai. O item da
 * esquerda torna-se decendente. Os dois primeiros decendentes do nó 234 tornam-se
 * filhos do primeiro elemento e o terceiro, torna-se perna direita do nó central;
 * 3: Se o nó tem três elementos, o elemento do meio torna-se um nó pai. Os primeiro
 * e último elementos tornam-se filho esquerdo e direito do nó central.
 *
 *      |1| |2| |3| =>      |2|
 *     f1  f2  f3  f4      /   \
 *                      |1|     |3|
 *                     /   \   /   \
 *                    f1   f2 f3   f4
 *                   / \   / \/ \  / \
 *                  ... ... ... ... ...
 *
 * Após a conversão de um nó 234 para um nó rubro negro, as cores são ajustadas
 * afim de manter as propriedades de uma árvore rubro negra:
 *
 * 1: O nó que sobe é um nó preto;
 * 2: Os nós descendentes são vermelhos;
 * 3: Repete o processo recursivamente, alterando novamente
 * a cor dos nós à medida que o algoritmo sobe.
 *
 * O procedimento é realizado da folha à raíz;
 */
#ifndef RB_BTREE_H
#define RB_BTREE_H
#include "./btree.h"
#include "./rbtree.h"

/**
 * Exibe as propriedades da árvore
 * 234
 */
void check_234_tree(Tree_234 *t);
/**
 * Faz a interação com o algorítmo
 * de conversão
 */RB_Tree convert_234_rb(Tree_234 *t);
/**
 * Cria um nó no tipo rubro negro
 * retorna o nó mais significante (que sobe)
 */
RB_Node * make_rb_node(Node_234 * n);
/**
 * Trata a criação de um nó RB para
 * o nó 234 com dois filhos
 */
RB_Node * two_node(Node_234 * n);
/**
 * Trata a criação de um nó RB para
 * o nó 234 com tres filhos
 */
RB_Node * three_node(Node_234 * n);
/**
 * Trata a criação de um nó RB para
 * o nó 234 com quatro filhos
 */
RB_Node * four_node(Node_234 * n);
/**
 * Trata a criação de um nó RB para
 * o nó 234 folha
 */
RB_Node * leaf_node(Node_234 * n);
/**
 * Faz a interação com o algorítmo
 * de conversão
 */
Tree_234 *  convert_rb_234(RB_Tree * t);
/**
 * Faz a varredura da árvore
 * 234 a partir da raíz
 */
RB_Tree  walk_234_tree(Tree_234 * t);
/**
 * Faz a varredura de um nó
 * e de suas sub árvores
 */
RB_Node * walk_234_nodes(Node_234 * n);

#endif