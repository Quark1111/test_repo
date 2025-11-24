#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

int main()
{
    char InputString[100];
    stack ScobStruct;
    ScobStruct.next = NULL;
    bool flag = 1;
    scanf("%s", InputString);
    for (int i = 0; i < strlen(InputString); i++){
	switch(InputString[i]){
	case ']':
	    if (get(&ScobStruct, '['))
		pop(&ScobStruct);
	    else
		flag = 0;
	    break;
	case ')':
	    if (get(&ScobStruct, '('))
		pop(&ScobStruct);
	    else
		flag = 0;
	    break;
	case '}':
	    if (get(&ScobStruct, '{'))
		pop(&ScobStruct);
	    else
		flag = 0;
	    break;
	default:
	    if (InputString[i] == '(' || InputString[i] == '[' || InputString[i] == '{')
		push(&ScobStruct, InputString[i]);
	    break;
	}
	if (!flag)
	    break;
    }
    if (flag && ScobStruct.next == NULL)
	printf("%s", "Yes");
    else
	printf("%s", "No");
    while (ScobStruct.next !=NULL)
	pop(&ScobStruct);
    return 0;
}