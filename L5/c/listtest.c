#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

int main() {
    char command[20];
    bool cont = true;
    int r;
    int e;
    list l = malloc(sizeof(list_t));
    l->first = l->last = NULL;
    l->length = 0;
    while (cont) {
        printf("Command: ");
        scanf("%s", command);
        if (!strcmp(command, "pop")) {
            if (!is_empty(l)) {
                r = pop(l);
                printf("Result: %d\n", r);
            } else {
                printf("Error - stack is empty!\n");
            }
        }
        else if (!strcmp(command, "push")) {
            printf("Value: ");
            scanf("%d", &r);
            push(l, r);
            printf("Result: OK\n");
        }
        else if (!strcmp(command, "append")) {
            printf("Value: ");
            scanf("%d", &r);
            append(l, r);
            printf("Result: OK\n");
        }
        else if (!strcmp(command, "get")) {
            printf("Value: ");
            scanf("%d", &r);

            printf("Result: %d\n", get(l, r));
        }
        else if (!strcmp(command, "put")) {
            printf("Value: ");
            scanf("%d", &r);
            printf("Elem: ");
            scanf("%d", &e);
            put(l, r, e);
            printf("Result: OK\n");
        }
        else if (!strcmp(command, "insert")) {
            printf("Value: ");
            scanf("%d", &r);
            printf("Elem: ");
            scanf("%d", &e);
            insert(l, r, e);
            printf("Result: OK\n");
        }
        else if (!strcmp(command, "delete")) {
            printf("Value: ");
            scanf("%d", &r);
            delete(l, r);
            printf("Result: OK\n");
        }
        else if (!strcmp(command, "print")) {
            printf("Result: ");
            print(l);
        }
        else if (!strcmp(command, "length")) {
            r = length(l);
            printf("Result: %d\n", r);
        }
        else if (!strcmp(command, "clean")) {
            clean(l);
            printf("Result: OK\n");
        }
        else if (!strcmp(command, "exit")) {
            cont = false;
        }
        else
        printf("Unknown command!\n");
    }
    while (!is_empty(l))
        pop(l);
    free(l);

    return 0;
}
