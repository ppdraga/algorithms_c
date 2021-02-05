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


void printIndent(int n) {
    for (int i = 0; i < n; i++) {
        printf("  ");
    }
}

int indent = 0;
void printTree2(Node* root) {
    if (root) {
        printIndent(indent);
        printf("%d\n", root->data);
        if (root->left || root->right) {
            
            indent++;
            if (root->left) {
                printTree2(root->left);
            } else {
                printIndent(indent);
                printf("NULL\n");
            }

            if (root->right) {
                printTree2(root->right);
            } else {
                printIndent(indent);
                printf("NULL\n");
            }
            indent--;
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
        printf("%3d", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void preOrderTravers2(Node* root) {
    if (root) {
        preOrderTravers2(root->left);
        printf("%3d", root->data);
        preOrderTravers2(root->right);
    }
}


Node* searchNode(T value, Node* root) {
    if (value == root->data) {
        return root;
    } else if (value < root->data) {
        if (root->left) {
            return searchNode(value, root->left);
        } else {
            return NULL;
        }
    } else {
        if (root->right) {
            return searchNode(value, root->right);
        } else {
            return NULL;
        }
    }
}



int main(int argc, const char *argv[]) {

    char* string = "Some string";
    printf("'%s' has checksum %d \n\n", string, hashCalc(string));


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
        // printf("read value %d\n", value);
        insert(&tree, value);
    }

    //Печать деревьев:
    printTree(tree);
    printf("\n");
    printTree2(tree);
    printf("\n");


    // Обход деревьев:
    printf("\n");
    preOrderTravers(tree);
    printf("\n");
    preOrderTravers2(tree);
    printf("\n");
    printf("\n");


    // Поиск узла:
    Node* node7;
    int value = 7;
    node7 = searchNode(value, tree);
    if (node7) {
        printf("Found Node at %p with value %d\n", node7, node7->data);
    } else {
        printf("Could not find Node with value %d\n", value);
    }

    value = 100;
    Node* nodeNull;
    nodeNull = searchNode(value, tree);
    if (nodeNull) {
        printf("Found Node at %p with value %d\n", nodeNull, nodeNull->data);
    } else {
        printf("Could not find Node with value %d\n", value);
    }

    fclose(file);
    return 0;
}


