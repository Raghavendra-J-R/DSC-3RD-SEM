#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct node{
int item;
struct node *next;
};
struct node *start;
int main()
{

FILE *fp;
fp = fopen("list.txt","r");

if(fp==NULL){
printf("The file could kjfe\n");
exit(1);
}
int num;
struct node *temp , *ptr;
for(int i=0; i<MAX;i++){
     fscanf(fp,"%d",&num);
     struct node *new= (struct node *)malloc(sizeof(struct node));
new->item = num;
new->next=NULL;
if(start==NULL)
start = new;
else{
temp = start;
while(temp->next!=NULL){
    temp = temp->next;
}
temp->next = new;
}
}
ptr = start;
while(ptr!=NULL){
    printf("%d->\t",ptr->item);
    ptr = ptr->next;
}
fclose(fp);

// printf("Enter the name and roll number\n");
// fscanf(stdin, "%s %d",name, &roll);
// fscanf(fp , "%s");

return 0;
}
