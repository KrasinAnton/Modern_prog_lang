#include <iostream> // Подключаем заголовочный файл для работы с вводом-выводом
#include "Encryptor.h" // Подключаем заголовочный файл с определением класса Encryptor

int main(int argc, char* argv[]) {
    // Проверяем количество аргументов командной строки
    if (argc != 5) {
        std::cout << "Usage: " << argv[0] << " <encrypt|decrypt> <input_file> <output_file> <key>" << std::endl;
        return 1; // Завершаем программу с кодом ошибки
    }

    // Получаем аргументы командной строки
    std::string mode = argv[1]; // Режим работы (encrypt или decrypt)
    std::string inputFile = argv[2]; // Имя входного файла
    std::string outputFile = argv[3]; // Имя выходного файла
    int key = std::stoi(argv[4]); // Ключ шифрования (сдвиг)

    // Создаем объект Encryptor с заданным ключом
    Encryptor encryptor(key);

    // Выполняем действие в зависимости от режима
    if (mode == "encrypt") {
        encryptor.encrypt(inputFile, outputFile); // Шифруем файл
        std::cout << "File encrypted successfully." << std::endl; // Выводим сообщение об успешном шифровании
    } else if (mode == "decrypt") {
        encryptor.decrypt(inputFile, outputFile); // Дешифруем файл
        std::cout << "File decrypted successfully." << std::endl; // Выводим сообщение об успешном дешифровании
    } else {
        std::cerr << "Unknown mode: " << mode << std::endl; // Выводим сообщение об ошибке
        return 1; // Завершаем программу с кодом ошибки
    }

    return 0; // Завершаем программу успешно
}