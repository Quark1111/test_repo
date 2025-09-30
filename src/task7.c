#include<stdio.h>
int main()
{
    int mas[1000];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
	int c;
	scanf("%d", &c);
	mas[i] = c;
    }
    int cnt = 0;
    for (int i = 0; i < n;  i++)
    {
	if (mas[i] == 0) cnt++;
    }
    printf("%d \n", cnt);
    return 0;
}