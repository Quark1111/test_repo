#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "list.h"

void Test1(){
    SortList List;
    List.next = NULL;
    
    append(&List, 5);
    append(&List, 8);
    append(&List, -4);
    append(&List, 0);
    append(&List, 11);
    append(&List, 9);
    append(&List, 5);
    
    assert(get(&List) == -4);
    DelElem(&List, -4);
    assert(get(&List) == 0);
    DelElem(&List, 0);
    assert(get(&List) == 5);
    DelElem(&List, 5);
    assert(get(&List) == 5);
    DelElem(&List, 5);
    assert(get(&List) == 8);
    DelElem(&List, 8);
    assert(get(&List) == 9);
    DelElem(&List, 9);
    assert(get(&List) == 11);
    DelElem(&List, 11);
}

void Test2(){
    SortList List;
    List.next = NULL;
    
    append(&List, 1);
    append(&List, 2);
    append(&List, 3);

    assert(get(&List) == 1);
    DelElem(&List, 1);
    assert(get(&List) == 2);
    DelElem(&List, 2);
    assert(get(&List) == 3);
    DelElem(&List, 3);
}

void Test3(){
    SortList List;
    List.next = NULL;
    
    append(&List, 3);
    append(&List, 2);
    append(&List, 1);

    assert(get(&List) == 1);
    DelElem(&List, 1);
    assert(get(&List) == 2);
    DelElem(&List, 2);
    assert(get(&List) == 3);
    DelElem(&List, 3);
}
void Test4(){
    SortList List;
    List.next = NULL;
    
    append(&List, 3);
    append(&List, 2);
    append(&List, 1);
    
    DelList(&List);
    assert(List.next == NULL);
}
void run(){
    Test1();
    Test2();
    Test3();
    Test4();
    printf("%s \n", "all tests have been completed successfully");
}
int main(int argc, char *argv[]){
    if (argc == 2 && strcmp(argv[1], "--test") == 0){
		run();
		return 0;
    }
    SortList begin;
    begin.next = NULL;
    bool flag = 1;
    while (flag){
		int c, value;
		printf("%s \n", "0: close the program");
		printf("%s \n", "1: add a value to the list");
		printf("%s \n", "2: delete a value");
		printf("%s \n", "3: output a list");
		scanf ("%d", &c);
		switch(c){
		    case 0:
				flag = 0;
				break;
		    case 1:
				scanf("%d", &value);
				append(&begin, value);
				break;
		    case 2:
				scanf("%d", &value);
				DelElem(&begin, value);
				break;
		    case 3:
				PrintfList(&begin);
				break;
		}
    }
    DelList(&begin);
    return 0;
}
