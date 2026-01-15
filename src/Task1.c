#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 10

void printArray(int arr[], int size) {
    printf("Массив: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    printf("Массив заполнен случайными значениями.\n");
    printArray(arr, size);
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Массив отсортирован по возрастанию.\n");
    printArray(arr, size);
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    printf("Массив развернут.\n");
    printArray(arr, size);
}

double calculateAverage(int arr[], int size) {
    if (size == 0) {
        return 0.0;
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

int main() {
    int array[ARR_LEN];
    int choice;
    int isInitialized = 0;
    
    printf("=== Работа с массивом ===\n");
    printf("Размер массива: %d элементов\n", ARR_LEN);
    
    do {
        printf("\nМеню операций:\n");
        printf("0 - Выйти\n");
        printf("1 - Заполнить массив случайными значениями\n");
        printf("2 - Отсортировать массив\n");
        printf("3 - Развернуть массив\n");
        printf("4 - Посчитать среднее арифметическое\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Выход из программы.\n");
                break;
                
            case 1:
                fillArray(array, ARR_LEN);
                isInitialized = 1;
                break;
                
            case 2:
                if (!isInitialized) {
                    printf("Ошибка: массив не инициализирован. Сначала заполните массив (опция 1).\n");
                } else {
                    sortArray(array, ARR_LEN);
                }
                break;
                
            case 3:
                if (!isInitialized) {
                    printf("Ошибка: массив не инициализирован. Сначала заполните массив (опция 1).\n");
                } else {
                    reverseArray(array, ARR_LEN);
                }
                break;
                
            case 4:
                if (!isInitialized) {
                    printf("Ошибка: массив не инициализирован. Сначала заполните массив (опция 1).\n");
                } else {
                    double average = calculateAverage(array, ARR_LEN);
                    printf("Среднее арифметическое элементов массива: %.2f\n", average);
                    printArray(array, ARR_LEN);
                }
                break;
                
            default:
                printf("Ошибка: неверный выбор. Пожалуйста, выберите операцию от 0 до 4.\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}
