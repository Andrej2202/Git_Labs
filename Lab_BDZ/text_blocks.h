#ifndef TEXT_BLOCKS_H
#define TEXT_BLOCKS_H
#include "dungeon_logic.h"

void class_pick_text(Parametrs *player);


void entering_dungeons_text(Parametrs *player);
void each_dungeon_text(int current_dungeon);
void empty_dungeon_text();


void treasuries_dungeon_text();


void mob_dungeon_text();

void end_of_base_dungeons();
void boss_dungeon_text(int *class);
void end_of_phase_1_text();
void phase_2_text();


void good_end_text();
void bad_end_text();
#endif