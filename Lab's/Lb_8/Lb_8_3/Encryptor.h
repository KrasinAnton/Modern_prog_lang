#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <string>

// Класс Encryptor для шифрования и дешифрования текста
class Encryptor {
public:
    Encryptor(int key); // Конструктор с параметром key для задания сдвига
    void encrypt(const std::string& inputFile, const std::string& outputFile); // Метод шифрования файла
    void decrypt(const std::string& inputFile, const std::string& outputFile); // Метод дешифрования файла

private:
    int key; // Ключ шифрования
    char shiftChar(char c, int shift); // Вспомогательный метод для сдвига символа
};

#endif // ENCRYPTOR_H