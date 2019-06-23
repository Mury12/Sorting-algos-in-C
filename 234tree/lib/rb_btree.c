#include <stdlib.h>
#include <stdio.h>
#include "rbtree.h"
#include "btree.h"
#include "rb_btree.h"
#define null NULL
#define BLK 0
#define RED 1
#define BTREE 1
#define RBLCK 2
#define LEFT 1
#define RIGHT 2
#define CAP 3


void check_234_tree(Tree_234 *t){
    printf("\n--------------------------------------");
    printf("\n %s ALTURA: %d \t ELEMENTOS: %d",tree_type(t), t->height, t->count);
    printf("\n--------------------------------------\n\n");
    printf("\n--PRESSIONE [ENTER] PARA INICIAR\n");
    getchar();
}
//manipula a conversão
RB_Tree * convert_234_rb(Tree_234 *t)
{
    RB_Tree * rb_t;

    check_234_tree(t);
    printf("\n---INICIANDO CONVERSAO 234 -> RED BLACK\n");


    return rb_t;
}
//cria os nós e retorna o nó mais significante
RB_Node * two_node(Node_234 * n)
{
    RB_Node * rb_node;

    rb_node = allocate_rb(n->data[0]);

    change_color(rb_node, BLK);

    return rb_node;
}
RB_Node * three_node(Node_234 * n)
{
    RB_Node * rb_node;

    rb_node = allocate_rb(n->data[1]);
    rb_node->left = allocate_rb(n->data[0]);
    change_color(rb_node, BLK);
    return rb_node;
}
RB_Node * four_node(Node_234 * n)
{

}
RB_Node * leaf_node(Node_234 * n)
{
    RB_Node * rb_node;

    switch(n->fill){
        case 1:
            rb_node = allocate_rb(n->data[0]);
            break;

        case 2:
            rb_node = allocate_rb(n->data[1]);
            rb_node->left = allocate_rb(n->data[0]);
            rb_node->left->parent = rb_node;
            break;

        case 3:
            rb_node = allocate_rb(n->data[1]);
            rb_node->left = allocate_rb(n->data[0]);
            rb_node->right = allocate_rb(n->data[2]);
            rb_node->left->parent = rb_node->right->parent = rb_node;
            break;

        default: return null;
    }

    change_color(rb_node, BLK);
    return rb_node;
}

Tree_234 * convert_rb_234(RB_Tree * t);
Node_234 * make_234_node(RB_Node * n);

//Varre os nós da arvore 234
RB_Tree walk_234_tree(Tree_234 * t){


    Node_234 * n;
    RB_Node *root, *a[4];
    RB_Tree rb_t;
    init_rb(&rb_t);

    int i=0;
    //childs 0
    n = t->root;
    root = make_rb_node(t->root);
    while(n->childs[i] && i<=CAP){
        a[i] = walk_234_nodes(n->childs[i]);
        i++;
    }

    switch(get_num_childs(t->root)){
        case 2:
            root->left = a[0];
            root->right = a[1];
        break;

        case 3:
            root->left->left = a[0];
            root->left->right = a[1];
            root->right = a[2];
        break;

        case 4:
            root->left->left = a[0];
            root->left->right = a[1];
            root->right->left = a[2];
            root->right->right = a[3];
        break;
    }
    // printf("\n------%d %s\n", root->right->data, get_node_color(root->right));
    rb_t.root = root;
    return rb_t;
}
RB_Node * walk_234_nodes(Node_234 * n)
{

        printf("\n---current node |%02d|%02d|%02d|", n->data[0], n->data[1], n->data[2]);

        RB_Tree t;
        RB_Node *a[4], *parent, *rb_node;
        int i = 0;

        //01
        while(n->childs[i] && i<=CAP){
            a[i] = walk_234_nodes(n->childs[i]);
            i++;
        }

        rb_node = make_rb_node(n);

        switch(get_num_childs(n)){
            case 2:
                rb_node->left = a[0];
                rb_node->right = a[1];
            break;

            case 3:
                rb_node->left->left = a[0];
                rb_node->left->right = a[1];
                rb_node->right = a[2];
            break;

            case 4:
                rb_node->left->left = a[0];
                rb_node->left->right = a[1];
                rb_node->right->left = a[2];
                rb_node->right->right = a[3];
            break;
        }


        // t.root = rb_node;
        // print_rb(t, 1);

    return rb_node;
}
void walk_rb_nodes(RB_Tree * t);

RB_Node * make_rb_node(Node_234 * n)
{
    if(!n) return null;
    if(!n->childs[0]) return leaf_node(n);

    switch(get_num_childs(n)){
        case 2:
            return two_node(n);
            break;

        case 3:
            return three_node(n);
            break;

        case 4:
            return four_node(n);
            break;
    }
}