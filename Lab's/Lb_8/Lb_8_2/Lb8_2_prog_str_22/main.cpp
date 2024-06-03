#include <iostream> // Подключаем заголовочный файл для работы с вводом-выводом
#include "Money.h"  // Подключаем заголовочный файл, содержащий определение класса Money
using namespace std; // Используем пространство имен std

// Шаблонная функция сортировки массива
template <class T>
void Sort(T array[], size_t size)
{
    int i, j;
    T tmp;
    // Внешний цикл проходит по всем элементам массива, кроме последнего
    for (i = 0; i < size - 1; i++)
        // Внутренний цикл проходит по элементам от конца к началу до i
        for (j = size - 1; i < j; j--)
            // Если текущий элемент больше следующего
            if (array[i] > array[j])
            {
                // Меняем элементы местами
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
}

int main(void)
{
    // Создаем массив объектов Money и инициализируем его значениями
    Money mas[] = { Money(19,10),
                    Money(99,99),
                    Money(99,95),
                    Money(19,95)
    };

    // Вызываем шаблонную функцию сортировки для массива объектов Money
    Sort(mas, sizeof(mas) / sizeof(mas[0]));

    // Выводим отсортированный массив на экран
    for (int i = 0; i < sizeof(mas) / sizeof(mas[0]); i++)
        cout << "mas[" << i << "] =" << mas[i] << endl;

    return 0; // Завершаем программу
}