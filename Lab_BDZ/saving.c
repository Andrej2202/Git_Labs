#include <stdio.h>
#include "items.h"
#include "saving.h"
#include "sys_funcs.h"
#include "player_parametrs.h"


int saving_to_file(){
    FILE *file = fopen("data.txt", "w"); // w - ���������� a - ��������
    if (file == NULL) {
        printf("������ �������� �����\n");
        return 1;
    }

    fprintf(file, "%s|%d|%d", player.name, player.level, player.hp);

    fclose(file);
    return 0;
}


int reading_file(){
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("������ �������� �����\n");
        return 1;
    }
    char result[64];
    fscanf(file, "%s", result);
    printf("%s", result);
    fclose(file);
    return 0;
}