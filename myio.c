#include <stdio.h>
#include "myio.h"

void printError(int code){
    if (code == 1){ printf("Memory error\n"); }
    if (code == 2){ printf("Некорректный ввод\n"); }
    if (code == 3){ printf("Такой элемент уже существует\n"); }
    if (code == 4){ printf("Такого элемента не существует\n"); }
}

int getInt(int* variable, char* prompt){
    int err;
    while (1){
        printf("%s", prompt);
        err = scanf("%d", variable);
        if (err == 1){ return 0; }
        if (err == -1){ return -1; }
        scanf("%*[^\n]");
        printError(2);
    }
}
