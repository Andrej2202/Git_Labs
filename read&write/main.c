#include <stdio.h>

int main() {
    int i = 0;
    for(i = 0; i < 100; i++){
        printf("%d\n", i);
        if(i == 0){
            i = 95;
        }
    }
    return 0;
}