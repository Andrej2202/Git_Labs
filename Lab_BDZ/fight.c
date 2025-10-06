#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "fight.h"
#include "items.h"
#include "sys_funcs.h"
#include "text_blocks.h"
#include "player_parametrs.h"


int fight(int lvl){ 
    mob_dungeon_text();
    int cube;
    int mob_maxHealth = lvl * 5, mob_health = lvl * 5;
    clear_input();
    clear_input();
    while(get_mathInfo("hp") > 0 ){
        clear_screen();
        printf("���� ��: %d/%d, �� ���� %d/%d\n\n", get_mathInfo("hp"), get_mathInfo("max_hp"), mob_health, mob_maxHealth);
        cube = rand() % 6  + 1;
        mob_health -= cube;
        printf("�� ������ ������� � �� ������� %d��\n", cube);
        clear_input();
        if(mob_health <= 0){
            printf("������ ���������� � ����\n\n");
            int temp_lvl = get_mathInfo("level"), temp_hp = get_mathInfo("max_hp"), temp_strenght = get_mathInfo("strength");
            change_player_param("xp", lvl * 5);
            printf("����� ������� %d xp �� ������\n", lvl * 5);
            if(temp_lvl!= get_mathInfo("level")){
                int count_heals = get_mathInfo("level") - temp_lvl;
                printf("������� ��������� ������� %d -> %d\n", temp_lvl, get_mathInfo("level"));
                printf("����� ������� %d ������� �����\n", count_heals);
                for(int i = 0; i < count_heals; i++){
                    add_to_inv("������� �����", 20);
                }
                printf("���������� �������������� ���������: ������������ �� - %d -> %d, ������� ���� %d -> %d\n", temp_hp, get_mathInfo("max_hp"), temp_strenght, get_mathInfo("strength"));
            }
            clear_input();
            return 1;
        }
        printf("������ ������ ����� � ������ ������ ������� ����.\n");
        printf("�� ������� %d��\n", cube);
        change_player_param("hp", -1 * cube);
        clear_input();
        
    }
    return 0;
}