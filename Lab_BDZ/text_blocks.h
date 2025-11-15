#ifndef TEXT_BLOCKS_H
#define TEXT_BLOCKS_H
#include "dungeon_logic.h"

void class_pick_text(Parametrs *player);
void entering_dungeons_text(Parametrs *player);
void each_dungeon_text(int current_dungeon);
void empty_dungeon_text();
void treasuries_dungeon_text(char *item);
void mob_dungeon_text();
void game_end_text(int end);

#endif