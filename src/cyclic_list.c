#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct cyclic_list{
    int number;
    struct cyclic_list *next;
} cyclic_list;
cyclic_list *append(cyclic_list *current, cyclic_list *begin, int num){
    cyclic_list *elem = malloc(sizeof(cyclic_list));
    elem->number =  num;
    current->next = elem;
    elem->next = begin;
    return elem;
}
void del_list(cyclic_list *begin){
    while (begin->next != begin){
	cyclic_list *p = begin->next;
	begin->next = p->next;
	free(p);
    }
}
void del_elem(cyclic_list *elem, int *len){
    cyclic_list *p = elem->next;
    elem->next = p->next;
    free(p); 
    (*len)--;
}
void printf_list(cyclic_list *begin){
    cyclic_list *elem = begin->next;
    while (elem != begin){
	printf("%d %c", elem->number, ' ');
	elem = elem->next;
    }
    printf("\n");
}
int main(){
    int n, m, len = 0;
    cyclic_list begin, *p;
    begin.next = &begin;
    p = &begin;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
	p = append(p, &begin, i);
	len++;
    }
    if (len > 0){
	int c = 0;
	cyclic_list *elem =  &begin;
	while (len >= m){
	    if ((c + 1) % m == 0){
        	if (elem->next == &begin)
        	    elem = elem->next;
		del_elem(elem, &len);
		c = 0;
	    }
	    else{
        	if (elem->next != &begin)
            	    c++;
		elem = elem->next;
	    }
	}
	printf_list(&begin);
	del_list(&begin);
    }
    else{
	printf("%s", "the list is empty");
    }
    return 0;
}