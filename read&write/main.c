#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "w"); // w - ���������� a - ��������
    if (file == NULL) {
        printf("������ �������� �����\n");
        return 1;
    }

    fprintf(file, "���: ����\n");
    fprintf(file, "�������: 25\n");
    fprintf(file, "�����: ������\n");

    fclose(file);

    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("������ �������� �����\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}