#include <stdbool.h>

typedef struct stack {
    char symbol;
    struct stack *next;
} stack;

void push(stack *begin, char c);
void pop(stack *begin);
bool get(stack *begin, char symbol);

