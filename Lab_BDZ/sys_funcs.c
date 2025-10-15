#include <stdio.h>
#include <stdlib.h> 

int clear_input(){
    int c, counter = 0;
    while ((c = getchar()) != '\n' && c != EOF){
        counter++;
    }
    return counter;
}

void start_program(char* enter){
    int res = 0;
    do
    {
        printf("Хочешь начать программу? (y/n): ");
        scanf(" %c",  enter);
        res = clear_input();
    }while((*enter != 'n' && *enter != 'N' && *enter != 'y' && *enter != 'Y') || res !=0);
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear"); 
#endif
}