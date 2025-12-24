#include "stack.h"
#include <stdio.h>
#include <string.h>

stack operations;

int IntToStr(char num[10], int len)
{
    int res = 0, degree10 =  1;
    for (int i = len - 1; i >= 0; i--) {
	res += (num[i] - '0') * degree10;
	degree10 *= 10;
    }
    return res;
}

bool isOperatorOrBracket(char ch)
{
    return ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '(' || ch == ')';
}

int priority(char operator)
{
    if (operator == '+' || operator == '-')
	return 1;
    if (operator == '*' || operator == '/')
	return 2;
    return 0;
}

void addOperation(char operation){
    char prevOperation = get(&operations);
    while (priority(prevOperation) >= priority(operation)) {
	printf("%c %c", prevOperation, ' ');
	pop(&operations);
	prevOperation = get(&operations);
    }
    push(&operations, operation);
}

int main()
{
    char str[10000], num[10], len = 0;
    operations.next = NULL;
    fgets(str, sizeof(str), stdin);

    for (int i = 0; i < strlen(str); i++) {
	if (str[i] >= '0' && str[i] <= '9') {
	    num[len] = str[i];
	    len++;
	} else if (isOperatorOrBracket(str[i])){
	    if (len){
		printf("%d %c", IntToStr(num, len), ' ');
		len = 0;
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
	    } else
		addOperation(str[i]);
	}
    }
    
    if (len) {
	printf("%d %c", IntToStr(num, len), ' ');
    }

    while (operations.next != NULL) {
	printf("%c %c", get(&operations), ' ');
	pop(&operations);
    }

    return 0;
}