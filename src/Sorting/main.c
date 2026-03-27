#include "sort.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int StrToInt(char *String, int ind)
{
    int res =  0, degree10 = 1;
    for (int i  = ind - 1; i >= 0; i--) {
		res += (String[i] - '0') * degree10;
		degree10 *= 10;
    }
    return res;
}
void ReadNumbers(int* arr, int *len)
{
    char InputString[1000];
    char substr[10];
    int ind = 0;
    fgets(InputString, sizeof(InputString), stdin);
    for (int i = 0; i < strlen(InputString); i++) {
		if (InputString[i] - '0' >= 0 && InputString[i] - '0' <= 9) {
		    substr[ind] = InputString[i];
		    ind++;    
		} else {
		    arr[*len] = StrToInt(substr, ind);
		    (*len)++;
		    ind = 0;
		}		
    }
}
int main()
{
    int len = 0;
    int arr[100];
    int ArrInitial[100];
    ReadNumbers(arr, &len);
    int ChangedPositions = 0;
    for (int i = 0; i <= len - 1; i++) {
		ArrInitial[i] = arr[i];
    }  
    sorting(arr, len);
    for (int i = 0; i <= len - 1; i++) {
		if (arr[i] != ArrInitial[i]) {
		    ChangedPositions++;
		}
    } 
    return ChangedPositions;
}
