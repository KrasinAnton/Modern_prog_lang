#include <iostream>
#include <cstring>
using namespace std;

// Функция определения длины строки
int stringLength(const char* str) {
    return strlen(str);
}

// Функция копирования строк
void stringCopy(char* destination, const char* source) {
    strcpy(destination, source);
}

// Функция сравнения строк
int stringCompare(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

// Функция конкатенации строк
void stringConcatenate(char* destination, const char* source) {
    strcat(destination, source);
}

int main() {
    char *str1, *str2;

    // Выделение памяти для строк
    str1 = (char*)malloc(100 * sizeof(char));
    str2 = (char*)malloc(100 * sizeof(char));

    // Проверка на успешное выделение памяти
    if (str1 == nullptr || str2 == nullptr) {
        cout << "Ошибка выделения памяти" << endl;
        return 1;
    }

    // Инициализация строк
    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");

    // Использование функций длины строки
    cout << "Длина str1: " << stringLength(str1) << ", str2: " << stringLength(str2) << endl;

    char* str3 = (char*)malloc(20 * sizeof(char)); // Буфер для копии строки

    // Проверка на успешное выделение памяти
    if (str3 == nullptr) {
        cout << "Ошибка выделения памяти" << endl;
        free(str1);
        free(str2);
        return 1;
    }

    // Вызов функции копирования строк
    stringCopy(str3, str1);
    cout << "Результат копирования: str3 = " << str3 << endl;

    // Вызов функции сравнения строк
    cout << "Результат сравнения: str1 и str2 = " << stringCompare(str1, str2) << endl;

    // Вызов функции конкатенации строк
    stringConcatenate(str1, str2);
    cout << "Результат сцепления: str1 = " << str1 << endl;

    // Освобождение выделенной памяти
    free(str1);
    free(str2);
    free(str3);
    return 0;
}
