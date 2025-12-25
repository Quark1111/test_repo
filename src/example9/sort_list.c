#include "list.h"
#include <stdio.h>
#include <stdbool.h>

int main()
{
    SortList begin;
    begin.next = NULL;
    bool flag = 1;
    while (flag) {
        int c, value;
	printf("%s \n", "0: close the program");
        printf("%s \n", "1: add a value to the list");
	printf("%s \n", "2: delete a value");
	printf("%s \n", "3: output a list");
	scanf ("%d", &c);
	switch(c) {
	case 0:
            flag = 0;
	    break;
	case 1:
	    scanf("%d", &value);
	    append(&begin, value);
	    break;
	case 2:
	    scanf("%d", &value);
	    DelElem(&begin, value);
	    break;
	case 3:
	    PrintfList(&begin);
	    break;
	}
    }
    DelList(&begin);
    return 0;
}
