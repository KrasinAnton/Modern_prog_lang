// Подключение заголовочного файла iostream для ввода/вывода
#include <iostream>
using namespace std;

// Шаблонный класс Tstack для представления стека
template <class T>
class Tstack {
protected:
    int numItem; // Количество элементов в стеке
    T *item;     // Массив для хранения элементов стека
public:
    Tstack(size_t size = 10) // Конструктор с параметром размера (по умолчанию 10)
    {
        numItem = 0;
        item = new T[size];
    }
    ~Tstack() // Деструктор для освобождения памяти
    {
        delete[] item;
    }
    void push(T t); // Функция для добавления элемента в стек
    T pop();        // Функция для извлечения элемента из стека

    bool isEmpty() const { // Метод для проверки, пуст ли стек
        return numItem == 0;
    }

    T top() const { // Метод для получения верхнего элемента стека без извлечения
        return item[numItem - 1];
    }
};

// Реализация функции push для добавления элемента в стек
template <class T>
void Tstack <T>::push(T t)
{
    item[numItem++] = t;
}

// Реализация функции pop для извлечения элемента из стека
template <class T>
T Tstack <T>::pop()
{
    return item[--numItem];
}

// Функция для сортировки железнодорожного состава с использованием тупика
template <class T>
void sortRailway(Tstack<T>& inputStack) {
    Tstack<T> outputStack; // Создаем стек для отсортированных вагонов
    Tstack<T> sidetrack;   // Создаем стек для временного хранения вагонов

    T currentExpected = 1; // Переменная для хранения ожидаемого вагона

    while (!inputStack.isEmpty()) {
        T current = inputStack.pop(); // Берем верхний вагон из входного стека

        if (current == currentExpected) {
            outputStack.push(current); // Если вагон соответствует ожидаемому порядку, помещаем его в выходной стек
            currentExpected++;         // Увеличиваем ожидаемый вагон
        }
        else {
            sidetrack.push(current); // Иначе помещаем вагон в тупик
        }

        // Перемещаем вагоны из тупика в выходной стек, если это возможно
        while (!sidetrack.isEmpty() && sidetrack.top() == currentExpected) {
            outputStack.push(sidetrack.pop());
            currentExpected++;
        }
    }

    // Выводим отсортированный железнодорожный состав
    cout << "Отсортированный состав: ";
    while (!outputStack.isEmpty()) {
        cout << outputStack.pop() << " ";
    }
    cout << endl;
}

int main() {
    // Пример использования
    Tstack<int> inputStack; // Создаем стек для входного железнодорожного состава

    // Заполняем входной железнодорожный состав (порядок произвольный)
    inputStack.push(3);
    inputStack.push(1);
    inputStack.push(2);
    inputStack.push(4);
    inputStack.push(5);

    // Сортируем железнодорожный состав и выводим результат
    sortRailway(inputStack);

    return 0;
}