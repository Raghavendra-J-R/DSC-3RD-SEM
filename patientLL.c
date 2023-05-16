#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 3 

struct node
{
   char name[1000] , venue[500] , time[500];
    struct node *next;
};
struct node *head;
int main()
{

    struct node *head , *ptr,*current;

    FILE *fp = fopen("new.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening input file.\n");
    return 1;
    }

   char name[100] , venue[250] , time[500];
    for (int i = 0; i < MAX; i++)
    {
        fscanf(fp, "%s %s %s", name, venue , time);

        struct node *new_node = (struct node *)malloc(sizeof(struct node));

        if (new_node == NULL)
        {
            printf("Error allocating memory for patient.\n");
            return 1;
        }

        strcpy(new_node->name, name);
        strcpy(new_node->venue,venue);
        strcpy(new_node->time, time);
        new_node->next = NULL;

        if (head == NULL)
        {

            head = new_node;
        }
        else
        {

           current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    

    
ptr = head;
while(ptr!=NULL){
    printf("%s-> %s-> %s\n",ptr->name ,ptr->venue, ptr->time);
    ptr= ptr->next;
}
   fclose(fp); 
   return 0;
}



