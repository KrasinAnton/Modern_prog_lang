#include "Money.h"

// Конструктор по умолчанию
Money::Money() : dollars(0), cents(0) {}

// Конструктор с параметрами
Money::Money(long d, int c) : dollars(d), cents(c) {}

// Оператор сравнения "больше"
int Money::operator>(const Money& amt) const
{
    return (dollars > amt.dollars) ||
           ((dollars == amt.dollars) && (cents > amt.cents));
}

// Дружественный оператор вывода
std::ostream& operator<<(std::ostream& os, Money& amt)
{
    os << "$" << amt.dollars << '.' << amt.cents;
    return os;
}