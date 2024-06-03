#include "stroka.h"    
#include <cstring>     
#include <iostream>    
using namespace std;  

Stroka::Stroka(char *string) {
    str = new char[strlen(string) + 1];  // Выделение памяти для строки
    strcpy(str, string);                  // Копирование переданной строки в выделенную память
}

Stroka::Stroka() {
    str = new char[1];  // Выделение памяти для пустой строки
    str[0] = '\0';       // Установка первого символа как нулевой символ, обозначающий конец строки
}

Stroka::Stroka(const Stroka& s) {
    str = new char[strlen(s.str) + 1];  // Выделение памяти для копии строки
    strcpy(str, s.str);                  // Копирование строки из объекта s в текущий объект
}

Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        delete[] str;                    // Освобождение старой памяти
        str = new char[strlen(s.str) + 1];  // Выделение новой памяти для строки
        strcpy(str, s.str);                  // Копирование строки из объекта s в текущий объект
    }
    return *this;  // Возврат ссылки на текущий объект для поддержки цепочки присваиваний
}

Stroka& Stroka::operator+(const Stroka& s) {
    char* temp = new char[strlen(str) + strlen(s.str) + 1];  // Выделение временной памяти для конкатенации строк
    strcpy(temp, str);                  // Копирование текущей строки во временную переменную
    strcat(temp, s.str);                // Добавление к текущей строке строки из объекта s
    delete[] str;                       // Освобождение старой памяти
    str = temp;                         // Присвоение новой строки текущему объекту
    return *this;                       // Возврат ссылки на текущий объект для поддержки цепочки операций
}

int Stroka::operator==(const Stroka& s) {
    return strcmp(str, s.str) == 0;     // Сравнение текущей строки с строкой из объекта s и возврат результата
}

int Stroka::dlina() {
    return strlen(str);                 // Возвращение длины строки
}

void Stroka::vvod() {
    cin >> str;                         // Стандартный ввод строки из консоли
}

void Stroka::vyvod() {
    cout << str;                        // Стандартный вывод строки в консоль
}

Stroka::~Stroka() {
    delete[] str;                       // Освобождение памяти, выделенной для строки при уничтожении объекта
}

