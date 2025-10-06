#include <stdlib.h>
#include "sys_funcs.h"
#include "treasuries.h"
#include "text_blocks.h"

item possible[3] = { // application 0 - armour; 1 - weapon; 2 - smt to inventory;
    {"Шлем", 0, 2, 0, 0},
    {"Меч", 1, 0, 0, 10},
    {"Малая хилка", 0, 0, 10, 0}
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