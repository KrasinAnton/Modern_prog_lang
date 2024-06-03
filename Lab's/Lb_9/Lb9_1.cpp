// Подключение заголовочного файла iostream для ввода/вывода
#include <iostream>
using namespace std;

// Шаблонная функция Sort для сортировки массива типа T
template <class T>
void Sort(T array[], size_t size)
{
    int i, j;
    T tmp;
    // Внешний цикл проходит по массиву от начала до предпоследнего элемента
    for (i = 0; i < size - 1; i++)
        // Внутренний цикл проходит по массиву от конца к текущему элементу внешнего цикла
        for (j = size - 1; i < j; j--)
            // Если текущий элемент больше следующего, меняем их местами
            if (array[i] > array[j])
            {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
}

// Класс Money для представления денежной суммы
class Money
{
    long dollars; // Количество долларов
    int cents;    // Количество центов
public:
    Money() {} // Конструктор по умолчанию
    Money(long d, int c) // Конструктор с параметрами
    {
        dollars = d;
        cents = c;
    }
    // Перегрузка оператора > для сравнения двух объектов Money
    int operator > (const Money&) const;
    // Дружественная функция для вывода объекта Money в поток
    friend ostream& operator << (ostream&, Money&);
};

// Реализация перегрузки оператора >
int Money::operator>(const Money& amt) const
{
    return
        (dollars > amt.dollars) ||
        ((dollars == amt.dollars) && (cents > amt.cents));
}

// Реализация дружественной функции для вывода объекта Money в поток
ostream& operator<<(ostream& os, Money& amt)
{
    os << "$" << amt.dollars << '.' << amt.cents;
    return os;
}

int main(void)
{
    // Создание массива объектов Money
    Money mas[] = { Money(19,10),
                    Money(99,99),
                    Money(99,95),
                    Money(19,95)
    };

    // Вызов функции Sort для сортировки массива mas
    Sort(mas, sizeof(mas) / sizeof(mas[0]));

    // Вывод отсортированного массива
    for (int i = 0; i < sizeof(mas) / sizeof(mas[0]); i++)
        cout << "mas[" << i << "] =" << mas[i] << endl;
}