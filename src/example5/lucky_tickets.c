#include <stdio.h>

int main()
{
    int sums[28], res = 0;
    
    for (int i = 0; i < 28; i++)
	sums[i] = 0;

    for (int a = 0; a <= 9; a++)
	for (int b = 0; b <= 9; b++)
	    for (int c = 0; c <= 9; c++)
		sums[a + b + c] += 1;

    for (int i = 0; i < 28; i++)
	res += sums[i] * sums[i];
    
    printf("%d", res);
    return 0;
}