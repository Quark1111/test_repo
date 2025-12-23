#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

bool checkParen(char ch1, char ch2)
{
    return (ch1 == '(' && ch2 == ')') || (ch1 == '[' && ch2 == ']') || (ch1 == '{' && ch2 == '}');
}
int main()
{
    char str[100];
    stack ScobStruct;
    ScobStruct.next = NULL;
    bool flag = 1;
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
	if (str[i] == '(' || str[i] == '[' || str[i] == '{') 
	    push(&ScobStruct, str[i]);
	else if (str[i] == ')' || str[i] == ']'||str[i] == '}')
	    if (ScobStruct.next == NULL || !checkParen(get(&ScobStruct), str[i])){
		flag = 0;
		break;
	    } else {
		pop(&ScobStruct);
	    }
    }
    if (flag && ScobStruct.next == NULL)
	printf("%s", "Yes");
    else
	printf("%s", "No");
    while (ScobStruct.next !=NULL)
	pop(&ScobStruct);
    return 0;
}
