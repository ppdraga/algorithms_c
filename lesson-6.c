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
typedef struct Node {
    T data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

void printTree(Node* root) {
    if (root) {
        printf("%d", root->data);
        if (root->left || root->right) {
            printf("(");
            if (root->left) {
                printTree(root->left);
            } else {
                printf("NULL");
            }
            printf(",");

            if (root->right) {
                printTree(root->right);
            } else {
                printf("NULL");
            }
            printf(")");
        }
    }
}

Node* newNode(T value, Node* parent) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

void insert(Node** head, T value) {
    Node* tmp = NULL;
    if (*head == NULL) {
        *head = newNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp) {
        if (value > tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = newNode(value, tmp);
                return;
            }
        } else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = newNode(value, tmp);
                return;
            }
        } else {
            exit(2);
        }
    }
}

void preOrderTravers(Node* root) {
    if (root) {
        printf("%d", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

int main(int argc, const char *argv[]) {

    char* string = "Some string";
    printf("'%s' has checksum %d \n", string, hashCalc(string));


    Node* tree = NULL;
    FILE* file = fopen("data.txt", "r");
    if (file == NULL) {
        puts("Can't open file!");
        exit(1);
    }
    int count;
    fscanf(file, "%d", &count);
    for(int i = 0; i < count; i++) {
        int value;
        fscanf(file, "%d", &value);
        printf("read value %d\n", value);
        insert(&tree, value);
    }

    printTree(tree);

    fclose(file);
    return 0;
}
