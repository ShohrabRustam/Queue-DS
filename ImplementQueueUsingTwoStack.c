#include <stdio.h>
#include <stdlib.h>

struct node

{

    int data;

    struct node *next;
};

void push(struct node **top, int data);

int pop(struct node **top);

struct queue

{

    struct node *stack1;

    struct node *stack2;
};

void enqueue(struct queue *q, int x)

{

    push(&q->stack1, x);
}

void dequeue(struct queue *q)

{

    int x;

    if (q->stack1 == NULL && q->stack2 == NULL)
    {

        printf("Queue is empty");

        return;
    }

    if (q->stack2 == NULL)
    {

        while (q->stack1 != NULL)
        {

            x = pop(&q->stack1);

            push(&q->stack2, x);
        }
    }

    x = pop(&q->stack2);

    printf("Removed Element: %d\n", x);
}

void push(struct node **top, int data)

{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {

        printf("Stack overflow\n");

        return;
    }

    newnode->data = data;

    newnode->next = (*top);

    (*top) = newnode;
}

int pop(struct node **top)

{

    int buff;

    struct node *t;

    if (*top == NULL)
    {

        printf("Stack underflow \n");

        return -1;
    }

    else
    {

        t = *top;

        buff = t->data;

        *top = t->next;

        free(t);

        return buff;
    }
}

void display(struct node *top1, struct node *top2)

{

    while (top1 != NULL)
    {

        printf("%d\n", top1->data);

        top1 = top1->next;
    }

    while (top2 != NULL)
    {

        printf("%d\n", top2->data);

        top2 = top2->next;
    }
}

int main()

{

    clrscr();

    struct queue *q = (struct queue *)malloc(sizeof(struct queue));

    int f = 0, a;

    char ch = 'y';

    q->stack1 = NULL;

    q->stack2 = NULL;

    while (1)
    {

        printf("\n1.Add to queue\n2.Remove from queue\n3.Display\n4.Exit\nEnter your choice:");

        scanf("%d", &f);

        switch (f)
        {

        case 1:
            printf("Enter the element to be added to queue:");

            scanf("%d", &a);

            enqueue(q, a);

            break;

        case 2:
            dequeue(q);

            break;

        case 3:
            display(q->stack1, q->stack2);

            break;

        case 4:
            exit(1);

            break;

        default:
            printf("Invalid Choice!\n");

            break;
        }
    }
}