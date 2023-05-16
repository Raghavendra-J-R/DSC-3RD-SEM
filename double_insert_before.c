#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *start;
struct node *insert_at_end(struct node *start, int item)
{
    struct node *ptr, *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    p->prev = NULL;
    p->next = NULL;
    if (start == NULL)
        start = p;
    else
    {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = p;
        p->prev = ptr;
    }
    return start;
}
struct node *insert_before(struct node *start, int key, int item)
{
    struct node *p, *ptr;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    ptr = start;
        while (key != ptr->info)
        {
          
            ptr = ptr->next;
        }
    if (ptr==start)
    {
        p->prev = NULL;
        p->next = start;
        start->prev = p;
        start = p;
    }
    else
    {
        p->next = ptr;
        ptr->prev->next = p;
        p->prev = ptr->prev;
        ptr->prev = p;
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
    return start;
}

int main()
{
    start = NULL;
    int item, key;
    printf("Enter the items into the Linked List.\nEnter -999 to stop\n");
    scanf("%d", &item);
    while (item != -999)
    {
        start = insert_at_end(start, item);
        scanf("%d", &item);
    }
    printf("Enter the key element before which a new node has to be inserted\n");
    scanf("%d", &key);

    printf("Enter the item\n");
    scanf("%d", &item);
    if (item != -999)
        start = insert_before(start, key, item);
    start = display(start);

    return 0;
}