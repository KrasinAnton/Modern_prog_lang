#include "SingleLinkedList.h" // Подключение заголовочного файла SingleLinkedList.h

using namespace std;

// Конструктор класса SingleLinkedList
SingleLinkedList::SingleLinkedList() : head(nullptr), tail(nullptr) {}

// Деструктор класса SingleLinkedList
SingleLinkedList::~SingleLinkedList() {
    Bus* current = head; // Указатель на текущий узел
    while (current != nullptr) { // Цикл, пока не достигнут конец списка
        Bus* next = current->next; // Сохранение указателя на следующий узел
        delete current; // Удаление текущего узла
        current = next; // Переход к следующему узлу
    }
}

// Функция добавления нового автобуса в список
void SingleLinkedList::addBus(int number, const string& model, const string& driver_name) {
    Bus* newBus = new Bus{number, model, driver_name, nullptr}; // Создание нового узла
    if (head == nullptr) { // Если список пустой
        head = tail = newBus; // Новый узел становится головой и хвостом
    } else {
        tail->next = newBus; // Добавление нового узла в конец списка
        tail = newBus; // Новый узел становится хвостом
    }
}

// Функция вывода всех автобусов в списке
void SingleLinkedList::displayBuses() const {
    Bus* current = head; // Указатель на текущий узел
    while (current != nullptr) { // Цикл, пока не достигнут конец списка
        cout << "Bus number: " << current->number << ", Model: " << current->model << ", Driver: " << current->driver_name << endl;
        current = current->next; // Переход к следующему узлу
    }
}

// Функция удаления автобуса из списка по номеру
bool SingleLinkedList::removeBus(int number) {
    Bus* current = head; // Указатель на текущий узел
    Bus* previous = nullptr; // Указатель на предыдущий узел

    while (current != nullptr && current->number != number) { // Цикл поиска нужного узла
        previous = current;
        current = current->next;
    }

    if (current == nullptr) { // Если узел не найден
        return false;
    }

    if (previous == nullptr) { // Если удаляемый узел является головой
        head = current->next; // Новая голова - следующий узел
    } else {
        previous->next = current->next; // Обход удаляемого узла
    }

    if (current == tail) { // Если удаляемый узел является хвостом
        tail = previous; // Новый хвост - предыдущий узел
    }

    delete current; // Удаление узла
    return true;
}

// Функция поиска автобуса по номеру
Bus* SingleLinkedList::findBus(int number) const {
    Bus* current = head; // Указатель на текущий узел
    while (current != nullptr && current->number != number) { // Цикл поиска нужного узла
        current = current->next;
    }
    return current; // Возвращение указателя на найденный узел или nullptr, если узел не найден
}

int main() {
    SingleLinkedList busList; // Создание экземпляра класса SingleLinkedList
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Add bus\n";
        cout << "2. Remove bus\n";
        cout << "3. Find bus\n";
        cout << "4. Display all buses\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int number;
                string model, driver_name;
                cout << "Enter bus number: ";
                cin >> number;
                cin.ignore();
                cout << "Enter bus model: ";
                getline(cin, model);
                cout << "Enter driver name: ";
                getline(cin, driver_name);
                busList.addBus(number, model, driver_name); // Добавление нового автобуса
                break;
            }
            case 2: {
                int number;
                cout << "Enter bus number to remove: ";
                cin >> number;
                if (busList.removeBus(number)) { // Удаление автобуса по номеру
                    cout << "Bus removed successfully.\n";
                } else {
                    cout << "Bus not found.\n";
                }
                break;
            }
            case 3: {
                int number;
                cout << "Enter bus number to find: ";
                cin >> number;
                Bus* foundBus = busList.findBus(number); // Поиск автобуса по номеру
                if (foundBus != nullptr) {
                    cout << "Bus found: Number: " << foundBus->number << ", Model: " << foundBus->model << ", Driver: " << foundBus->driver_name << endl;
                } else {
                    cout << "Bus not found.\n";
                }
                break;
            }
            case 4:
                busList.displayBuses(); // Вывод всех автобусов в списке
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}