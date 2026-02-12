#include "cyclic_list.h"
#include <stdlib.h>

void createList(list* List)
{
    List->current->next = List->current;
    List->head = List->current;
    List->len = 0;
}

void deleteList(list* List)
{
    List->current = List->head;
    while (List->current->next != List->head) {
        node* elem = List->current->next;
        List->current->next = elem->next;
        free(elem);
        List->len--;
    }
}

node* append(list* List, int value)
{
    node* newElem = malloc(sizeof(node));
    newElem->next = List->current->next;
    newElem->num = value;
    List->current->next = newElem;
    List->len++;
    return newElem;
}

void pop(list* List) 
{
    if (List->len) {
        node* elem = List->current->next;
        if (elem == List->head) {
            elem = elem->next;
            List->current = List->current->next;
            List->head->next = elem->next;
        }
        List->current->next = elem->next;
        List->len--;
        free(elem);
    }
}
