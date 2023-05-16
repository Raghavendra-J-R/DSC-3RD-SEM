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
    return start;
}

// struct node *delete_beg(struct node *start){
//     struct node *temp ;
//     if(start==NULL){
//         printf("No Linked List to delete\n");
//     }
//     else if(start!=NULL && start->next == NULL){
//         printf("The Deleted element is %d\n",start->info);
//         free(start);
//     }
//     else{
//     temp = start;
//     start = start->next;
//     printf("The deleted element is %d\n", temp->info);
//     free(temp);
//     start->prev = NULL;
//     }
//     return start;
// }
struct node *delete_end(struct node *start)
{
    struct node *temp, *follow;
    if (start == NULL)
    {
        printf("No Linked List to delete\n");
    }
    else if (start->next == NULL)
    {
        printf("The Deleted element is %d\n", start->info);
        free(start);
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            follow = temp;
            temp = temp->next;
        }
        printf("The deleted element is %d\n", temp->info);
        free(temp);
        follow->next = NULL;
    }
    return start;
}
struct node *sortedInsert(struct node *start, int data)
{
    struct node *p, *temp = start;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = data;

    if (start == NULL)
    {
        p->prev = NULL;
        p->next = NULL;
        start = p;
    }

    else if (p->info <= start->info)

    {
        p->next = start;
        start->prev = p;
        start = p;
    }

    else
    {

        while (temp != NULL && temp->info <= p->info)
        {
            temp = temp->next;
        }
        p->next = temp;
        temp->prev->next = p;
        p->prev = temp->prev->next;
        temp->prev = p;
    }
    return start;
}
int main()
{
    start = NULL;
    int item, data;
    printf("Enter the elements of the Linked List\n");
    scanf("%d", &item);
    while (item != -999)
    {
        start = insert_end(start, item);
        scanf("%d", &item);
    }
    // start = delete_end(start);
    // printf("The Linked List is \n\n");
    // start = display(start);
    // printf("\n\n");

    printf("Enter the data to insert\n");
    scanf("%d", &data);
    start = sortedInsert(start, data);

    start = display(start);
        return 0;
}