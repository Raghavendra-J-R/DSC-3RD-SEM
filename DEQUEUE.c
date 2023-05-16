#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int deq[MAX], left = -1, right = -1;

void insert_right()
{

    int val;

    printf("Enter the value to be inserted...\n");
    scanf("%d", &val);

    if ((left == 0 && right == MAX - 1) || left == right + 1)
    {
        printf("Overflow...\n");
        return;
    }

    if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else
    {
        if (right == MAX - 1)
            right = 0;

        else
            right = right + 1;
    }
    deq[right] = val;
}

void insert_left()
{

    int val;
    printf("Enter the value..\n");
    scanf("%d", &val);

    if ((left == 0 && right == MAX - 1) || left == right + 1)
    {
        printf("Overflow...\n");
        return;
    }

    if (left == -1)
    {
        left = 0;
        right = 0;
    }

    else
    {

        if (left == 0)
            left = MAX - 1;

        else
            left = left - 1;
    }

    deq[left] = val;
}

void delete_right()
{

    if (left == -1)
    {
        printf("Underflow...\n");
        return;
    }

    printf("The deleted element is %d\n", deq[right]);

    if (left == right)
    {
        left = -1;
        right = -1;
    }

    else
    {
        if (right == 0)
            right = MAX - 1;

        else
            right = right - 1;
    }
}

void delete_left()
{

    if (left == -1)
    {
        printf("Underflow...\n");
        return;
    }
    printf("The deleted element is %d\n", deq[left]);
    if (left == right)
    {
        left = -1;
        right = -1;
    }

    else
    {
        if (left == MAX - 1)
            left = 0;
        else
            left = left + 1;
    }
}

void display()
{
    int front = left, rear = right;

    if (front == -1)
    {
        printf("Underflow....No queue to display...\n");
        return;
    }
    printf("The elements of the queue are:\n");
    if (front <= rear)
    {
        while (front <= rear)
        {
            printf("Queue[%d] = %d\n", front, deq[front]);
            front++;
        }
    }
    else
    {
        while (front <= MAX - 1)
        {
            printf("Queue[%d] = %d\n", front, deq[front]);
            front++;
        }

        front = 0;
        while (front <= rear)
        {
            printf("Queue[%d] = %d\n", front, deq[front]);
            front++;
        }
    }
}

void inp_deq()
{

    int option;

    while (1)
    {
        printf("This is an input restricted dequeue...\n");
        printf("1.Insert Right..\n");
        printf("2.Delete Right..\n");
        printf("3.Delete Left..\n");
        printf("4.Display..\n");
        printf("5.Exit..\n");

        printf("Enter the option...\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            insert_right();
            break;

        case 2:
            delete_right();
            break;

        case 3:
            delete_left();
            break;

        case 4:
            display();
            break;
        case 5:
            printf("Exiting....\n");
            exit(0);
            break;
        }
    }
}

void out_deq()

{

    int option;

    while (1)
    {
        printf("This is an output restricted dequeue...\n");
        printf("1.Insert Right..\n");
        printf("2.Insert Left..\n");
        printf("3.Delete Left..\n");
        printf("4.Display..\n");
        printf("5.Exit..\n");

        printf("Enter the option...\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            insert_right();
            break;

        case 2:
            insert_left();
            break;

        case 3:
            delete_left();
            break;

        case 4:
            display();
            break;
        case 5:
            printf("Exiting....\n");
            exit(0);
            break;
        }
    }
}

int main()
{
    int option;

    printf("1.Input Restricted Dequeue..\n");
    printf("2.Output Restricted Dequeue..\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        inp_deq();
        break;

    case 2:
        out_deq();
        break;
    }
    return 0;
}