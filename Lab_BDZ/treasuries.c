#include <stdlib.h>
#include "sys_funcs.h"
#include "treasuries.h"
#include "text_blocks.h"

item possible[3] = { // 0 - зашита, 1 - оружие, 2 - предметы
    {"Шлем", 0, 2},
    {"Меч", 1, 0},
    {"Малая хилка", 0, 10}
};

void give_treasuries(){
    int way = rand() % 2;
    if(way == 0){
        empty_dungeon_text();
    }
    else{
        treasuries_dungeon_text();
    }
}