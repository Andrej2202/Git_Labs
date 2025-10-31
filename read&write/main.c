#include <stdio.h>
int clear_input(){
    int c, counter = 0;
    while ((c = getchar()) != '\n' && c != EOF){
        counter++;
    }
    return counter;
}

void int_input(int* enter, char* text){
    int res = 0, temp = 0;
    do
    {
        printf("Хочешь %s? (y/n): ", text);
        res = scanf("%d",  enter);
        temp = clear_input();
    }while(res != 1 || temp != 0);
}


int main() {
    char s[] = "ввести число";
    int n;
    int_input(&n, s);
    printf("%d", n);
    return 0;
}