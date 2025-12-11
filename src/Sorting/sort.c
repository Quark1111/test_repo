#include <stdio.h>
void sorting(int* arr, int len)
{
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
		int tmp = arr[j];
		arr[j] = arr[i];
		arr[i] = tmp;
	    }
	}
    }
}