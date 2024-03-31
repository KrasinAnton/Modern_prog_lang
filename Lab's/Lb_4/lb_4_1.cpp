#include <iostream>
#include <cstring> // Для работы с функциями строки в C
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
    char str1[] = "qwerty";
    char str2[] = "1234567890";

    // Использование функций длины строки
    cout << "Длина str1: " << stringLength(str1) << ", str2: " << stringLength(str2) << endl;

    char str3[20]; // Буфер для копии строки
    // Вызов функции копирования строк
    stringCopy(str3, str1);
    cout << "Результат копирования: str3 = " << str3 << endl;

    // Вызов функции сравнения строк
    cout << "Результат сравнения: str1 и str2 = " << stringCompare(str1, str2) << endl;

    // Вызов функции конкатенации строк
    stringConcatenate(str1, str2);
    cout << "Результат сцепления: str1 = " << str1 << endl;

    return 0;
}
