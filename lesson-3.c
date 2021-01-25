#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define True 1
#define False 0

#define ARRAY_LENGTH 15


int main(int argc, const char *argv[]) {

    void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    srand(time(NULL));

    int arr[ARRAY_LENGTH];
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        arr[i] = rand() % 100 + 1;
    }

    void print(int length, int *array) {
        for(int i = 0; i < length; i++) {
            printf("%4i", array[i]);
        }
        printf("\n");
            
    }

    print(ARRAY_LENGTH, arr);

    // Bliznyuk Yaroslav
    // 1.Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной
    // и неоптимизированной программы. Написать функции сортировки, которые возвращают количество операций.






    // 2. *Реализовать шейкерную сортировку.
    
    
    
    
    // 3.Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. 
    // Функция возвращает индекс найденного элемента или -1, если элемент не найден.

    int search(int num, int *array, int length) {



        return -1;
    }
 


    return 0;
}