#include <stdlib.h>
#include <stdio.h>
#include "sys_funcs.h"
#include "treasuries.h"
#include"person_items.h"
#include "text_blocks.h"

void give_treasuries(){
    item possible[6] = { // 0 - ������, 1 - ������, 2 - ��������
        {"����", 0, 20},
        {"������", 0, 50},
        {"������", 0, 10},
        {"���", 1, 40},
        {"����� �����", 2, 10},
        {"������� �����", 2, 20}
    };
    int way = rand() % 2, item_num = rand() % 6;
    if(way == 0){
        empty_dungeon_text();
    }
    else{
        treasuries_dungeon_text(possible[item_num].name);
        if(possible[item_num].class == 0){

        }
        else if(possible[item_num].class == 1){

        }
        else{
            add_to_inv(possible[item_num].name, possible[item_num].param);
        }
    }
}