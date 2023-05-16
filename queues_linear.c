#include<stdio.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};


void create (struct queue *q , int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(sizeof(size));
}


void enqueue(struct queue *q , int x)
{
    if(q->rear == q->rear-1)
    printf("Queue is Full\n");


    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}


int main()
{
struct queue q;
create(&q , 5);
enqu

}
