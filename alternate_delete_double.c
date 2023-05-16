
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *start;
struct node *insert_end(struct node *start, int item)
{
    struct node *p, *temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    p->prev = NULL;
    p->next = NULL;

    if (start == NULL)
        start = p;

    else
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
        p->prev = temp;
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("<-%d-> ", ptr->info);
        ptr = ptr->next;
    }
    printf("NULL");
    return start;
}

struct node *delete_alt(struct node *start)
{
    struct node *temp = start;
while(temp!=NULL && temp->next!=NULL)
{
    temp->next = temp->next->next;
     if(temp->next == NULL)
    break;
    temp->next->prev = temp;
    temp = temp->next;
   
}
return start;
}
int main()
{

    start = NULL;
int item;
printf("Enter item...\n");
scanf("%d",&item);
    while(item!=-999)
    {
    start = insert_end(start,item);
scanf("%d",&item);
    }
    display(start);
    start = delete_alt(start);
    printf("\n");
    display(start);
    return 0;
}