#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
typedef struct queue_num{
    int n;
    char c;
    bool flag;
    struct queue_num *left, *right;
} queue_num;
typedef struct stack{
    char c;
    struct stack *next;
} stack;
typedef struct stack_num{
    int c;
    struct stack_num *next;
} stack_num;
bool prior(char c){
    if (c == '+' || c == '-')
        return 0;
    return 1;
}
void stack_push_num(stack_num *St, int c, int *len){
    stack_num *new_elem = malloc(sizeof(stack_num));
    new_elem->next = St->next;
    St->next = new_elem;
    new_elem->c = c;
    (*len)++;
}
int stack_pop_num(stack_num *St, int *len){
    if (len == 0) 
        return 0;
    else{
        stack_num *del_elem = St->next;
        int x = del_elem->c;
        St->next = del_elem->next;
        free(del_elem);
        (*len)--;
        return x;
    }
}
void stack_push(stack *St, char c, int *len){
    stack *new_elem = malloc(sizeof(stack));
    new_elem->next = St->next;
    St->next = new_elem;
    new_elem->c = c;
    (*len)++;
}
char stack_operation_get(stack *St){
    return St->next->c;
}
void stack_pop(stack *St, int *len){
    if (len == 0) 
        return ;
    else{
        stack *del_elem = St->next;
        St->next = del_elem->next;
        free(del_elem);
        (*len)--;
    }
}
int func(stack *st, int *len){
    int n = 0, c = 1;
    while (*len){
        n += ((st->next->c - '0') * c);
        stack_pop(st, len);
        c *= 10;
    }
    return n;
}
void add(queue_num *Tail, int num, char c, bool flag, int *len){
    queue_num* elem = malloc(sizeof(queue_num));
    if (flag)
        elem->n = num;
    else
        elem->c = c;
    elem->flag = flag;
    queue_num *p = Tail->right;
    Tail->right = elem;
    p->left =  elem;
    elem->left = Tail;
    elem->right = p;
    (*len)++;
}
void del(queue_num* head, int* len){
    if (len == 0)
	return;
    else{
	queue_num *p = head->left;
	queue_num *p1 = p->left;
	p1->right = head;
	head->left = p1;
	free(p);
	(*len)--;
    }
}
int main(){
    char mas_c[100];
    int len_queue = 0, len_op = 0, len_conversion_num = 0, len_num = 0;
    bool flag = 0;
    queue_num tail, head;
    stack operation;
    stack conversion_number;
    stack_num numbers;
    conversion_number.next = NULL;
    operation.next = NULL;
    tail.left = NULL;
    head.right = NULL;
    tail.right = &head;
    head.left = &tail;
    scanf("%s", mas_c);
    for (int i = 0; i < strlen(mas_c); i++){
        if (mas_c[i] >= 48 && mas_c[i] <= 57){
            if (flag == 0){
                flag = 1;
                stack_push(&conversion_number, mas_c[i], &len_conversion_num);
            }
            else{
                stack_push(&conversion_number, mas_c[i], &len_conversion_num);
            }
        }
        else{
            if (len_conversion_num){
                int x = func(&conversion_number, &len_conversion_num);
                add(&tail, x, ' ', 1, &len_queue);
                flag = 0;
            }
            if (mas_c[i] == ')'){ 
                while (stack_operation_get(&operation) != '('){
                    add(&tail, 0, stack_operation_get(&operation), 0, &len_queue);
                    stack_pop(&operation, &len_op);
                }
                stack_pop(&operation, &len_op);
                continue;
            }
            if (len_op){
                char oper = stack_operation_get(&operation);
                if (oper == '(' || mas_c[i] == '('){
                    stack_push(&operation, mas_c[i], &len_op);
                    continue;

                }
                if (prior(oper) < prior(mas_c[i])){
                    stack_push(&operation, mas_c[i], &len_op);
                }
                else{
                    add(&tail, 0, oper, 0, &len_queue);
                    stack_pop(&operation, &len_op);
                    stack_push(&operation, mas_c[i], &len_op);
                }
            }
            else{
                stack_push(&operation, mas_c[i], &len_op);
            }
        }
    }
    if (len_conversion_num){
        int x = func(&conversion_number, &len_conversion_num);
        add(&tail, x, ' ', 1, &len_queue);
    }
    while (len_op){
        add(&tail, 0, stack_operation_get(&operation), 0, &len_queue);
        stack_pop(&operation, &len_op);
    }
    queue_num *p = head.left;
    while (len_queue){
        if (p->flag){
            printf("%d %c", p->n, ' ');
            stack_push_num(&numbers, p->n, &len_num);
        }
        else{
            printf("%c %c", p->c, ' ');
            switch (p->c)
            {
            case '-':
                if (len_num == 1){
                    int x = stack_pop_num(&numbers, &len_num);
                    stack_push_num(&numbers, -x, &len_num);

                }
                else{
                    int x = stack_pop_num(&numbers, &len_num);
                    int y = stack_pop_num(&numbers, &len_num);
                    stack_push_num(&numbers, y - x, &len_num);
                }
                break;
            case '+':
                int x = stack_pop_num(&numbers, &len_num);
                int y = stack_pop_num(&numbers, &len_num);
                stack_push_num(&numbers, y + x, &len_num);
                break;
            case '*':
                int i = stack_pop_num(&numbers, &len_num);
                int j = stack_pop_num(&numbers, &len_num);
                stack_push_num(&numbers, i * j, &len_num);
                break;
            case '/':
                int I = stack_pop_num(&numbers, &len_num);
                int J = stack_pop_num(&numbers, &len_num);
                stack_push_num(&numbers, J / I, &len_num);
                break;
            }
        }
        del(&head, &len_queue);
        p = head.left;
    }
    printf("\n");
    printf("%s %d","res: ", stack_pop_num(&numbers, &len_num));
    printf("\n");
    return 0;
}