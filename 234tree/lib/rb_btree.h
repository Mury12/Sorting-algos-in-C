#ifndef RB_BTREE_H
#define RB_BTREE_H
#include "./btree.h"
#include "./rbtree.h"


void check_234_tree(Tree_234 *t);
//manipula a conversão
RB_Tree convert_234_rb(Tree_234 *t);
//cria os nós e retorna o nó mais significante
RB_Node * make_rb_node(Node_234 * n);
Node_234 *  make_234_node(RB_Node * n);
RB_Node * one_node(Node_234 * n);
RB_Node * two_node(Node_234 * n);
RB_Node * three_node(Node_234 * n);
RB_Node * four_node(Node_234 * n);
RB_Node * leaf_node(Node_234 * n);
Tree_234 *  convert_rb_234(RB_Tree * t);
//Varre os nós da arvore 234
RB_Tree  walk_234_tree(Tree_234 * t);
RB_Node * walk_234_nodes(Node_234 * n);
void walk_rb_nodes(RB_Tree * t);

#endif