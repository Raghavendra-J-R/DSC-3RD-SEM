#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node *t;

    t = (struct node *)malloc(sizeof(struct node));

    if (t == NULL)
    {
        printf("Cannot add elements to the queue.....\n");
    }
    else
    {

        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }

        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x = -1;
    struct node *t;

    if (front == NULL)
        printf("Queue is empty...\n");

    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }

    return x;
}

void display()
{

    struct node *p;

    if (front == NULL)
        printf("No queue to display\n");

    else
    {
        p = front;
        while (p != NULL)
        {
            printf("%d\n", p->data);
            p = p->next;
        }
    }
}

int main()
{
    int n , option;


    while(1)
    {

printf("Enter your choice.....\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");


scanf("%d",&option);

switch(option)
{
    case 1:
    printf("Enter the element\n");
    scanf("%d",&n);
    enqueue(n);
    break;

    case 2:

    printf("Deleted Element is %d\n",dequeue());
    break;

    case 3:
    printf("Displaying the Linked List......\n");
    display();
    break;

    case 4:
    exit(0);
    break;

}



    }


    return 0;
}
