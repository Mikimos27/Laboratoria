#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool is_empty(list l) {
    return l->first == NULL;
}
int pop(list l) {
    node_ptr n = l->first;
    int e = n->elem;
    l->first = l->first->next;
    if (l->first == NULL)  // last element
        l->last = NULL;
    free(n);
    l->length--;
    return e;
}
void push(list l, int e) {
    node_ptr n = malloc(sizeof(node));
    n->elem = e;
    n->next = l->first;
    l->first = n;
    if (l->last == NULL)  // first element
        l->last = n;
    l->length++;
}
void append(list l, int e) {
    node_ptr n = malloc(sizeof(node));
    n->elem = e;
    n->next = NULL;
    if (l->first == NULL)  // first element
        l->first = n;
    else
        l->last->next = n;
    l->last = n;
    l->length++;
}
void print(list l) {
    node_ptr n = l->first;
    while (n != NULL) {
        printf(" %d", n->elem);
        n = n->next;
    }
    printf(" ( %d )\n", length(l));
}
int length(list l) {
//    printf("len1 = %d\n", l->length);
//    int i = 0;
//    node_ptr n = l->first;
//    while (n != NULL) {
//        i = i + 1;
//        n = n->next;
//    }
    return l->length;
}


int get(list l, int i) {
    i--;
    node_ptr tmp = l->first;
    for(int j = 0; j < i; j++){
        tmp = tmp->next;
    }
    return tmp->elem;
}
void put(list l, int i, int e){
    i--;
    node_ptr tmp = l->first;
    for(int j = 0; j < i; j++){
        tmp = tmp->next;
    }
    tmp->elem = e;
}
void insert(list l, int i, int e){
    if(i == 1){
        push(l, e);
        return;
    }
    if(i == length(l) + 1){
        append(l, e);
        return;
    }
    i--;
    node_ptr tmp = l->first;
    for(int j = 0; j < i - 1; j++){
        tmp = tmp->next;
    }
    node_ptr to_insert = malloc(sizeof(node));
    to_insert->elem = e;
    to_insert->next = tmp->next;
    tmp->next = to_insert;
    l->length++;
}
void delete(list l, int i){
    if(i == 1){
        pop(l);
        return;
    }
    i--;
    node_ptr to_delete = l->first;
    for(int j = 0; j < i - 1; j++){
        to_delete = to_delete->next;
    }
    if(i == length(l) - 1){
        free(l->last);
        to_delete->next = NULL;
        l->last = to_delete;
        l->length--;
        return;
    }
    node_ptr tmp = to_delete->next;
    to_delete->next = tmp->next;
    tmp->next = NULL;
    free(tmp);
    tmp = NULL;
    l->length--;
}

void clean(list l){
    while (!is_empty(l))
        pop(l);
}
