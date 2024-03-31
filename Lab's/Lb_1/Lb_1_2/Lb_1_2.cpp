#include <iostream>  

#include <Windows.h> 

template<typename T>
void pointerOperations() {
    T var = 10; // Объявление переменной типа T и присвоение ей значения 10
    T* ptr = &var; // Объявление указателя типа T и присвоение ему адреса переменной var

    std::cout << "Initial value: " << var << std::endl; // Вывод начального значения переменной var
    std::cout << "Pointer address: " << ptr << std::endl; // Вывод адреса, на который указывает ptr
    std::cout << "Value at address: " << *ptr << std::endl; // Вывод значения, на которое указывает ptr

    (*ptr)++; // Увеличение значения, на которое указывает ptr, на единицу
    std::cout << "After incrementing through pointer: " << var << std::endl; // Вывод значения переменной var после инкрементации через указатель

    ptr++; // Увеличение указателя на следующую ячейку памяти
    std::cout << "After incrementing the pointer: " << *ptr << std::endl; // Вывод значения, на которое указывает ptr после инкрементации

    ptr--; // Уменьшение указателя на предыдущую ячейку памяти
    std::cout << "After decrementing the pointer: " << *ptr << std::endl; // Вывод значения, на которое указывает ptr после декрементации

    ptr += 2; // Перемещение указателя на 2 позиции вперед
    std::cout << "After advancing the pointer by 2 positions: " << *ptr << std::endl; // Вывод значения, на которое указывает ptr после сдвига на 2 позиции вперед

    ptr -= 2; // Перемещение указателя на 2 позиции назад
    std::cout << "After moving the pointer back by 2 positions: " << *ptr << std::endl; // Вывод значения, на которое указывает ptr после сдвига на 2 позиции назад
}

int main() {
    std::cout << "Operations with int:" << std::endl; // Вывод заголовка для операций с типом int
    pointerOperations<int>(); // Вызов функции pointerOperations() с параметром int

    std::cout << "\nOperations with double:" << std::endl; // Вывод заголовка для операций с типом double
    pointerOperations<double>(); // Вызов функции pointerOperations() с параметром double

    std::cout << "\nOperations with char:" << std::endl; // Вывод заголовка для операций с типом char
    pointerOperations<char>(); // Вызов функции pointerOperations() с параметром char

    return 0; // Возвращаем ноль, указывая на успешное завершение программы
}
