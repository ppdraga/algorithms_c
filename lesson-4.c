#include <stdio.h>
#include <math.h>
// #include <conio.h>
#define True 1
#define False 0

    // Bliznyuk Yaroslav
    // 3.Требуется обойти конём шахматную доску размером NxM, 
    // пройдя через все поля доски по одному разу.

#define N 5
#define M 5

int board[N][M];

int SearchSolution(int n, int x, int y);
int CheckKnight(int x, int y, int n);
void Print(int n, int m, int a[N][M]);
void Zero(int n, int m, int a[N][M]);




int main(int argc, const char *argv[]) {
    Zero(N, M, board);
    Print(N, M, board);
    printf("\n");
    SearchSolution(1, 0, 0);

    return 0;
}


int SearchSolution(int n, int x, int y) {
    if (n > N * M) return True;
    if (CheckKnight(x, y, n)) {

        // MAP:
        //      8   1 
        //    7       2  
        //        x
        //    6       3
        //      5   4 

        // way-1
        if (SearchSolution(n + 1, x - 2, y + 1)) return True;
        // way-2
        if (SearchSolution(n + 1, x - 1, y + 2)) return True;
        // way-3
        if (SearchSolution(n + 1, x + 1, y + 2)) return True;
        // way-4
        if (SearchSolution(n + 1, x + 2, y + 1)) return True;
        // way-5
        if (SearchSolution(n + 1, x + 2, y - 1)) return True;
        // way-6
        if (SearchSolution(n + 1, x + 1, y - 2)) return True;
        // way-7
        if (SearchSolution(n + 1, x - 1, y - 2)) return True;
        // way-8
        if (SearchSolution(n + 1, x - 2, y - 1)) return True;
        // Step back
        board[x][y] = 0;
        Print(N, M, board);
        return False;
    }
    return False;
}

// Check knight
int CheckKnight(int x, int y, int n) {
    if (x < 0 || y < 0 || x > N - 1 ||  y > M - 1) return False;
    if (board[x][y] == 0) {
        board[x][y] = n;
        Print(N, M, board);
        return True;
    }
    return False;
}


// Clean board
void Zero(int n, int m, int a[N][M]) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            a[i][j] = 0;
        }
    }
}

// Print board
void Print(int n, int m, int a[N][M]) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


