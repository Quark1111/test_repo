#include "cyclic_list.h"
#include <stdio.h>

void warriors(list* List, int n, int m)
{
    List->current = List->head;
    int killWarrior = 0;
    while (List->len > m - 1) {
        if (killWarrior + 1 == m) {
            pop(List);
            killWarrior = 0;
        } 
        
        List->current = List->current->next;
        if (List->current == List->head) {
            List->current = List->current->next;
        }
        killWarrior++;
    }
}

int main()
{
    list List;
    createList(&List);
    int n, m;
    scanf("%d %d", &n, &m);
	if (m <= 1) {
		return 0;
	}
    for (int i = 1; i <= n; i++) {
		List.current = append(&List, i);
    }
    warriors(&List, n, m);
    List.current = List.head->next;
    while (List.current != List.head) {
        printf("%d %c", List.current->num, ' ');
        List.current = List.current->next;
    }
    deleteList(&List);
    return 0;
}
