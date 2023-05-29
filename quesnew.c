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
    FILE *inputFile, *outputFile, *output1File, *output3File;
    int p, t, q1, num;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    output1File = fopen("output1.txt", "w");
    output3File = fopen("output3.txt", "w");

    if (outputFile == NULL || output1File == NULL || output3File == NULL) {
        printf("Error opening output files.\n");
        return 1;
    }

    initQueue(&q);

    fscanf(inputFile, "%d %d", &p, &q1);
    fscanf(inputFile, "%d", &t);

    for (int i = 0; i < t; i++) {
        fscanf(inputFile, "%d", &num);
        enqueue(&q, num);
    }

    int e, ch;

    while (!isEmpty(&q)) {
        fscanf(inputFile, "%d", &ch);

        switch (ch) {
            case 1:
                fscanf(inputFile, "%d", &e);
                enqueue(&q, e);
                fprintf(outputFile, "%d ", e);
                fprintf(output3File, "enqueue\n");
                break;
            case 2:
                e = dequeue(&q);
                fprintf(output1File, "%d ", e);
                fprintf(output3File, "dequeue\n");
                break;
            case 3:
                display(&q);
                fprintf(output3File, "display\n");
                break;

        }
    }

    fclose(inputFile);
    fclose(outputFile);
    fclose(output1File);
    fclose(output3File);

    return 0;
}
