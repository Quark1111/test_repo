#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct stack{
    char simbol;
    struct stack *next;
} stack;
void push(stack *begin, char c){
    stack *elem = malloc(sizeof(stack));
    elem->simbol = c;
    elem->next = begin->next;
    begin->next = elem;
}
void pop(stack *begin){
    stack *elem = begin->next;
	if (elem != NULL){
    	begin->next = elem->next;
    	free(elem);
	}
}
bool get(stack *begin, char simbol){
    if (begin->next != NULL)
		return begin->next->simbol == simbol;
    return 0;
}
int main(){
    char input_string[100];
    stack scob_struct;
    scob_struct.next = NULL;
    bool flag = 1;
    scanf("%s", input_string);
    for (int i = 0; i < strlen(input_string); i++){
		switch(input_string[i]){
		case ']':
	    	if (get(&scob_struct, '['))
				pop(&scob_struct);
	    	else
				flag = 0;
	    	break;
		case ')':
	    	if (get(&scob_struct, '('))
				pop(&scob_struct);
	    	else
				flag = 0;
	    	break;
		case '}':
	    	if (get(&scob_struct, '{'))
				pop(&scob_struct);
	    	else
				flag = 0;
	    	break;
		default:
	    	push(&scob_struct, input_string[i]);
	    	break;
	}
	if (!flag)
	    break;
    }
    if (flag && scob_struct.next == NULL)
		printf("%s", "Yes");
    else
		printf("%s", "No");
    while (scob_struct.next !=NULL)
		pop(&scob_struct);
    return 0;
}
