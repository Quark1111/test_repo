#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    unsigned int len;
    unsigned int capacity;
    void** data;
} vector;

void createVector(vector* vec)
{
    vec->len = 0;
    vec->capacity = 1;
    vec->data = calloc(vec->capacity, sizeof(void*));
    if (vec->data == NULL) {
        printf("Memory allocation failed\n");
        vec->capacity = 0;
    }
}

void deleteVector(vector* vec)
{
    if (vec->data != NULL) {
        for (int i = 0; i < vec->len; i++) {
            free(vec->data[i]);
        }
        free(vec->data);
        vec->data = NULL;
        vec->capacity = 0;
        vec->len = 0;
    }
}

void pushBack(vector* vec, void *elem)
{
    if (vec->len + 1 > vec->capacity) {
        void** newData = realloc(vec->data, vec->capacity * 2 * sizeof(void*));
        if (newData != NULL) {
            vec->data = newData;
            vec->capacity *= 2;
        } else {
            printf("limit memory exceeded!\n");
            free(elem);
            return;
        }
    }

    vec->data[vec->len] = elem;
    vec->len++;

}

void* get(vector* vec, int index)
{
    if (index < 0 || index > vec->len - 1) {
        return NULL;
    }
    return vec->data[index];
} 

void pop(vector* vec, int index)
{
    if (index > vec->len - 1 || index < 0) {
        return;
    }
    free(vec->data[index]);
    for (int i = index + 1; i < vec->len; i++) {
        vec->data[i - 1] = vec->data[i];
    }
    vec->data[vec->len - 1] = NULL;
    vec->len--;
}

int main()
{
    vector Vector;
    createVector(&Vector);
    for (int i = 0; i < 10; i++){
        int *x = malloc(sizeof(int));
        *x = i;
        pushBack(&Vector, x);
    }
    for (int i = 0; i < Vector.len; i++) {
        printf("%d \n", *(int*)Vector.data[i]);
    }
    deleteVector(&Vector);
    return 0;
}
