#include <stdlib.h>
#include <stdio.h>
#include "list.h"
void free_node(node_ptr n){
    free(n->next);
    n->next = NULL;
    free(n);
}
node_ptr new_node(int elem, node_ptr ptr){
    node_ptr created = NULL;
    created = malloc(sizeof(node));
    created->elem = elem;
    created->next = ptr;
    return created;
}
bool is_empty(list l){
    if(l->first == NULL) return true;
    return false;
}

int pop(list l){
    if(is_empty(l)){
        return 0;
    }
    if(l->lenght

    node_ptr tmp = l->first;
    while(tmp->next != l->last){
        tmp = tmp->next;
    }
    node_ptr last = l->last;
    tmp->next = NULL;
    int elem = last->elem;
    free_node(last);
    l->length--;
    return elem;
}
void push(list l, int e){
    node_ptr newnode = new_node(e, l->first);
    l->first = newnode;
    l->length++;
}
void append(list l, int e){
    if(is_empty(l)){
        push(l, e);
        return;
    }
    l->last->next = new_node(e, NULL);
    l->length++;
}

int get(list l, int i){
    if(l->length >= i){

    }
    node_ptr tmp = l->first;
    for(int j = 0; j < i; j++){
        tmp = tmp->next;
    }
    return tmp->elem;
}
void put(list l, int i, int e){
    if(l->length >= i){

    }
    node_ptr tmp = l->first;
    for(int j = 0; j < i; j++){
        tmp = tmp->next;
    }
    tmp->elem = e;
}

void insert(list l, int i, int e){
    //if(i == 1
}
void delete(list l, int i);

void print(list l){

}
int length(list l);
void clean(list l);

