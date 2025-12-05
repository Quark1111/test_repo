#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int ms[1000];
int mas[1000];
bool mas_flag[1000];
void f(int a, int len){
    if (a == len){
	bool flag = 1;
	for (int j = 1; j < a; j++){
	    if (ms[j - 1] > ms[j]){
		flag = 0;
		break;
	    }
	}
	if (flag){
	    for (int i = 0; i < a; i++){
		printf("%d %c", ms[i], ' ');
	    }
	    exit(0);
	}
    }
    else{
	if (a < len){
	    for (int i = 0; i < len; i ++){
		if (!mas_flag[i]){
		    mas_flag[i] = 1;
		    ms[a] = mas[i];
		    a = a + 1;
		    f(a, len);
		    a = a - 1;
		    ms[a] = 0;
		    mas_flag[i] = 0;
		}
	    }
	}
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
	scanf("%d", &mas[i]);
	mas_flag[i] = 0;
    }
    f(0, n); 
    return 0;
}