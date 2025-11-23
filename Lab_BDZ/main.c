#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys_funcs.h"
#include "dungeon_logic.h"

// Dear programmist:
// When i was writing this code 
// only God and i knew how it works.
// Now only God khows
//
// However if you're trying
// to optimize smth
// and you won't succeed(most likely)
// please increase counter values
// as warning to the next person.
//
// vsego_chasov_potracheno_zdes = 254




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

