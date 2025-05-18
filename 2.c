#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100 // Максимальний розмір масиву
#define MENU_TEXT "\nМеню:\n1. Вивести\n2. Добуток ненульових\n3. Сума модулів після -\n4. Перезадати\n0. Вихід\n"

void initArray(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++)
        arr[i] = min + rand() % (max - min + 1);
}

void printArray(int arr[], int size) {
    printf("Масив: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int productOfNonZeroElements(int arr[], int size) {
    int product = 1, hasNonZero = 0;
    for (int i = 0;i < size; i++) {
        if (arr[i] != 0) {
            product *= arr[i];
            hasNonZero = 1;
        }
    }
    return hasNonZero ? product : 0;
}

int sumOfAbsoluteValuesAfterFirstNegative(int arr[], int size) {
    int sum = 0, firstNegativeFound = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0)
            firstNegativeFound = 1;
        if (firstNegativeFound)
            sum += abs(arr[i]);
    }
    return sum;
}

int main() {
    srand(time(NULL));
    int size = 0, choice;
    int arr[MAX_SIZE];

    do {
        printf(MENU_TEXT);
        printf("Ваш вибір: ");
        if (scanf("%d", &choice) != 1) {
            printf("Помилка вводу.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                if (size > 0) printArray(arr, size);
                else printf("Масив не ініціалізовано (4).\n");
                break;
            case 2:
                if (size > 0) printf("Добуток: %d\n", productOfNonZeroElements(arr, size));
                else printf("Масив не ініціалізовано (4).\n");
                break;
            case 3:
                if (size > 0) printf("Сума модулів: %d\n", sumOfAbsoluteValuesAfterFirstNegative(arr, size));
                else printf("Масив не ініціалізовано (4).\n");
                break;
            case 4:
                printf("Введіть розмір (макс. %d): ", MAX_SIZE);
                if (scanf("%d", &size) != 1 || size <= 0 || size > MAX_SIZE) {
                    printf("Помилка: Некоректний розмір.\n");
                    size = 0;
                    break;
                }
                initArray(arr, size, -100, 100);
                printf("Масив перестворено.\n");
                break;
            case 0:
                printf("Вихід.\n");
                break;
            default:
                printf("Невірний вибір.\n");
        }
    } while (choice != 0);

    return 0;
}