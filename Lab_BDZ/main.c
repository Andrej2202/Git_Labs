#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys_funcs.h"
#include "dungeon_logic.h"

int main(){
    char enter, text[] = "начать программу";
    int check = 0;
    srand(time(NULL));
    while(check == 0){
        yes_no_input(&enter, text);
        if(enter == 'y' || enter == 'Y'){
            check = dungeon_exploring();
        }
        else{
            return 0;
        }
    };
    return 0;
}

