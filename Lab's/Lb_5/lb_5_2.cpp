#include <stdio.h>

#include <ctype.h> // Для функции isprint()

int main(void) {
    char ch;
    char name[50];
    FILE *in;
    int emptyCount = 0; // Счетчик "пустых" символов
    int nonEmptyCount = 0; // Счетчик "непустых" символов

    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);

    if ((in = fopen(name, "r")) == NULL) {
        printf("Файл %s не открыт\n", name);
        return 1; // Выход из программы с кодом ошибки
    }

    while ((ch = getc(in)) != EOF) {
        if (isprint(ch)) { // Проверка, является ли символ отображаемым
            putchar(ch);
            nonEmptyCount++;
        } else {
            emptyCount++;
        }
    }

    printf("\n\nКоличество 'пустых' символов: %d\n", emptyCount);
    printf("Количество 'непустых' символов: %d\n", nonEmptyCount);

    fclose(in); // Закрыть файл

    return 0; // Выход из программы без ошибок
}
