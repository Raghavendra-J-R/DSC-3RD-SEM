#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct queue *q, int size)
{

    q->size = size;
    // q->front = q->rear = 0;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q, int x)
{


     if (q->front == -1 && q->rear == -1)
    {
        q->front = 0;
        q->rear = 0;
        q->Q[q->rear] = x;
    } 
    else if ((q->rear + 1) % q->size == q->front)
    {
        printf("The Queue is full.....\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct queue *q)
{
   
    int x = -1;
    if ((q->rear == -1 && q->front == -1))
        printf("Queue is empty.....\n");
    else if (q->front == q->rear)
    {
        x = q->Q[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        x = q->Q[q->front];
        q->front = (q->front + 1) % q->size;
    }
    return x;
}

void display(struct queue q)  
{

    int i = q.front;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
}

int main()
{
    struct queue q;
    create(&q, 6);
    int option, item;

    while (1)
    {
        printf("Enter the option....\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the item\n");
            scanf("%d", &item);
            enqueue(&q, item);
            break;

        case 2:
            printf("The removed element is %d\n", dequeue(&q));
            break;

        case 3:
            printf("Displaying the elements of the queue....\n");
            display(q);
            break;

        case 4:

            exit(0);
            break;
        }
    }

    return 0;
}