#include<stdio.h>
#include<stdlib.h>

struct node 

{
    int x;
    int y;
};

typedef struct node *point;

int main()
{
    point p = (point)malloc(sizeof(struct node));

    printf("Enter X coordinate...\n");
    scanf("%d",&p->x);
    printf("Enter Y coordinate...\n");
    scanf("%d",&p->y);

    if(p->y ==0 )
    printf("Point lies on X axis");
    return 0;
}