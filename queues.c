#include <stdio.h>
#include <stdlib.h>
#define max 1000

typedef struct {
    int front;
    int rear;
    int ele[max];
} queue;

void initQueue(queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(queue *q) {
    return (q->rear == max - 1);
}

int isEmpty(queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(queue *q, int e) {
    if (isFull(q)) {
        printf("Queue is full. Overflow!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->ele[q->rear] = e;
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Underflow!\n");
        return -1;
    }
    int e = q->ele[q->front];
    q->front++;
    return e;
}

int peek(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->ele[q->front];
}

void display(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->ele[i]);
    }
}

int main() {
    queue q;
    FILE *fp1, *fp2, *fp3, *fp5;
    int p, t, q1, i, num;
    fp1 = fopen("input.txt", "w");
    printf("Enter the range:\n");
    scanf("%d %d", &p, &q1);
    printf("Enter the number: ");
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        num = (rand() % (p - q1 + 1)) + p;
        printf("%d\n", num);
        fprintf(fp1, "%d ", num);
    }
    fclose(fp1);

    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    fp3 = fopen("output1.txt", "w");
    fp5 = fopen("output3.txt", "w");

    initQueue(&q);

    int e, ch;

    while (1) {
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (isFull(&q))
                    printf("Queue is full. Overflow!\n");
                else {
                    printf("Enter the element: ");
                    fscanf(fp1, "%d", &e);
                    printf("%d\n", e);
                    fprintf(fp2, "%d ", e);
                    enqueue(&q, e);
                    fprintf(fp5, "enqueue\n");
                }
                break;
            case 2:
                if (isEmpty(&q))
                    printf("Queue is empty. Underflow!\n");
                else {
                    e = dequeue(&q);
                    fprintf(fp3, "%d ", e);
                    fprintf(fp5, "dequeue\n");
}
                    break;
                     case 3:
                   display(&q);
                  fprintf(fp5, "display\n");
                   break;
               case 4:
              exit(0);
}
}
}
