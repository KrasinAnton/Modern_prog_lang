#include "stroka.h"
#include <cstring>
#include <iostream>

using namespace std;

Stroka::Stroka(char *string) {
    str = new char[strlen(string) + 1];
    strcpy(str, string);
}

Stroka::Stroka() {
    str = new char[1];
    str[0] = '\0';
}

Stroka::Stroka(const Stroka& s) {
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}

Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        delete[] str;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    return *this;
}

Stroka& Stroka::operator+(const Stroka& s) {
    char* temp = new char[strlen(str) + strlen(s.str) + 1];
    strcpy(temp, str);
    strcat(temp, s.str);
    delete[] str;
    str = temp;
    return *this;
}

int Stroka::operator==(const Stroka& s) {
    return strcmp(str, s.str) == 0;
}

int Stroka::dlina() {
    return strlen(str);
}

void Stroka::vvod() {
    cin >> str;
}

void Stroka::vyvod() {
    cout << str;
}

Stroka::~Stroka() {
    delete[] str;
}
