#include <stdio.h>
#include <stdlib.h> 

void clear_input(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear"); 
#endif
}