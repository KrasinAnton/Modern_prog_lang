// Lab9Task2Prog9.1.3.cpp : 2. Выполнить примеры из п.п. 9.1.2 и 9.1.3.
// Программа из пункта 9.1.3

#include <iostream>
#include <cstring>
using namespace std;

template <class T>
T getmax(T t1, T t2)
{
	return t1 > t2 ? t1 : t2;
}
const char* getmax(const char* s1, const char* s2)
{
	return strcmp(s1, s2) > 0 ? s1 : s2;
}
template <class T>// Подключение заголовочных файлов iostream для ввода/вывода
// и cstring для работы с строками
#include <iostream>
#include <cstring>
using namespace std;

// Шаблонная функция getmax для возврата большего из двух значений
template <class T>
T getmax(T t1, T t2)
{
    return t1 > t2 ? t1 : t2; // Тернарный оператор для возврата большего значения
}

// Специализация функции getmax для строк
const char* getmax(const char* s1, const char* s2)
{
    return strcmp(s1, s2) > 0 ? s1 : s2; // Возвращает строку, которая больше в лексикографическом порядке
}

// Перегруженная шаблонная функция getmax для возврата максимального значения из массива
template <class T>
T getmax(T t[], size_t size)
{
    T retval = t[0]; // Начальное значение максимума - первый элемент массива
    int i;
    for (i = 0; i < size; i++)
        if (t[i] > retval) retval = t[i]; // Обновление максимума, если найден больший элемент
    return retval; // Возврат найденного максимального значения
}

int main()
{
    int i1 = 3, i2 = 5; // Объявление и инициализация целочисленных переменных
    const char* s1 = "stroka1"; // Объявление и инициализация строковых указателей
    const char* s2 = "stroka2";

    cout << "max int = " << getmax(i1, i2) << endl; // Вызов шаблонной функции getmax для целых чисел
    cout << "max str = " << getmax(s1, s2) << endl; // Вызов специализации getmax для строк

    return 0;
}
T getmax(T t[], size_t size)
{
	T retval = t[0];
	int i;
	for (i = 0; i < size; i++)
		if (t[i] > retval) retval = t[i];
	return retval;
}
int main()
{
	int i1 = 3, i2 = 5;
	const char* s1 = "stroka1";
	const char* s2 = "stroka2";
	cout << "max int = " << getmax(i1, i2) << endl;
	cout << "max str = " << getmax(s1, s2) << endl;
	return 0;
}


