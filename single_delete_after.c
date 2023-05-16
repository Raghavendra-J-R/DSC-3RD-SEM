#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node* N ;
N start;
N insert_at_end(N start, int item)
{
 N temp, p;
    p = (N )malloc(sizeof(struct node));
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
    return start;
}

N delete(N start, int key){                                                                                                                                                        
    N temp= start, follow;
    if(start!=NULL && start->next==NULL){
      printf("No element after this element to delete\n");
    }
    else{
    while(key!=temp->info)
       
        temp = temp->next;
    
    follow = temp->next;
    temp->next = follow->next;
    printf("The deleted element is %d\n",follow->info);
    
    free(follow);
    }
    return start;

}
N display(N start)
{
    N ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d->\t", ptr->info);
        ptr = ptr->next;
    }
    return start;
}

int main()
{
    start = NULL;
    int item, key;
    printf("Enter the items of the linked List.\nEnter -999 to stop\n");
    scanf("%d", &item);
    while (item != -999)
    {
        start = insert_at_end(start, item);
        scanf("%d", &item);
    }
printf("Enter the key element after which a node has to be deleted\n");
scanf("%d",&key);
start = delete(start,key);
    printf("The elements of the linked list are\n");
    start = display(start);
    return 0;
}