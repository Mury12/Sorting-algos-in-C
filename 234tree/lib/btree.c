#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"
#define null NULL
#define CAP 3
#define BTREE 1
#define RBLCK 2


void init(Tree_234 * t)
{
    t->root = null;
    t->count = 0;
    t->height = 0;
    t->tree = BTREE;
}
//Inserts a node
void insert(Tree_234 * t, int data)
{
    Node_234 *n, *m, *aux;
    if(t->root == null)
    {
        n = allocate(data);

        printf(" Raiz nula iniciada \n");
        t->root = n;
    }else{
        aux = t->root;
        //Nó folha
        if(!aux->childs[0]){
            if(aux->fill == CAP){
                //preemptive split
                if(!aux->parent){//raíz
                    //split
                    n = split_node(aux);
                    t->root = n;
                    t->height++;
                }
                Node_234 *m = search_insert(t, n, data);
                insert_elem(m, data);
            }else{
                insert_elem(aux, data);
            }
        }else{
            Node_234 *m;
            m = search_insert(t, t->root, data);
            printf("No para insercao: |%02d|%02d|%02d| \n", m->data[0], m->data[1], m->data[2]);

            if(m->fill == CAP){
                split_node(m);
                m = search_insert(t, t->root, data);
            }
            insert_elem(m, data);

        }
    }
    t->count++;
}
int insert_elem(Node_234 * n, int data)
{
    Node_234 * aux;
    aux = n;
    int r=0;
    if(aux->fill < CAP){
        int i=0;
        while(aux->data[i] != -1 && i < CAP){
            i++;
        }
        while(data < aux->data[i-1] && i > 0){
            int a;
            Node_234 * b;

            //ordena a inserção
            a = aux->data[i-1];
            aux->data[i-1] = data;
            aux->data[i] = a;
            i--;
        }
        aux->data[i] = data;
        aux->fill++;
        printf("Adicionando elemento %d: |%02d|%02d|%02d| \n", data, n->data[0], n->data[1], n->data[2]);
    }
    r=0;
    while(r<CAP){
        if(aux->data[r] == data) break;
        r++;
    }
    return r;
}
Node_234 * search_234_rm(Node_234 * root, int data)
{
    Node_234 * aux;
    aux = root;
    int i = 0;
    int idx, self, p_idx;
    idx = get_self_pos(aux, data);

    if(!aux->childs[0] || aux->data[idx] == data) return aux;

    if(aux->parent && aux->childs && aux->fill == 1){
        if(aux->parent->fill > 1){
            self = get_self_child_idx(aux);
            if(aux->parent->childs[self+1] && aux->parent->childs[self+1]->fill == 1){
               merge_nodes(aux, aux->parent->childs[self+1]);
            }else
            if(aux->parent->childs[self-1] && aux->parent->childs[self-1]->fill == 1){
                merge_nodes(aux->parent->childs[self-1], aux);
            }
        }
        return search_234_rm(aux->parent, data);
    }

    for(i=0; i<CAP; i++){
        if(aux->data[i] == -1 || data <= aux->data[i]){
            break;
        }
    }
    if(data > aux->data[i-1] && aux->childs[i]){
        return search_234_rm(aux->childs[i], data);
    }else{
        return search_234_rm(aux->childs[i-1], data);
    }
}

Node_234 * search_insert(Tree_234 * t, Node_234 *n, int data)
{
    Node_234 *aux;
    int i=0;
    aux = n;

    //preemptive split
    if(aux->fill == CAP){
        //preemptive split
        if(!aux->parent){//raíz
            //split
            n = split_node(aux);
            t->root = n;
            t->height++;
        }else{
            n = split_node(aux);
        }
        if(n->parent)
            aux = n->parent;
        else
            aux = t->root;
    }

    if(!aux->childs[0]) return aux;

    for(i=0; i<CAP; i++){
        if(aux->data[i] == -1 || data <= aux->data[i]){
            break;
        }
    }
    if(data > aux->data[i-1] && aux->childs[i]){
        return search_insert(t, aux->childs[i], data);
    }else{
        return search_insert(t, aux->childs[i-1], data);
    }
}
//Removes a node


/**
 * Interage com o algorítmo de
 * impressão da arvore 234
 */
void print_t(Tree_234 t, int order)
{
    printf("\n|---NO---| ->  |FILHO 01| - |FILHO 02| - |FILHO 03| - |FILHO 04| \n");
    if(get_num_childs(t.root) == 0){
        printf("|%02d|%02d|%02d| ", t.root->data[0], t.root->data[1], t.root->data[2]);
    }else{
        print_n(t.root, 0);
    }

    printf("\n\t-------------------------------------------------------------");
    printf("\n\t|           Altura: %d  Elementos: %d   Tipo: %s          |", t.height, t.count, tree_type(&t));
    printf("\n\t-------------------------------------------------------------\n");

}

