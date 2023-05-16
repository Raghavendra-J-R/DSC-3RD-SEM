#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *start;
struct node *insert_end(struct node *start, int item){
    struct node *p , *temp;
    p = (struct node *)malloc(sizeof(struct node));
p->info = item;
p->prev = NULL;
p->next=NULL;

if(start==NULL)
start = p;

else{
temp = start;
while(temp->next!=NULL)
temp = temp->next;
temp->next = p;
p->prev = temp;
}
return start;
}
struct node *display_rev(struct node *start){
    struct node *last;
    if(start==NULL)
    printf("No Linked List to display\n\n");
    else{
        last = start;
        while(last->next!=NULL){
           last=last->next;
        }
    }

    while(last!=NULL){
        printf("<-%d->\t",last->info);
        last = last->prev;
    }
    return start;
}
int main()
{
start = NULL;
int item;
printf("Enter the elements of the Linked List\n");
scanf("%d",&item);
while(item!=-999){
start = insert_end(start,item);
scanf("%d",&item);
}
printf("The Linked List is \n\n");
start = display_rev(start);
printf("\n\n");
return 0;
}