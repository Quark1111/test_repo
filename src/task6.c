#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
    char s[1000], s1[1000];
    int cnt = 0;
    scanf("%s", s);
    scanf("%s", s1);
    for (int i = 0; i < strlen(s); i++)
    {
	bool f = 0;
	for (int j = 0; j < strlen(s1); j++)
	{
	    if (i + j > strlen(s))
	    {
		f = 1;
		break;
	    }
	    if (s[i + j] != s1[j])
	    {
		f = 1;
		break;
	    }
	}
	if (!f) cnt++;
    }
    printf("%d", cnt);
    return 0;
}