#include<stdio.h>
#include<stdbool.h>
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
	int x = 0, num = i;
	char ms[10000];
	while (num > 0){
	    ms[x] = num % 2;
	    num = num / 2;
	    x++;
	}
	bool flag = 1;
	for (int j = 0; j < x / 2; j++){
	    if (ms[j] != ms[x - j - 1]){
		flag = 0;
		break;
	    }
	}
	if (flag)
	    printf("%d %c", i, ' ');
    } 
    return 0;
}