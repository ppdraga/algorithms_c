#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define True 1
#define False 0


    // Bliznyuk Yaroslav

    // 1. Реализовать простейшую хэш-функцию. На вход функции подается строка,
    // на выходе сумма кодов символов.
int hashCalc(char* s) {
    int sum = 0;
    int i = 0;
    while (*(s + i) != 0) {
        sum += *(s + 1);
        i++;
    }
    return sum;
}
    
    // 2. Переписать программу, реализующее двоичное дерево поиска.
    // а) Добавить в него обход дерева различными способами;
    // б) Реализовать поиск в двоичном дереве поиска;

typedef int T;


int main(int argc, const char *argv[]) {

    char* string = "Some string";
    printf("'%s' has checksum %d \n", string, hashCalc(string));

    return 0;
}
