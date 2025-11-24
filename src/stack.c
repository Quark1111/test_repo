#include <stdlib.h>
#include "stack.h"

void push(stack *begin, char c) {
    stack *elem = malloc(sizeof(stack));
    elem->symbol = c;
    elem->next = begin->next;
    begin->next = elem;
}

void pop(stack *begin) {
    stack *elem = begin->next;
    if (elem != NULL) {
        begin->next = elem->next;
        free(elem);
    }
}

bool get(stack *begin, char symbol) {
    if (begin->next != NULL)
        return begin->next->symbol == symbol;
    return false;
}

