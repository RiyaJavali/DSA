#include<stdio.h>
#include<stdlib.h>
#define max 1000

typedef struct
{
    int top;
    int ele[max];

} stack;


void initStack(stack *s)
{
   s->top = -1;
}

int isFull(stack *s)
{
    return (s->top == max - 1);
}

void push(stack *s, int e)
{
    s->top++;
    s->ele[s->top] = e;
}

int isEmpty(stack *s)
{
    return (s->top == -1);
}

int pop(stack *s)
{
    int e = s->ele[s->top];
    s->top--;
    return e;
}

int peek(stack *s)
{
    int e = s->ele[s->top];
    return e;
}

void display(stack *s)
{
    FILE *fp4 = fopen("output2.txt", "w");
    if (s->top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->ele[i]);
            fprintf(fp4, "%d\t", s->ele[i]);
        }
    }
}

int main()
{
    stack s;
    FILE *fp1, *fp2, *fp3, *fp5;
    int p, t, q, i, num;
    fp1 = fopen("input.txt", "r");

    if (fp1 == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    fp2 = fopen("output.txt", "w");
    fp3 = fopen("output1.txt", "w");
    fp5 = fopen("output3.txt", "w");

    if (fp2 == NULL || fp3 == NULL || fp5 == NULL)
    {
        printf("Error opening output files.\n");
        return 1;
    }

    initStack(&s);

    fscanf(fp1, "%d %d", &p, &q);
    fscanf(fp1, "%d", &t);

    for (i = 0; i < t; i++)
    {
        fscanf(fp1, "%d", &num);
        push(&s, num);
    }

    int e, ch;

    while (1)
    {
        printf("\n1. push\n2. pop\n3. display\n4. exit\n");
        printf("Enter your choice: ");
        fscanf(fp1, "%d", &ch);

        switch (ch)
        {
        case 1:
            if (isFull(&s))
            {
                printf("Stack is overflow.\n");
            }
            else
            {
                fscanf(fp1, "%d", &e);
                printf("%d  ", e);
                fprintf(fp2, "%d  ", e);
                push(&s, e);
                fprintf(fp5, "push\n");
            }
            break;
        case 2:
            if (isEmpty(&s))
            {
                printf("Stack is underflow.\n");
            }
            else
            {
                e = pop(&s);
                fprintf(fp3, "%d   ", e);
                fprintf(fp5, "pop\n");
            }
            break;
        case 3:
            display(&s);
            fprintf(fp5, "display\n");
            break;
        case 4:
            exit(0);
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp5);
return 0;
}
