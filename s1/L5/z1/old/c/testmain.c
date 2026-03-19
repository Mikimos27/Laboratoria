#include <stdio.h>
#include <stdlib.h>
#include "list.h"



int main(){
    list_t l;
    list lp = &l;
    l.first = NULL;
    l.last = NULL;
    l.length = 0;
    push(lp, 1);
    printf("elem = %d\n", pop(lp));
    printf("is_empty = %d\n", is_empty(lp));
    return 0;
}
