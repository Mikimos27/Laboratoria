#ifndef MYLIST_H
#define MYLIST_H

#include <stdbool.h>

typedef struct node{
    int elem;
    struct node* next ;
}node;
typedef node* node_ptr ;

typedef struct list_t{
    node_ptr first;
    node_ptr last;
    int length;
}list_t;
typedef list_t* list;

node_ptr new_node(int elem, node_ptr ptr);
void free_node(node_ptr);

bool is_empty(list l);

int pop(list l);
void push(list l, int e);
void append(list l, int e);

int get(list l, int i);
void put(list l, int i, int e);
void insert(list l, int i, int e);
void delete(list l, int i);

void print(list l);
int length(list l);
void clean(list l);

#endif
