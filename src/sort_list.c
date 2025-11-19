#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct sort_list{
    int value;
    struct sort_list *next;
} sort_list;
void append(sort_list *begin, int value){
    sort_list *new_elem = malloc(sizeof(sort_list));
    sort_list  *p = begin;
    bool flag = 0;
    new_elem->value = value;
    while (p->next != NULL){
	if (p->next->value > value){
	    new_elem->next = p->next;
	    p->next = new_elem;
	    flag = 1;
	    break;
	}
	p = p->next;
    }
    if (!flag){
	new_elem->next = p->next;
	p->next = new_elem;
    }
}
void del_elem(sort_list *begin, int value){
    sort_list *p = begin;
    bool flag  = 0;
    while (p->next != NULL){
	if (p->next->value == value){
	    sort_list *elem = p->next;
	    p->next = elem->next;
	    flag = 1;
	    free(elem);
	    break;
	}
	p = p->next;
    }
    if (!flag){
	printf("\n %s", "the item is not in the list");
    }
}
void del_list(sort_list *begin){
    while (begin->next != NULL){
	sort_list *p = begin->next;
	begin->next = p->next;
	free(p);
    }
}
void printf_list(sort_list *begin){
    sort_list *p = begin->next;
    while (p != NULL){
	printf("%d %c", p->value, ' ');
	p = p->next;
    }
    printf("\n");
}
int main(){
    sort_list begin;
    begin.next = NULL;
    bool flag = 1;
    while (flag){
	int c, value;
	printf("%s \n", "0: close the program");
	printf("%s \n", "1: add a value to the list");
	printf("%s \n", "2: delete a value");
	printf("%s \n", "3: output a list");
	scanf ("%d", &c);
	switch(c){
	    case 0:
		flag = 0;
		break;
	    case 1:
		scanf("%d", &value);
		append(&begin, value);
		break;
	    case 2:
		scanf("%d", &value);
		del_elem(&begin, value);
		break;
	    case 3:
		printf_list(&begin);
		break;
	}
    }
    del_list(&begin);
    return 0;
}