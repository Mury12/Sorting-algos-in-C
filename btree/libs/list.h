#ifndef LIST_H
#define LIST_H

struct l_Node{
    struct l_Node *next;
    int p;
}; 
typedef struct l_Node l_Node;

struct List{
    l_Node *first;
};
typedef struct List List;

l_Node * nodeAlloc(int p);
void initl(List * l);
void pushList(List * l, int p);
void printl(List l);
void removeList(List *l, int p);
#endif