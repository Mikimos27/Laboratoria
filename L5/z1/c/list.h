#pragma once

#include <stdbool.h>

typedef struct node {
    int elem;
    struct node* next;
} node;
typedef node* node_ptr;

typedef struct list_t {
    node_ptr first;
    node_ptr last;
    int length;
} list_t;
typedef list_t* list;

bool is_empty(list l);
int  pop(list l);
void push(list l, int e);
void append(list l, int e);

void print(list l);
int  length(list l);

int get(list, int);
void put(list, int i, int e);
void insert(list, int i, int e);
void delete(list, int i);

void clean(list);
