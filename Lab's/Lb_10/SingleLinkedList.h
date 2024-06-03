#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
#include <iostream>
#include <string>

// Структура Bus для представления автобуса
struct Bus {
    int number; // Номер автобуса
    std::string model; // Модель автобуса
    std::string driver_name; // Имя водителя
    Bus* next; // Указатель на следующий узел в списке
};

// Класс SingleLinkedList для представления односвязного списка автобусов
class SingleLinkedList {
private:
    Bus* head; // Указатель на голову списка
    Bus* tail; // Указатель на хвост списка

public:
    SingleLinkedList(); // Конструктор
    ~SingleLinkedList(); // Деструктор

    // Метод для добавления нового автобуса в конец списка
    void addBus(int number, const std::string& model, const std::string& driver_name);

    // Метод для вывода всех автобусов в списке
    void displayBuses() const;

    // Метод для удаления автобуса из списка по номеру
    bool removeBus(int number);

    // Метод для поиска автобуса в списке по номеру
    Bus* findBus(int number) const;
};

#endif // SINGLE_LINKED_LIST_H