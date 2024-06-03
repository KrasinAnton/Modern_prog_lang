#include "Stroka.h" // Подключаем заголовочный файл, содержащий объявление класса Stroka
#include <cstring> // Подключаем заголовочный файл для работы с C-строками
#include <iostream> // Подключаем заголовочный файл для работы с вводом-выводом
using namespace std; // Используем пространство имен std

// Конструктор по умолчанию
Stroka::Stroka() {
    str = new char[80]; // Выделяем память для строки размером 80 символов
    str[0] = '\0'; // Инициализируем пустую строку
}

// Конструктор с указанием размера
Stroka::Stroka(int size) {
    str = new char[size + 1]; // Выделяем память для строки с указанным размером
    str[0] = '\0'; // Инициализируем пустую строку
}

// Деструктор
Stroka::~Stroka() {
    delete[] str; // Освобождаем память, выделенную под строку
}

// Метод копирования строки
void Stroka::kopir(char* src) {
    delete[] str; // Освобождаем старую память
    str = new char[strlen(src) + 1]; // Выделяем новую память для строки
    char* dest = str; // Указатель на начало строки назначения
    while (*src != '\0') { // Копируем символы из исходной строки в новую
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Завершаем строку нулевым символом
}

// Метод конкатенации строк
void Stroka::konkat(char* src) {
    int len1 = strlen(str);
    int len2 = strlen(src);
    if (len1 + len2 >= strlen(str)) { // Если текущая строка недостаточно велика
        char* temp = new char[len1 + len2 + 1]; // Выделяем новую память
        char* dest = temp; // Указатель на начало новой строки
        char* source = str; // Указатель на начало старой строки
        while (*source != '\0') { // Копируем старую строку в новую
            *dest = *source;
            dest++;
            source++;
        }
        source = src; // Указатель на начало строки для конкатенации
        while (*source != '\0') { // Копируем строку для конкатенации в новую
            *dest = *source;
            dest++;
            source++;
        }
        *dest = '\0'; // Завершаем строку нулевым символом
        delete[] str; // Освобождаем старую память
        str = temp; // Указатель на новую строку
    } else { // Если текущая строка достаточно велика
        char* dest = str + len1; // Указатель на конец текущей строки
        while (*src != '\0') { // Конкатенируем строки
            *dest = *src;
            dest++;
            src++;
        }
        *dest = '\0'; // Завершаем строку нулевым символом
    }
}

// Метод сравнения строк
void Stroka::sravn(const char* str2) {
    const char* str1 = str; // Указатель на текущую строку
    while (*str1 == *str2) { // Сравниваем строки посимвольно
        if (*str1 == '\0') { // Если достигнут конец строки
            std::cout << "Stroki ravni" << std::endl;
            return;
        }
        str1++;
        str2++;
    }
    std::cout << "Stroki ne ravni" << std::endl;
}

// Конструктор с C-строкой
Stroka::Stroka(const char* string) {
    str = new char[strlen(string) + 1]; // Выделяем память для новой строки
    strcpy_s(str, strlen(string) + 1, string); // Копируем исходную строку
}

// Конструктор копирования
Stroka::Stroka(const Stroka& s) {
    str = new char[strlen(s.str) + 1]; // Выделяем память для новой строки
    strcpy_s(str, strlen(s.str) + 1, s.str); // Копируем строку
}

// Оператор присваивания для класса Stroka
Stroka& Stroka::operator=(const Stroka& s) {
    if (this == &s) // Проверка самоприсваивания
        return *this;
    delete[] str; // Освобождаем старую память
    str = new char[strlen(s.str) + 1]; // Выделяем новую память
    strcpy_s(str, strlen(s.str) + 1, s.str); // Копируем строку
    return *this;
}

// Оператор присваивания для C-строки
Stroka& Stroka::operator=(const char* s) {
    delete[] str; // Освобождаем старую память
    str = new char[strlen(s) + 1]; // Выделяем новую память
    strcpy_s(str, strlen(s) + 1, s); // Копируем строку
    return *this;
}

// Оператор сложения строк
Stroka Stroka::operator+(const Stroka& s) {
    Stroka result; // Создаем новый объект Stroka
    result.str = new char[strlen(str) + strlen(s.str) + 1]; // Выделяем память для новой строки
    strcpy_s(result.str, strlen(str) + 1, str); // Копируем первую строку
    strcat_s(result.str, strlen(result.str) + strlen(s.str) + 1, s.str); // Конкатенируем вторую строку
    return result; // Возвращаем новый объект Stroka
}

// Оператор сравнения строк
int Stroka::operator==(const Stroka& s) {
    return strcmp(str, s.str) == 0; // Сравниваем строки
}

// Метод ввода строки
void Stroka::vvod() {
    cin.getline(str, 80); // Ввод строки с клавиатуры
}

// Метод вывода строки
void Stroka::vyvod() {
    cout << str; // Вывод строки на экран
}

// Функция для получения длины строки
int dlinal(const char* str) {
    return strlen(str); // Возвращаем длину строки
}