#include "Encryptor.h"
#include <fstream> // Подключаем заголовочный файл для работы с файлами
#include <iostream> // Подключаем заголовочный файл для работы с вводом-выводом

// Конструктор с параметром key для задания сдвига
Encryptor::Encryptor(int key) : key(key) {}

// Метод шифрования файла
void Encryptor::encrypt(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile); // Открываем входной файл
    std::ofstream outFile(outputFile); // Открываем выходной файл
    
    if (!inFile || !outFile) { // Проверяем, открылись ли файлы
        std::cerr << "Error opening files." << std::endl; // Сообщаем об ошибке открытия файлов
        return;
    }

    char c;
    while (inFile.get(c)) { // Читаем символы из входного файла
        outFile.put(shiftChar(c, key)); // Пишем зашифрованные символы в выходной файл
    }
}

// Метод дешифрования файла
void Encryptor::decrypt(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile); // Открываем входной файл
    std::ofstream outFile(outputFile); // Открываем выходной файл

    if (!inFile || !outFile) { // Проверяем, открылись ли файлы
        std::cerr << "Error opening files." << std::endl; // Сообщаем об ошибке открытия файлов
        return;
    }

    char c;
    while (inFile.get(c)) { // Читаем символы из входного файла
        outFile.put(shiftChar(c, -key)); // Пишем дешифрованные символы в выходной файл
    }
}

// Вспомогательный метод для сдвига символа
char Encryptor::shiftChar(char c, int shift) {
    if (isalpha(c)) { // Проверяем, является ли символ буквой
        char base = islower(c) ? 'a' : 'A'; // Определяем базовый символ для сдвига
        return (c - base + shift + 26) % 26 + base; // Сдвигаем символ
    }
    
    return c; // Возвращаем символ без изменений, если он не является буквой
}