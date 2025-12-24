#include <stdio.h>

int main()
{
    int x, t, result;
    scanf("%d", &x);
    t = x * x;
    result = (t + x) * (t + 1) + 1;
    printf("for x = %d \n", x);
    printf("x^4 + x^3 + x^2 + x + 1 = %d", result);
    return 0;
}