typedef struct node {
    int num;
    struct node* next;
} node;

typedef struct list {
    int len;
    struct node* head;
    struct node* current;
} list;

void createList(list* List);
void deleteList(list* List);
node* append(list* List, int value);
void pop(list* List) ;
