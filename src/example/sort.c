#include "sort.h"

void sort(int *arr, int len)
{
    for (int i = 0; i < len; i++) {
	for (int j = i + 1; j < len; j++) {
	    if (arr[i] > arr[j]) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	    }
	}
    }
}