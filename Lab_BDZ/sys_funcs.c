#include <stdio.h>
#include <stdlib.h> 

void clear_input(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void enter_expect(){
    int c;
    while ((c = getchar()) != '\n');
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear"); 
#endif
}