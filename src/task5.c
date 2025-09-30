#include<stdio.h>
#include<stdbool.h>
int main()
{
    char mas[1000];
    scanf("%s", mas);
    int cnt = 0;
    bool f = 0;
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
	if (mas[i] == '\0') break;
	if (mas[i] == '(') cnt++;
	else if (mas[i] == ')') cnt--;
	if (cnt < 0)
	{
	    printf("No");
	    f = 1;
	    break;
	}
    }
    if (cnt==0) printf("Yes");
    else if (!f) printf("No");
    return 0;
}