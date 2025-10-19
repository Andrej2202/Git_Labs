#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "person_items.h"

#include "sys_funcs.h"
#include "saving.h"


//#include "items.h"

int main(){

    /*
    class_pick;
    add_to_inv("Большая_хилка", 10);
    save_to_file(0);
    read_file();
    */



    //armour_show();
    /*
    for(int i = 0; i < 10; i++){
        add_to_inv("Большая хилка", 10);
    }
    open_inventory();
    add_to_inv("Мини хилка", 10);
    open_inventory();
    */
    char enter, text[] = "начать программу";
    srand(time(NULL));
    while(1){
        yes_no_input(&enter, text);
        if(enter == 'y' || enter == 'Y'){
            start();
        }
        else{
            return 0;
        }
        
    };
    
}

