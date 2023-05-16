#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *Node;

Node start;


Node insert_end(Node start)
{

Node last;
    int item;

   printf("Enter the data\n");
   scanf("%d",&item);
   while(item!=-999)
   {
    Node p = (Node)malloc(sizeof(Node));

p->data = item;
p->next = NULL;

if(start == NULL)
{
    start = p;
last = p;
}
else{
   last->next =p;
   last = p;

}
scanf("%d",&item);
   }
return start;
}

Node delete_alt(Node start)
{
    Node temp = start;
    Node ptr = start->next;
    while(temp!=NULL && ptr!=NULL)
    {
       temp->next = ptr->next;
       free(ptr);
       temp = temp->next;
       if(temp != NULL)
       ptr = temp->next;
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
    return start;
}

struct node *replace(struct node *start)
{
    struct node *temp = start;

    int first = temp->data;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }

int last = temp->data;



if(last >= first)
{
    for(struct node *ptr = start; ptr->next!=NULL; ptr = ptr->next)
    {
        ptr->data = last;
    }
}
else
{
     for(struct node *ptr = start->next; ptr!=NULL; ptr = ptr->next)
    {
        ptr->data = first;
    }
}

return start;
}

int main()
{


    start = NULL;

    start = insert_end(start);
    display(start);

    start = replace(start);
    printf("\n");
    // start = delete_alt(start);
    // printf("\n");
    display(start);
    return 0;
}