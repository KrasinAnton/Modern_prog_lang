#ifndef STROKA_H
#define STROKA_H
#include <iostream> // Подключаем заголовочный файл для работы с вводом-выводом

class Stroka {
    char* str; // Указатель на динамически выделенную память для строки

public:
    // Конструктор с C-строкой
    Stroka(const char*);

    // Конструктор по умолчанию
    Stroka();

    // Конструктор копирования
    Stroka(const Stroka&);

    // Оператор присваивания для класса Stroka
    Stroka& operator=(const Stroka&);

    // Оператор присваивания для C-строки
    Stroka& operator=(const char*);

    // Оператор сложения строк
    Stroka operator+(const Stroka&);

    // Оператор сравнения строк
    int operator==(const Stroka&);

    // Метод ввода строки
    void vvod();

    // Метод вывода строки
    void vyvod();

    // Метод сравнения строк
    void sravn(const char* str2);

    // Метод для получения строки
    const char* getStr() const {
        return str;
    }

    // Метод копирования строки
    void kopir(char* src);

    // Метод конкатенации строк
    void konkat(char* src);

    // Конструктор с указанием размера
    Stroka(int size);

    // Деструктор
    ~Stroka();

    // Дружественный оператор вывода
    friend std::ostream& operator<<(std::ostream& out, const Stroka& s) {
        out << s.getStr();
        return out;
    }

    // Дружественный оператор ввода
    friend std::istream& operator>>(std::istream& in, Stroka& s) {
        char temp[256];
        in.getline(temp, 256);
        s = temp; // Присваивание введенной строки объекту Stroka
        return in;
    }
};

// Функция для получения длины строки
int dlinal(const char* str);

#endif // STROKA_H