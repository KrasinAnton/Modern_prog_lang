#include <stdio.h>

int main(void) {
    char ch;
    char name[50];
    FILE *in;

    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);

    if ((in = fopen(name, "r")) == NULL) {
        printf("Файл %s не открыт\n", name);
        return 1; // Выход из программы с кодом ошибки
    }

    while ((ch = getc(in)) != EOF) {
        putchar(ch);
    }

    fclose(in); // Закрыть файл
    return 0; // Выход из программы без ошибок
}
