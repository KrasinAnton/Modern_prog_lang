#include "stroka.h"
#include <iostream>

using namespace std;

int main() {
    char str1[] = "qwert";
    char str2[] = "sl";
    char str3[] = "asdfg";
    
    // Создание объектов класса Stroka с использованием различных конструкторов
    Stroka s1(str1), s3, s4(str2), s5;
    
    // Ввод строки с клавиатуры
    s3.vvod();
    
    // Присвоение значения строки
    s3 = str3;
    
    // Вывод строки на экран
    s3.vyvod();
    
    // Конкатенация строк и присвоение результата
    s5 = s1 + s3 + s4;
    
    // Вывод длины и содержимого строки s5
    cout << "Длина s5 = " << s5.dlina();
    s5.vyvod();
    
    // Сравнение строк s1 и s5
    cout << "Строки s1 и s5 равны: ";
    if (s1 == s5)
        cout << "да";
    else
        cout << "нет";
    return 0;
}
