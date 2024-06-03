﻿#include <iostream> // Подключаем заголовочный файл для работы с вводом-выводом
#include <cstring> // Подключаем заголовочный файл для работы с C-строками
#include <iomanip> // Подключаем заголовочный файл для использования манипулятора std::hex
using namespace std; // Используем пространство имен std

// Шаблонная функция, возвращающая большее из двух значений
template <class T>
T getmax(T t1, T t2)
{
    return t1 > t2 ? t1 : t2; // Если t1 больше t2, возвращаем t1, иначе возвращаем t2
}

// Специализация функции getmax для строк
const char* getmax(const char* s1, const char* s2)
{
    return strcmp(s1, s2) > 0 ? s1 : s2; // Сравниваем строки и возвращаем большее значение
}

// Шаблонная функция, возвращающая максимальный элемент в массиве
template <class T>
T getmax(T t[], size_t size)
{
    T retval = t[0]; // Инициализируем retval первым элементом массива
    for (int i = 0; i < size; i++) // Проходим по всем элементам массива
        if (t[i] > retval) retval = t[i]; // Обновляем retval, если текущий элемент больше
    return retval; // Возвращаем максимальный элемент
}

int main()
{
    int i1 = 3, i2 = 5; // Инициализируем две целочисленные переменные
    const char* s1 = "stroka1"; // Инициализируем первую строку
    const char* s2 = "stroka2"; // Инициализируем вторую строку

    // Изменение состояния потока std::cout
    cout.flags(std::ios_base::hex); // Установка флага для вывода чисел в шестнадцатеричной системе счисления

    // Вывод максимального значения целого числа
    cout << "max int = " << getmax(i1, i2) << endl;

    // Изменение состояния потока std::cout
    cout.width(10); // Установка ширины поля вывода для строк

    // Вывод максимальной строки
    cout << "max str = " << getmax(s1, s2) << endl;

    return 0; // Завершаем программу
}