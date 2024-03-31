#include <iostream>  

#include <Windows.h> 
int power(int base, int exponent); // Объявляем прототип функции power()

int main() {
    int base, exponent;

    std::cout << "Введите основание: "; // Выводим приглашение на ввод основания
    std::cin >> base; // Считываем основание с консоли

    std::cout << "Введите показатель степени: "; // Выводим приглашение на ввод показателя степени
    std::cin >> exponent; // Считываем показатель степени с консоли

    int result = power(base, exponent); // Вычисляем результат возведения в степень

    std::cout << base << " в степени " << exponent << " = " << result << std::endl; // Выводим результат

    return 0; // Возвращаем ноль, указывая на успешное завершение программы
}

int power(int base, int exponent) { // Определение функции power() для возведения в степень
    int result = 1; // Инициализируем результат значением 1

    for (int i = 0; i < exponent; i++) { // Цикл для умножения основания на себя exponent раз
        result *= base;
    }

    return result; // Возвращаем результат возведения в степень
}
