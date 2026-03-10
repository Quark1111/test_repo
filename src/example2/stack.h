#include <stdbool.h>

typedef struct stack {
    char symbol;
    struct stack *next;
} stack;

void push(stack *begin, char c);
void pop(stack *begin);
char get(stack *begin);
