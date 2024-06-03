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
    const int SIZE = 3;
    const char* strings[SIZE] = {"Hello", "World", "C++"};

    // Применение функции определения длины строки к элементам массива строк
    for (int i = 0; i < SIZE; ++i) {
        cout << "Длина строки " << i + 1 << ": " << stringLength(strings[i]) << endl;
    }

    // Применение функции копирования строк к элементам массива строк
    char copiedStrings[SIZE][20]; // массив для хранения копий строк
    for (int i = 0; i < SIZE; ++i) {
        stringCopy(copiedStrings[i], strings[i]);
        cout << "Копия строки " << i + 1 << ": " << copiedStrings[i] << endl;
    }

    // Применение функции сравнения строк к первым двум элементам массива строк
    cout << "Результат сравнения строк 1 и 2: " << stringCompare(strings[0], strings[1]) << endl;

    // Применение функции конкатенации строк ко всем элементам массива строк
    char concatenatedString[100] = "";
    for (int i = 0; i < SIZE; ++i) {
        stringConcatenate(concatenatedString, strings[i]);
    }
    cout << "Результат конкатенации: " << concatenatedString << endl;
    return 0;
}
