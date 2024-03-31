#include <iostream>

// Функция для обмена двух элементов массива
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция для разбиения массива и возврата индекса опорного элемента
int partition(int arr[], int low, int high) {
    // Выбираем опорный элемент (последний элемент в данном случае)
    int pivot = arr[high];

    // Индекс для элемента, который будет находиться правее опорного элемента после разбиения
    int i = low - 1;

    // Проходим по подмассиву, переставляя элементы так, чтобы все элементы меньше опорного были слева от него
    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++; // Увеличиваем индекс элемента, который будет находиться правее опорного после разбиения
            swap(arr[i], arr[j]); // Меняем местами элементы arr[i] и arr[j]
        }
    }
    // Меняем местами опорный элемент и элемент, стоящий справа от всех элементов меньших опорного
    swap(arr[i + 1], arr[high]);
    return i + 1; // Возвращаем индекс опорного элемента
}

// Основная функция для сортировки массива методом быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi - это индекс опорного элемента, arr[pi] сейчас на своем правильном месте в отсортированном массиве
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы перед опорным и после опорного
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Перед сортировкой:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, n - 1); // Вызываем функцию быстрой сортировки

    std::cout << "После сортировки с помощью быстрой сортировки:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
