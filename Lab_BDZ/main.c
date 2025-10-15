#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "sys_funcs.h"


//#include "items.h"

int main(){
    //armour_show();
    char enter;
    srand(time(NULL));
    while(1){
        start_program(&enter);
        if(enter == 'y' || enter == 'Y'){
            start();
        }
        else{
            return 0;
        }
        
    };
}

