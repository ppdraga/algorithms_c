#include <stdio.h>
#define True 1
#define False 0


int main(int argc, const char *argv[]) {

    // Bliznyuk Yaroslav
    // Исполнитель «Калькулятор» преобразует целое число, записанное на экране. У
    // исполнителя две команды, каждой присвоен номер:
    // 1. Прибавь 1.
    // 2. Умножь на 2.
    // Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза. Сколько
    // существует программ, которые число 3 преобразуют в число 20:
    // а. С использованием массива.
    // b. *С использованием рекурсии.

    int count = 0;
    int deep = 0;
    char* history[256];
    char* alphabet[2] = {"+1", "*2"};

    void executorCalc(int startNum, int endNum) {
        if (startNum == endNum) {
            count++;
            // print history
            history[deep] = "\0";
            int k = 0;
            while (history[k] != "\0") {
                printf("%s ", history[k]);
                k++;
            }
            printf("\n");
            return;
        }
        for(int i = 0; i < 2; i++) {
            if (alphabet[i] == "+1" && startNum + 1 <= endNum) {
                history[deep] = "+1";
                deep++;
                executorCalc(startNum + 1, endNum);
                history[deep] = "\0";
                deep--;
            }
            if (alphabet[i] == "*2" && startNum * 2 <= endNum) {
                history[deep] = "*2";
                deep++;
                executorCalc(startNum * 2, endNum);
                history[deep] = "\0";
                deep--;
            }
        }

        return;
    }

    executorCalc(3, 20);
    printf("\nresult %d\n", count);

    return 0;
}