#include <stdio.h>
#include <stdlib.h>
int count = 0;
struct node
{
    int info;
    struct node *next;
};
struct node *start;
struct node *insert_at_end(struct node *start, int item)
{
    struct node *temp, *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;
    if (start == NULL)
        start = p;
    else
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
    count++;
    return start;
}

void find(struct node *start, int n){
    struct node *temp = start;
    int c;
    c =1;

    while(c<(count-n+1)){
temp = temp->next;
c++;
    }
    printf("The element is %d\n",temp->info);
}

int main(){
    start = NULL;
    int item , n;
    scanf("%d",&item);
    while (item!=-999){
    start = insert_at_end(start,item);
scanf("%d",&item);
    }
    printf("%d\n",count);
printf("Enter the nth element from the end of the linked list which has to be detremined\n");

scanf("%d",&n);

     find(start,n);
     return 0;
    }