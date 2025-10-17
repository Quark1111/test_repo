#include<stdio.h>
int sum(int x){
    int sm = 0;
    while (x > 0){
	sm = sm + (x % 10);
	x = x / 10;
    }
    return sm;
}
int main(){
    int cnt = 0, mas[1000], ms[1000], n, mx = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
	scanf("%d", &mas[i]);
	if (mas[i] != 0){
	    ms[i] = sum(mas[i]);
	}
	else{
	    ms[i] = 0;
	}
	if (ms[i] > mx)
	    mx = ms[i];
    }
    for (int i = 0; i < n; i++){
	if (ms[i] == mx){
	    printf("%d %c", mas[i], ' ');
	}
    }
    return 0;
}