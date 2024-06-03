#include "Stroka.h" // Подключаем заголовочный файл, содержащий объявление класса Stroka
#include <cstring> // Подключаем заголовочный файл для работы с C-строками
#include <iostream> // Подключаем заголовочный файл для работы с вводом-выводом
using namespace std; // Используем пространство имен std

int main(void)
{
    // Создаем объект s класса Stroka и инициализируем его строкой "Hello, world!"
    Stroka s("Hello, World!");
    std::cout << s << std::endl; // Выводим строку s на экран
    std::cin >> s; // Читаем строку s с клавиатуры
    
    std::cout << "Vi vveli: " << s << std::endl; // Выводим введенную строку

    // Создаем объекты s1, s3, s4 и s5 класса Stroka
    Stroka s1("qwerty"), s3, s4(s1), s5;

    s3.vvod(); // Вводим строку s3 с клавиатуры
    s3.vyvod(); // Выводим строку s3 на экран
    cout << "\n";
    s3 = "LOL"; // Присваиваем строке s3 значение "LOL"
    s3.vyvod(); // Выводим строку s3 на экран
    cout << "\n";
    s5 = s1 + s3 + s4; // Конкатенируем строки s1, s3 и s4 и присваиваем результат s5
    // Выводим длину строки s5
    cout << "Dlina s5 = " << dlinal(const_cast<char*>(s5.getStr())); 
    cout << "\nVyvod s5\n";
    s5.vyvod(); // Выводим строку s5 на экран
    cout << "\n";

    // Выводим длину строки s1
    cout << "Dlina s1 = " << dlinal(const_cast<char*>(s1.getStr())); 
    cout << "\n";
    s1.vyvod(); // Выводим строку s1 на экран
    cout << "\n";

    s1.sravn(s5.getStr()); // Сравниваем строку s1 со строкой s5
    s1.sravn(s4.getStr()); // Сравниваем строку s1 со строкой s4
    char str[] = "Some string to copy or concatenate"; // Создаем строку str
    s1.kopir(str); // Копируем строку str в s1
    s1.vyvod(); // Выводим строку s1 на экран
    std::cout << "\n";

    s1.konkat(str); // Конкатенируем строку str к строке s1
    s1.vyvod(); // Выводим строку s1 на экран
    std::cout << "\n";
    return 0; // Завершаем программу
}