void print_n(Node_234 * n, int order)
{
    int i=0, nc = get_num_childs(n);

    if(!n || nc == 0) return;

    printf("|%02d|%02d|%02d| -> ", n->data[0], n->data[1], n->data[2]);
    while(i < nc && n->childs[i]){
        if(i>0) printf("-");
        printf(" |%02d|%02d|%02d| ", n->childs[i]->data[0], n->childs[i]->data[1], n->childs[i]->data[2]);
        i++;
    }
    printf("\n");
    i=0;
    while(i < nc && n->childs[i]){
        print_n(n->childs[i],0);
        i++;
    }


}

//Aloca um nó
Node_234 * allocate(int data)
{
    Node_234 * n = malloc(sizeof(Node_234));

    if(n){
        n->data[0] = data;
        n->data[1] = -1;
        n->data[2] = -1;
        n->fill = 1;
        n->childs[0] = n->childs[1] = n->childs[2] = n->childs[3] = null;
        n->parent = null;
    }
    return n;
}
//Searches a value in the tree
Node_234 * search(Tree_234 * t, int data);
//Searches the node
Node_234 * search_n(Node_234 * n, int data);
//Gets the bigger value
Node_234 * maxval(Tree_234 * t);
//Gets the lwoest value
Node_234 * minval(Tree_234 * t);
//Next value
Node_234 * next(Node_234 * n);
//Tracks the next node value
Node_234 * find_next(Node_234 * n);
//Previous value
Node_234 * previous(Node_234 * n);
//Tracks the previous node value
Node_234 * find_previous(Node_234 * n);
//Promotes a child node one level above
Node_234 * promoteChild(Node_234 * n);

//Divide o nó e retorna o nó pai a/->b<-\c
Node_234 * split_node(Node_234 * aux)
{
    printf("\nNo cheio, split\n");
    //n é o nó que será pai, m o nó da direita
    //aux vira filho 0
    Node_234 *n, *m;
    aux->fill = 1;
    Node_234 * p = aux->parent;


    if(aux->parent){
        int i=0, idx, n_childs=0;
        if(p->fill < CAP){

            idx = insert_elem(aux->parent, aux->data[1]);
            printf("\n Promovido %d, ", aux->data[1]);
            printf("posicionado em %d\n", idx);

            n_childs = get_num_childs(p);
            //valor da direita
            n = allocate(aux->data[2]);

            i=n_childs-1;

            //move de 1 posição os filhos no vetor
            while(i>idx){
                p->childs[i+1] = p->childs[i];
                i--;
            }
            Node_234 * z = p->childs[idx];
            if(n->data[0] > p->data[idx]){
                p->childs[idx+1] = n;
            }else
            if(z->data[0] > p->data[idx]){
                p->childs[idx] = n;
                p->childs[idx+1] = z;
            }
            //Set pai de n
            n->parent = p;

            //Se não é nó folha, acerta as referências
            if(aux->childs[0]){
                n->childs[0] = aux->childs[2];
                n->childs[1] = aux->childs[3];
                n->childs[0]->parent = n->childs[1]->parent = n;
                aux->childs[2] = aux->childs[3] = null;
            }

        }

    }else{
        //Nó que sobe
        n = allocate(aux->data[1]);
        //Filho da direita
        m = allocate(aux->data[2]);

        if(get_num_childs(aux) == 4){
            m->childs[0] = aux->childs[2];
            m->childs[1] = aux->childs[3];

            m->childs[0]->parent = m;
            m->childs[1]->parent = m;

            n->childs[2] = n->childs[3] = null;
            aux->childs[2] = aux->childs[3] = null;

        }
        //Ajusta as referencias dos filhos de n
        n->childs[0] = aux;
        n->childs[1] = m;
        aux->parent = m->parent = n;
    }
    //esvazia as posições que saíram
    aux->data[1] = aux->data[2] = -1;
    return n;
}

