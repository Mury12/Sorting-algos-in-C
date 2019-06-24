#ifndef BTREE_H
#define BTREE_H

struct node_234{
    int data[3];
    int fill;
    struct node_234 * childs[4];
    struct node_234 * parent;
};
struct tree_234{
    struct node_234 * root;
    int count;
    int height;
    int tree;
};

typedef struct node_234 Node_234;
typedef struct tree_234 Tree_234;
/**
 * Inicia a árvore 234
 */
void init(Tree_234 * t);
/**
 * Insere um nó na árvore 234
 */
void insert(Tree_234 * t, int data);
/**
 * Realiza a inserção do nó
 * e retorna sua posição no nó
 */
int insert_elem(Node_234 * n, int data);
/**
 * Remove um nó da árvore
 */
void remove_234(Tree_234 * t, int data);
int remove_234_node(Node_234 * n, int data);
Node_234 * next_234(Node_234 * n);
/**
 * Realiza e trata a remoção do nó
 */
void remove_btree(Node_234 * n);

/**
 * Imprime a árvore 234
 */
void print_t(Tree_234 t, int order);
/**
 * Realiza a impressão dos nós
 * da árvore 234
 *
 * |PAI| -> |F0| - |F1| - |F2| - |F3|
 * |F0|  -> |f0| - |f1| - |f2| - |f3|
 * |f0|  -> |ff0| ...
 * |F1|  -> ...
 */
void print_n(Node_234 * n, int order);
/**
 * Retorna a altura da árvore
 */
void getHeight(Tree_234 * t);

/**
 * Aloca um nó e retorna
 * o ponteiro para o nó alocado
 */
Node_234 * allocate(int data);
/**
 * Busca um valor na árvore 234
 */
Node_234 * search_234_rm(Node_234 * root, int data);
/**
 * Retorna o nó que contém a chave
 * de maior valor
 */
Node_234 * maxval(Tree_234 * t);
/**
 * Retorna o nó que contém a chave
 * com menor valor
 */
Node_234 * minval(Tree_234 * t);
/**
 * Realiza uma divisão em um nó
 * da árvore seguindo o algorítmo
 * de preemptive split
 */
Node_234 * split_node(Node_234 * aux);
Node_234 * merge_nodes(Node_234 * a, Node_234 * b);
/**
 * Realiza a busca da locação do novo
 * valor e retorna o nó escolhido para
 * alocar
 */
Node_234 * search_insert(Tree_234 * t, Node_234 *n, int data);

/**
 * Retorna o tipo da árvore
 * em formato de string
 */
char * tree_type(Tree_234 *t);
/**
 * Retorna a quantidade de filhos que
 * um nó possui
 */
int get_num_childs(Node_234 *n);
int get_self_pos(Node_234 *self, int data);
int get_self_child_idx(Node_234 * self);
int get_parent_idx(Node_234 * self, int idx);

#endif