#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define True 1
#define False 0


int main(int argc, const char *argv[]) {

    // Bliznyuk Yaroslav
    
    // 14. * Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним
    // цифрам своего квадрата. Например, 25 \ :sup: `2` = 625. Напишите программу, которая вводит
    // натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.
    int num;
    printf("Input number ");
    scanf("%d", &num);
    printf("Automorphic numbers:  ");
    for (int i = 1; i <= num; i++) {
        int i_len = 0;
        int i_copy = i;
        while (i_copy > 0) {
            i_copy /= 10;
            i_len++;
        }
        int pow2 = i * i;
        int check_num = 0;
        int teens = 1;
        for(int j = 0; j < i_len; j++) {
            int digit = pow2 % 10;
            check_num = check_num + digit * teens;
            pow2 /= 10;
            teens *= 10;
        }
        if (i == check_num) {
            printf("%d ", i);
        }
    }
    printf("\n");



    // 13. * Написать функцию, генерирующую случайное число от 1 до 100.
    //     с использованием стандартной функции rand()
    //     без использования стандартной функции rand()
    int generator1() {
        srand(time(NULL));
        int result = rand() % 100 + 1;
        return result;
    }
    printf("Random int with rand(): %d\n", generator1());

    int generator2() {
        unsigned int ttime = time(NULL);
        int a, b;
        a = 87;
        b = 199;
        int result = (ttime * a + b) % 100 + 1;
        return result;
    }
    printf("Random int without rand(): %d\n", generator2());

    // 12. Написать функцию нахождения максимального из трех чисел.
    int max3(int n1, int n2, int n3) {
        int result = n1;
        if (result < n2) {
            result = n2;
        }
        if (result < n3) {
            result = n3;
        }
        return result;
    }
    int nums[3];
    for (int i = 0; i < 3; i++) {
        printf("Input number %d ", i + 1);
        scanf("%d", nums + i);
    }
    printf("Maximum of 3 nums is: %d\n", max3(nums[0], nums[1], nums[2]));


// 11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех
// положительных четных чисел, оканчивающихся на 8.
    int total = 0;
    while (True) {
        int num;
        printf("Input number ");
        scanf("%d", &num);
        if (num == 0) {
            break;
        } else if (0 < num && (num % 10 == 8 || num == 8)) {
            total += num;
        }
    }
    printf("%d\n", total);


    // 10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления
    // определить, имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет
    // — вывести False.
    int n;
    int found;
    printf("Input number ");
    scanf("%d", &n);
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 != 0) {
            printf("True");
            found = True;
            break;
        }
        num /= 10;
    }
    if (!found) {
        printf("False");
    }



    return 0;
}


