#include <stdio.h>
#include <stdbool.h>

// Функція для перевірки парності числа
bool Even(int k) {
    return k % 2 == 0;
}

int main() {
    int choice;

    do {
        printf("\nМеню:\n");
        printf("1. Знайти кількість парних чисел у масиві\n");
        printf("0. Вихід\n");
        printf("Виберіть завдання: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int arr[10];
                int count = 0;

                printf("Введіть 10 цілих чисел:\n");
                for (int i = 0; i < 10; i++) {
                    // Перевірка введених даних
                    if (scanf("%d", &arr[i]) != 1) {
                        printf("Помилка: Введено некоректні дані. Будь ласка, введіть цілі числа.\n");
                        // Очистити буфер введення, щоб уникнути зациклення
                        while (getchar() != '\n');
                        count = -1; // Вказуємо на помилку введення
                        break;
                    }
                    if (Even(arr[i])) {
                        count++;
                    }
                }

                if (count != -1) {
                    printf("Кількість парних чисел у масиві: %d\n", count);
                }
                break;
            }
            case 0:
                printf("Вихід з програми.\n");
                break;
            default:
                printf("Невірний вибір. Спробуйте ще раз.\n");
        }
    } while (choice != 0);

    return 0;
}
