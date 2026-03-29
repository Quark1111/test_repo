#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void append(SortList *begin, int value){
    SortList *NewElem = malloc(sizeof(SortList));
    SortList  *p = begin;
    bool flag = 0;
    NewElem->value = value;
    while (p->next != NULL){
	if (p->next->value > value){
	    NewElem->next = p->next;
	    p->next = NewElem;
	    flag = 1;
	    break;
	}
	p = p->next;
    }
    if (!flag){
	NewElem->next = p->next;
	p->next = NewElem;
    }
}
int get(SortList *begin){
    if (begin->next != NULL)
	return begin->next->value;
    return -1;
}
void DelElem(SortList *begin, int value){
    SortList *p = begin;
    bool flag  = 0;
    while (p->next != NULL){
	if (p->next->value == value){
	    SortList *elem = p->next;
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
void DelList(SortList *begin){
    while (begin->next != NULL){
	SortList *p = begin->next;
	begin->next = p->next;
	free(p);
    }
}
void PrintfList(SortList *begin){
    SortList *p = begin->next;
    while (p != NULL){
	printf("%d %c", p->value, ' ');
	p = p->next;
    }
    printf("\n");
}
