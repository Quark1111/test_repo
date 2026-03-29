#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool Div(int a, int b, int* result)
{
    int absA = abs(a), absB = abs(b);
    if (b == 0)
		return 0;

    if (a == b)
		return 1;
    
    if (a == 0)
		return 1;

    while (absA >= absB) {
		absA -= absB;
		(*result)++;
    }
    if (a * b < 0) {
		if (absA)
	    	(*result)++;
		(*result) *= -1;
    }

    return 1;
}

int main()
{
    int a,b, result = 0;
    scanf("%d %d", &a, &b);
    if (Div(a, b, &result)) {
		printf("%d %d %d", a, b, result);
    } else 
		printf("%s", "impossible to divide");
    return 0;
}
