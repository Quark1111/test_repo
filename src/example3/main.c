#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isOperatorOrBracket(char ch)
{
    return ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '(' || ch == ')';
}

int priority(char operator)
{
    if (operator == '+' || operator == '-') {
		return 1;
	}

    if (operator == '*' || operator == '/') {
		return 2;
	}	

    return 0;
}

void addOperation(stack* operations, char operation){
    char prevOperation = get(operations);
	
    while (priority(prevOperation) >= priority(operation)) {
		printf("%c %c", prevOperation, ' ');
		pop(operations);
		prevOperation = get(operations);
    }
	
    push(operations, operation);
}

int main()
{
    stack operations;
    char str[10000];
    operations.next = NULL;
    fgets(str, sizeof(str), stdin);
    bool prevSymbolsIsNumber = false;
    
    for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
            printf("%c", str[i]);
            prevSymbolsIsNumber = true;
		} else if (isOperatorOrBracket(str[i])){
            if (prevSymbolsIsNumber) {
                printf("%c", ' ');
                prevSymbolsIsNumber = false;
            }
                    
		    if (str[i] == '(') {
				push(&operations, str[i]);
		    } else if (str[i] == ')') {
				char operation = get(&operations);

				while (operation != '(') {
				    printf("%c %c", operation, ' ');
				    pop(&operations);
				    operation = get(&operations);
				}
	
			pop(&operations);
		    } else {
				addOperation(&operations, str[i]);
			}
		}
    }
    if (prevSymbolsIsNumber) {
        printf("%c", ' ');
    }
    while (operations.next != NULL) {
		printf("%c %c", get(&operations), ' ');
		pop(&operations);
    }

    return 0;
}
