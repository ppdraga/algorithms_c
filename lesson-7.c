#include <stdio.h>
#define True 1
#define False 0
#define boolean int

//  Queue
#define MaxQ 100
typedef struct Queue {
    int qu[MaxQ];
    int front;
    int rear;
} Queue;

void init(Queue* q) {
    q->front = 1;
    q->rear = 0;
    return;
}

void push(Queue* q, int value) {
    if (q->rear < MaxQ - 1) {
        q->rear++;
        q->qu[q->rear] = value;
    } else {
        printf("Queue overflow!\n");
    }
    return;
}

int pop(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(2);
    }
    int value = q->qu[q->front];
    q->front++;
    return value;
}

boolean isEmpty(Queue* q) {
    if (q->rear < q->front) {
        return True;
    }
    return False;
}

void printQ(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->qu[i]);
    }
    printf("\n");
    return;
}



// Bliznyuk Yaroslav
// 2. Написать рекурсивную функцию обхода графа в глубину.

void graphTraversDeep(int graph[7][7], int startNode) {
    // Начальный статус вершин 0 
    // (необнаруженная и не посещенная - 0, обнаруженная - 1, посещенная - 2)
    int nodes[7] = {0, 0, 0, 0, 0, 0, 0};

    boolean isTraversed() {
        for(int i = 0; i < 7; i++) {
            if (nodes[i] == 0) {
                return False;
            }
        }
        return True;
    }

    void visit(int node) {
        printf("%d - ", node + 1);
        nodes[node] = 1;
        // Ищем смежные вершины
        for(int i = 0; i < 7; i++) {
            if (graph[node][i] == 1 && nodes[i] == 0) {
                // Посещаем смежные вершины
                visit(i);
                if (!isTraversed())
                    printf("back to %d - ", i + 1);
            }
        }
        // Помечаем вершину как посещенную
        nodes[node] = 2;
    }

    visit(startNode - 1);
}

// 3. Написать функцию обхода графа в ширину.
void graphTraversWidth(int graph[7][7], int startNode) {
    Queue* q;
    q = (Queue*) malloc(sizeof(Queue));
    init(q);

    // Начальный статус вершин 0 
    // (необнаруженная и не посещенная - 0, обнаруженная волной - 1, посещенная - 2)
    int nodes[7] = {0, 0, 0, 0, 0, 0, 0}; 

    // Помещаем в очередь первую вершину
    push(q, startNode - 1);
    while (!isEmpty(q)) {
        int node = pop(q);
        // Помечаем вершину как посещенную
        nodes[node] = 2;
        printf("%d ", node + 1);

        // Проверяем для нее все смежные вершины
        for(int j = 0; j < 7; j++) {
            if (graph[node][j] == 1 && nodes[j] == 0) {
                // если вершина смежная и не обнаружена, то добавляем в очередь
                push(q, j);
                // помечаем вершину как обнаруженную
                nodes[j] = 1;
            }
        }
    }
}


int main(int argc, const char *argv[]) {

    //         5----4
    //       /      |
    //      6    1--2
    //      \  /  \ |
    //       7     3

    int graph[7][7] = {
      // 1  2  3  4  5  6  7
        {0, 1, 1, 0, 0, 0, 1}, // 1
        {1, 0, 1, 1, 0, 0, 0}, // 2
        {1, 1, 0, 0, 0, 0, 0}, // 3
        {0, 1, 0, 0, 1, 0, 0}, // 4
        {0, 0, 0, 1, 0, 1, 0}, // 5
        {0, 0, 0, 0, 1, 0, 1}, // 6
        {1, 0, 0, 0, 0, 1, 0}, // 7
    };

    printf("\n");
    graphTraversWidth(graph, 1);
    printf("\n");
    graphTraversWidth(graph, 3);

    printf("\n");
    graphTraversDeep(graph, 1);
    printf("\n");

    return 0;
}
