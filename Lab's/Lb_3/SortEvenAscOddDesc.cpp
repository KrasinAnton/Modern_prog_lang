#include <iostream>
#include <vector>
#include <algorithm>

void sortEvenAscOddDesc(int arr[], int n) {
    std::vector<int> even, odd;

    // Разделение массива на четные и нечетные числа
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            even.push_back(arr[i]);
        } else {
            odd.push_back(arr[i]);
        }
    }

    // Сортировка четных чисел по возрастанию
    std::sort(even.begin(), even.end());

    // Сортировка нечетных чисел по убыванию
    std::sort(odd.begin(), odd.end(), std::greater<int>());

    // Объединение отсортированных частей в исходный массив
    int evenIdx = 0, oddIdx = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            arr[i] = even[evenIdx++];
        } else {
            arr[i] = odd[oddIdx++];
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

    sortEvenAscOddDesc(arr, n);

    std::cout << "После сортировки:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
