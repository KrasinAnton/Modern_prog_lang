#ifndef MONEY_H
#define MONEY_H

#include <iostream> // Подключаем заголовочный файл для работы с вводом-выводом

// Объявление класса Money
class Money
{
    long dollars; // Переменная для хранения значения долларов
    int cents;    // Переменная для хранения значения центов
public:
    Money(); // Конструктор по умолчанию
    Money(long d, int c); // Конструктор с параметрами для инициализации долларов и центов
    int operator > (const Money&) const; // Оператор сравнения "больше"
    friend std::ostream& operator << (std::ostream&, Money&); // Дружественный оператор вывода
};

#endif // MONEY_H