#ifndef RBTREE_H
#define RBTREE_H


struct rb_node{
    int data;
    struct rb_node * left, * right, *parent;
    int color;
};

struct rb_tree{
    struct rb_node * root;
    int count;
    int height;
    int tree;
};
typedef struct rb_node RB_Node;
typedef struct rb_tree RB_Tree;

/**
 * Inicia a árvore Rubro Negra
 */
void init_rb(RB_Tree * t);
/**
 * Insere um nó em uma árvore binária de pesquisa
 */
RB_Node * ord_insert(RB_Tree * t, int data);
/**
 * Ajusta as cores dos nós
 */
void rb_fixup(RB_Tree * t, RB_Node * n);

/**
 * Remove um nó da árvore
 */
RB_Tree * remove_rb(RB_Tree * t, int data);
RB_Tree * remove_rb_node(RB_Tree *t, RB_Node *n);
/**
 * Realiza a rotação à esquerda de n
 */
void rotateLeft_rb(RB_Tree * t, RB_Node * n);
/**
 * Realiza a rotação à direita de n
 */
void rotateRight_rb(RB_Tree * t, RB_Node * n);

/**
 * Faz a interação com o algorítmo
 * de impressão da árvore
 */
void print_rb(RB_Tree t, int order);
/**
 * Imprime os nós da árvore
 */
void print_n_rb(RB_Node * n, int order);

/**
 * Aloca um nó e retorna
 * o ponteiro para o nó alocado
 */
RB_Node * allocate_rb(int data);
/**
 * Busca uma chave na árvore
 */
RB_Node * search_rb(RB_Tree * t, int data);
//Searches the node
RB_Node * search_n_rb(RB_Node * n, int data);
/**
 * Procura e retorna o nó com
 * o maior valor
 */
RB_Node * maxval_rb(RB_Tree * t);
/**
 * Procura e retorna o nó com
 * o menor valor
 */
RB_Node * minval_rb(RB_Tree * t);
/**
 * Retorna o próximo nó
 */
RB_Node * next_rb(RB_Node * n);
/**
 * Pesquisa pelo próximo nó
 */
RB_Node * find_next_rb(RB_Node * n);
/**
 * Retorna o valor anterior
 */
RB_Node * previous_rb(RB_Node * n);
/**
 * Pesquisa pelo valor anterior
 */
RB_Node * find_previous_rb(RB_Node * n);
/**
 * Troca a posição entre *n e *t
 */
RB_Node * swap_rb_nodes(RB_Node * n, RB_Node * t);

/**
 * Retorna a cor do nó em formato
 * de string
 */
char * get_node_color(RB_Node * n);
/**
 * Retorna o código da cor do nó
 */
int get_color_code(RB_Node * n);
/**
 * Retorna o lado que o nó se
 * encontra em relação ao pai
 */
int get_self_side(RB_Node * self);
/**
 * Inverte a cor do nó
 */
void invert_color(RB_Node * self);
/**
 * Trata e realiza a troca da cor
 * do nó
 */
void change_color(RB_Node * n, int color);
/**
 * Retorna se um nó é folha
 */
int leaf(RB_Node *n);
#endif