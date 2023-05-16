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


void display(Node start)
{
    if(start == NULL)
    printf("Nothing to display\n");

    else{
        Node temp = start;

        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}


Node add_after(int item, int value)
{
    Node p = (Node)malloc(sizeof(Node));
    p->data = item;

     Node prt = start;

     while(value !=prt->data)
     prt = prt->next;

     if(prt == NULL)
     printf("No matching place found\n");
     else{
        p->next = prt->next;
        prt->next = p;
     }
return start;
}

Node add_to_sorted(Node start)
{
    int value;

    printf("Add the value u want to insert...\n");
    scanf("%d",&value);
    Node p = (Node)malloc(sizeof(Node));
   

if(start == NULL || value < start->data)
{
     p->data = value;
p->next = start;
start = p;
}

else
{

    Node temp = start;
Node prt;
    while(temp!= NULL && value > temp->data)
    {
prt = temp;
temp = temp->next;
    }
 p->data = value;
p->next = prt->next;
prt->next =p;

}

return start;
}

int main()
{
    start = NULL;
    start = insert_end(start);
    display(start);
    // start = add_after(100,20);
    // printf("\n");
    // display(start);
printf("\n");
start = add_to_sorted(start);
display(start);
    return 0;

}