#include <iostream>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмен значениями
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    bubbleSort(arr, n);

    std::cout << "После сортировки:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
