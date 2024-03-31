#include <iostream>
#include <algorithm>

void SortAscendingRange(int arr[], int n, int startIdx, int endIdx) {
    // Проверка корректности диапазона
    if (startIdx < 0 || startIdx >= n || endIdx < 0 || endIdx >= n || startIdx > endIdx) {
        std::cout << "Неверный диапазон!" << std::endl;
        return;
    }

    // Сортировка диапазона элементов массива по возрастанию
    std::sort(arr + startIdx, arr + endIdx + 1);
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

    SortAscendingRange(arr, n, startIdx, endIdx);

    std::cout << "После сортировки по диапазону [" << startIdx << ", " << endIdx << "]:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
