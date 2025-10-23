#include <stdio.h>
#include <stdlib.h> 

int clear_input(){
    int c, counter = 0;
    while ((c = getchar()) != '\n' && c != EOF){
        counter++;
    }
    return counter;
}

void yes_no_input(char* enter, char* text){
    int res = 0;
    do
    {
        printf("Хочешь %s? (y/n): ", text);
        scanf(" %c",  enter);
        res = clear_input();
    }while((*enter != 'n' && *enter != 'N' && *enter != 'y' && *enter != 'Y') || res !=0);
}

int my_strcmp(const char *s1, const char *s2){
	while (*s1 && (*s1 == *s2)){
        s2++;
        s1++;
    }
	return (*(unsigned char *)s1 - *(unsigned char *)s2); // ансайнд потому что есть приколы с минусовыми кодировками
}


int string_replace(const char *s1, char *s2){
    if (s1 == NULL || s2 == NULL) {
        return -1;
    }

    while (*(s1) != '\0') {
        *(s2++) = *(s1++);
    }

    *(s2) = '\0';
    return 0;
}


int remove_n(char *s){
    int i = 0;
    if(s == NULL) return -1;
    while(s[i] != '\n' && s[i] != '\0'){
        i++;
    }
    s[i] = '\0';
    return 0;
}


void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear"); 
#endif
}