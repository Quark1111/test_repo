#include <stdio.h>
#include <stdlib.h>

void reverse(int* array, int len)
{
    for (int i = 0; i < len / 2; i++) {
		int tmp = array[i];
		array[i] = array[len - i - 1];
		array[len - i - 1] = tmp;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int *array = calloc(n + m, sizeof(*array));

    if (array == NULL) {
      printf("Memory allocation error!\n");
    }

    for (int i = 0; i < n + m; i++) {
		scanf("%d", &array[i]);
    }

    reverse(array, n + m);
    reverse(array, m);
    reverse(array + m, n);

    for (int i = 0; i < n + m; i++) {
		printf("%d %c", array[i], ' ');
    }

    free(array);
    return 0;
}
