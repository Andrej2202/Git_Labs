#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "w"); // w - перезапись a - дозапись
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    fprintf(file, "Имя: Иван\n");
    fprintf(file, "Возраст: 25\n");
    fprintf(file, "Город: Москва\n");

    fclose(file);

    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}