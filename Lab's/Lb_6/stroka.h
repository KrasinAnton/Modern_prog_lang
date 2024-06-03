#ifndef STROKA_H
#define STROKA_H
#include <iostream>

class Stroka {
private:
    char* str;
public:
    Stroka(char*);
    Stroka();
    Stroka(const Stroka&);
    Stroka& operator=(const Stroka&); // Добавлен прототип оператора присваивания
    Stroka& operator+(const Stroka&);
    int operator==(const Stroka&);
    int dlina();
    void vvod();
    void vyvod();
    ~Stroka();
};

#endif // STROKA_H
