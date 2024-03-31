#include <iostream>
#include <cstdlib>

int main() {
    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(mas) / sizeof(int);
    int i, j;

    system("cls");
    for (i = 0; i < n; i++)
        std::cout << mas[i] << ' ';
    std::cout << std::endl;

    for (i = 0; i < n / 2; i++) {
        int imin = i, imax = i;

        // Находим минимальный и максимальный элементы в текущем подмассиве
        for (j = i + 1; j < n - i; j++) {
            if (mas[j] < mas[imin]) imin = j;
            if (mas[j] > mas[imax]) imax = j;
        }

        // Меняем минимальный элемент с крайним слева, а максимальный с крайним справа
        int t = mas[i]; 
        mas[i] = mas[imin];
        mas[imin] = t;

        // Проверка, чтобы не затронуть уже отсортированный максимальный элемент
        if (imax == i) imax = imin;
        t = mas[n - i - 1]; 
        mas[n - i - 1] = mas[imax];
        mas[imax] = t;
    }

    std::cout << "Отсортированный массив:" << std::endl;
    for (i = 0; i < n; i++)
        std::cout << mas[i] << ' ';
    std::cout << std::endl;

    return 0;
}
