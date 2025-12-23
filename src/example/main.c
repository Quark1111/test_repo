#include "sort.h"
#include <stdio.h>

void readNumber(int *arr, int *len)
{
    int number;
    while (scanf("%d", &number) == 1 && (*len) < 100) {
		arr[*len] = number;
		(*len)++;
    }
}

int main()
{
    int arr[100], arrInitial[100], len = 0, changed = 0;
    readNumber(arrInitial, &len);
    for (int i = 0; i < len; i++)
		arr[i] = arrInitial[i];
    sort(arr, len);
    for (int i = 0; i < len; i++) {
		if (arr[i] != arrInitial[i])
	    	changed++;
    }
    for (int i = 0; i < len; i++)
		printf("%d %c", arr[i], ' ');
    return changed;
}
