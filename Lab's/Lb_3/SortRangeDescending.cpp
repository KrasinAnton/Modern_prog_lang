#include <iostream>

void sortRangeDescending(int arr[], int n, int startIdx, int endIdx) {
    // Проверка корректности диапазона
    if (startIdx < 0 || startIdx >= n || endIdx < 0 || endIdx >= n || startIdx > endIdx) {
        std::cout << "Неверный диапазон!" << std::endl;
        return;
    }

    // Простой алгоритм сортировки выбором
    for (int i = startIdx; i <= endIdx; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j) { // Используем n в качестве верхнего предела итерации
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            // Обмен элементов
            int temp = arr[i];
            arr[i] = arr[maxIdx];
            arr[maxIdx] = temp;
        }
    }
}

int main() {
    int arr[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int startIdx = 1; // Начальный индекс диапазона
    int endIdx = 2;   // Конечный индекс диапазона

    std::cout << "Перед сортировкой:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    sortRangeDescending(arr, n, startIdx, endIdx);

    std::cout << "После сортировки по убыванию диапазона [" << startIdx << ", " << endIdx << "]:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
