#include <stdio.h>
#include <string.h>

int main()
{
    char Str[1000], SubStr[1000];
    char *ptr = Str;
    int cnt = 0;
    scanf("%s", Str);
    scanf("%s", SubStr);
    while ((ptr = strstr(ptr, SubStr)) != NULL) {
		cnt++;
		ptr += 1;
    }
    printf("%d", cnt);
    return 0;
}