void remove_234(Tree_234 * t, int data)
{
    int status;
    Node_234 *n = search_234_rm(t->root, data);
    if(data != n->data[0] && data != n->data[1] && data != n->data[2]){
        printf("\n\tELEMENTO NAO ENCONTRADO.\n");
        return;
    }
    status = remove_234_node(n, data);
    switch(status){
        case 2:
            t->height--;
        break;
    }
    t->count--;

}
int remove_234_node(Node_234 * n, int data)
{
    int i = 0, idx=0, p_idx=0;

    idx = get_self_pos(n, data);
    p_idx = get_parent_idx(n, idx);

    if(!n->childs[0]){
        if(!n->parent || n->fill > 1){
            i=idx;
            n->fill--;
            while(i < n->fill){
                n->data[i] = n->data[i+1];
                i++;
            }
            n->data[n->fill] = -1;
            return 1;
        }else
        if(n->parent && n->fill == 1){
            n->data[idx] = -1;
            //empresta rotaçao direita ou esquerda
            if(data >= n->parent->data[p_idx]){
                int self = get_self_child_idx(n);
                int lend, old, a, b;
                Node_234 * left, *right;
                left = n->parent->childs[self-1];
                right = n->parent->childs[self+1];
                //se ele for um vetor da direita, empresta da esquerda
                if(left->fill > 1){
                    //se o irmao da esquerda tiver mais de 1 elemento
                    left->fill--;
                    lend = left->data[left->fill];
                    left->data[left->fill] = -1;
                    old = n->parent->data[p_idx];
                    n->parent->data[p_idx] = lend;
                    n->data[idx] = old;
                }else{
                    //se o irmão da esquerda está com apenas 1, procura no da direita
                    if(right && right->fill > 1){
                        right->fill--;
                        lend = right->data[0];
                        right->data[0] = right->data[right->fill];
                        right->data[right->fill] = -1;
                        old = n->parent->data[p_idx+1];
                        n->parent->data[p_idx+1] = lend;
                        n->data[idx] = old;

                        //Se nenhum dos lados tem espaço, faz-se o merge dos nodes
                    }
                        n->parent->data[n->parent->fill] = -1;
                        n->parent->fill--;
                        n->parent->childs[self] = null;
                    }
                }
            }else{
                Node_234 * next = next_234(n, data);
                int c = next->data[0];
                i=0;
                if(next->fill>1){
                    while(i<CAP){
                        next->data[i] = next->data[i+1];
                    }
                    n->data[idx] = c;
                }else{
                    int next_in_child = get_self_child_idx(next);
                    if(next->parent->childs[next_in_child+1]){
                        merge_nodes(next, next->parent->childs[next_in_child+1]);
                    }else{
                        if(next->parent->childs[next_in_child+1]){
                        merge_nodes(next, next->parent->childs[next_in_child-1]);
                    }
                }
            }
        }
    }else{

    }
                printf("\n\t---removeu %d\n", data);

}
Node_234 * merge_nodes(Node_234 *a, Node_234* b)
{
    Node_234 * aux;
    int self_a, self_b, idx, p_idx, c, d, i=0;
    self_a = get_self_child_idx(a);
    self_b = get_self_child_idx(b);
    aux = a;
    p_idx = get_parent_idx(a, 0)+1;

    //a e b tem um dado apenas
    c = a->parent->data[p_idx];
    d = b->data[0];
    i=p_idx;
    while(i < a->parent->fill - 1){
        a->parent->data[i] = a->parent->data[i+1];
        i++;
    }
    a->parent->fill--;
    a->parent->data[a->parent->fill] = -1;
    insert_elem(a, c);
    insert_elem(a, d);
    a->childs[2] = b->childs[0];
    a->childs[3] = b->childs[1];
    a->childs[2]->parent = a->childs[3]->parent = a;
    a->parent->childs[self_b] = null;
    free(b);
    print_n(a, 1);
    return a;
}
Node_234 * next_234(Node_234 * n, int data)
{
    Node_234 * aux;
    int idx = get_self_pos(n, data);
    aux = n->childs[idx+1];

    while(aux->childs[0]){
        aux = aux->childs[0];
    }


    return aux;
}

char * tree_type(Tree_234 *t)
{
    if(t->tree == BTREE) return "BTREE";
    else return "REDBLACK";
}

//Retorna o número de filhos de um nó
int get_num_childs(Node_234 *n)
{
    int n_childs=0, i=0;
    while(n->childs[i] != null && i <= CAP){
        n_childs++;
        i++;
    }
    return n_childs;
}

int get_parent_idx(Node_234 * self, int idx)
{
    int i=0;
    if(self->parent){
        while(self->data[idx] < self->parent->data[i]){
            i++;
        }
    }
    return i;
}

int get_self_pos(Node_234 * self, int data)
{
    int i=0;
    while(i<CAP)
    {
        if(self->data[i] == data) return i;
        i++;
    }
}

int get_self_child_idx(Node_234 * self)
{
    int i=0;
    while(i<=CAP){
        if(self->parent->childs[i] == self) return i;
        i++;
    }
}