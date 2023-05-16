#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{

    char name[50];
    struct node *next;
};

typedef struct node *Node;

Node park;


Node insert_end(Node park)
{
Node last = NULL;
    char name[50];
    printf("Enter name...\n");
    scanf("%s",name);

    while(strcmp('\0',name))
    {


Node p = (Node)malloc(sizeof(Node));
    if(park == NULL)
    {
        strcpy(p->name,name);
        p->next = NULL;
        park = p;
        last = p;
    }
    else
    {
        last->next = p;
        last = p;
    }
    
    printf("Enter name...\n");
    scanf("%s",name);
    }
    return park;
}


void compare(Node park)
{
    Node temp = park;
    while(temp != NULL)
    {
        if(strcmp("Karnataka",temp->name)==0)
        printf("Amusment park found...\n");

    temp = temp->next;
    }


}


int main()
{
    park = NULL;

    park = insert_end(park);

    compare(park);
    return 0;
}