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

    void print(int length, int *array) {
        for(int i = 0; i < length; i++) {
            printf("%4i", array[i]);
        }
        printf("\n");
            
    }


    // Bliznyuk Yaroslav
    // 1.Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной
    // и неоптимизированной программы. Написать функции сортировки, которые возвращают количество операций.

    int bubbleSort(int* arr) {
        int count = 0;
        for(int i = 0; i < ARRAY_LENGTH; i++) {
            for(int j = 0; j < ARRAY_LENGTH - 1; j++) {
                count++;
                if (arr[j] > arr[j + 1]) {
                    count++;
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
        return count;
    }

    int bubbleSortV2(int* arr) {
        int count = 0;
        for(int i = 0; i < ARRAY_LENGTH; i++) {
            for(int j = 0; j < ARRAY_LENGTH - 1 - i; j++) {
                count++;
                if (arr[j] > arr[j + 1]) {
                    count++;
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
        return count;
    }

    // init array arr
    int arr[ARRAY_LENGTH];
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // arr2 - copy of arr
    int arr2[ARRAY_LENGTH];
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        arr2[i] = arr[i];
    }
    printf("Array befor sort:\n");
    print(ARRAY_LENGTH, arr);
    int ops1, ops2, ops3;
    ops1 = bubbleSort(arr);
    printf("Array after sort:\n");
    print(ARRAY_LENGTH, arr);
    printf("Sort takes %d operations\n", ops1);
    printf("\n");

    printf("Array befor improved sort:\n");
    print(ARRAY_LENGTH, arr2);
    ops2 = bubbleSortV2(arr2);
    printf("Array after improved sort:\n");
    print(ARRAY_LENGTH, arr2);
    printf("Improved sort takes %d operations\n", ops2);
    printf("\n");



    // 2. *Реализовать шейкерную сортировку.
    
    int shakerSort(int* arr) {
        int count = 0;
        int forward = True;
        int activity;
        printf("\n");
        for(int i = 0; i < ARRAY_LENGTH; i++) {
            print(ARRAY_LENGTH, arr);
            activity = False;
            if (forward) {
                for(int j = i / 2; j < ARRAY_LENGTH - i / 2 - 1; j++) {
                    count++;
                    if (arr[j] > arr[j + 1]) {
                        count++;
                        swap(&arr[j], &arr[j + 1]);
                        activity = True;
                    }
                }
                forward = False;
            } else {
                for(int j = ARRAY_LENGTH - 1 - (i + 1) / 2; j > (i - 1) / 2; j--) {
                    count++;
                    if (arr[j] < arr[j - 1]) {
                        count++;
                        swap(&arr[j], &arr[j - 1]);
                        activity = True;
                    }
                }
                forward = True;
            }
            count++;
            if (!activity) break;
            
        }
        return count;
    }

    // init array arr3
    int arr3[ARRAY_LENGTH];
    for(int i = 0; i < ARRAY_LENGTH; i++) {
        arr3[i] = rand() % 100 + 1;
    }
    
    printf("Array befor shaker sort:\n");
    print(ARRAY_LENGTH, arr3);
    ops3 = shakerSort(arr3);
    printf("Array after shaker sort:\n");
    print(ARRAY_LENGTH, arr3);
    printf("Shaker sort takes %d operations\n", ops3);
    printf("\n");


    // 3.Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. 
    // Функция возвращает индекс найденного элемента или -1, если элемент не найден.

    int search(int value, int *array, int length) {
        int L = 0;
        int R = length - 1;
        int m = L + (R - L) / 2;
        while (L <= R) {

            if (array[m] == value) {
                return m;
            } else if (array[m] < value) {
                L = m + 1;
            } else {
                R = m - 1;
            }
            m = L + (R - L) / 2;
        }


        return -1;
    }
    
    int index;
    int value = 51;
    int a[10] = {5, 7, 10, 11, 32, 48, 51, 73, 82, 90};
    index = search(value, a, 10);
    printf("Index of value %d is %d \n", value, index);
    printf("\n");

    return 0;
}