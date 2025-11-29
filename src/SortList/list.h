#include <stdbool.h>

typedef struct SortList{
    int value;
    struct SortList *next;
} SortList;

void append(SortList *begin, int value);
int get(SortList *begin);
void DelElem(SortList *begin, int value);
void DelList(SortList *begin);
void PrintfList(SortList *begin);
