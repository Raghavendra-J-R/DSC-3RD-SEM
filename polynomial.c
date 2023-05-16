// #include<stdio.h>
// #include<stdlib.h>
// struct node
// {
//     int coeff,px,flag;
//     struct node *next;
// };
// struct node *insert(struct node *);
// struct node *add(struct node *,struct node *,struct node *);
// struct node *display(struct node *);
// struct node *add_insert(int,int,struct node *);
// int main()
// {
//     struct node *start1=NULL,*start2=NULL,*start3=NULL;
//     start1=insert(start1);
//     start1=display(start1);
//     start2=insert(start2);
//     start2=display(start2);
//     start3=add(start1,start2,start3);
//     printf("\n");
//     start3=display(start3);
//     return 0;
// }
// struct node *insert(struct node *start)
// {
//     struct node *p,*temp;
//     int cf,x;
//     printf("enter coeff and power of x:\n");
//     scanf("%d%d",&cf,&x);
//     while(cf!=-999)
//     {
//     p=(struct node*)malloc(sizeof(struct node));
//     p->coeff=cf;
//     p->px=x;
//     p->flag=0;
//     p->next=NULL;
//     if(start==NULL)
//     start=p;
//     else
//     {
//     temp=start;
//     while(temp->next!=NULL)
//     temp=temp->next;
//     temp->next=p;
//     }
//     scanf("%d%d",&cf,&x);
//     }
//     return start;
// }
// struct node *add(struct node *start1,struct node *start2,struct node *start3)
// {
//     struct node *p1=start1,*p2;
//     int cf;
//     while(p1!=NULL)
//     {
//         p2=start2;
//         while(p2!=NULL)
//         {
//             if(p1->px==p2->px)
//             break;
//             p2=p2->next;
//         }
//         if(p2!=NULL)
//         {
//             p2->flag=1;
//             int cf;
//             cf=p1->coeff+p2->coeff;
//             if(cf!=0)
//             start3=add_insert(cf,p2->px,start3);
//         }
//         else
//         start3=add_insert(p1->coeff,p1->px,start3);
//         p1=p1->next;
//     }
//     p2=start2;
//     while(p2!=NULL)
//     {
//     if(p2->flag==0)
//     start3=add_insert(p2->coeff,p2->px,start3);
//     p2=p2->next;
//     }
//     return start3;
// }
// struct node *add_insert(int cf, int x,struct node *start3)
// {
//     struct node *p,*temp;
//     p=(struct node *)malloc(sizeof(struct node));
//     p->coeff=cf;
//     p->px=x;
//     p->flag=0;
//     p->next=NULL;
//     if(start3==NULL)
//     start3=p;
//     else
//     {
//         temp=start3;
//         while(temp->next!=NULL)
//         temp=temp->next;
//         temp->next=p;
//     }
//     return start3;
// }
// struct node *display(struct node *start3)
// {
//     struct node *temp;
//     temp=start3;
//     while(temp!=NULL)
//     {
//         printf("%d %d ->  ",temp->coeff,temp->px);
//         temp=temp->next;
//     }
//     return start3;
// }

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    float coef;
    int Px;
    int Py;
    int flag;
    struct node *next;
};
typedef struct node *Node;

Node poly1, poly2, poly3, poly;

Node insert_end(Node poly, float cf, int px, int py)
{
    Node temp;
    Node p = (Node)malloc(sizeof(struct node));

    p->coef = cf;
    p->Px = px;
    p->Py = py;
    p->next = NULL;
p->flag = 0;

    if (poly == NULL)
        poly = p;

    else
    {
        temp = poly;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = p;
    }
    return poly;
}

void display(Node poly)
{
    Node ptr;

    if (poly == NULL)
        printf("No polynomial to print....\n");

    else
    {
        ptr = poly;
        while (ptr != NULL)
        {
            printf("(%0.1fx^%dy^%d)->", ptr->coef, ptr->Px, ptr->Py);
            ptr = ptr->next;
        }
        printf("NULL");
    }
}

Node add_poly(Node poly1, Node poly2, Node poly3)
{

    Node p2, p1 = poly1;
    while (p1 != NULL)
    {
        p2 = poly2;

        while (p2 != NULL)
        {
            if (p1->Px == p2->Px && p1->Py == p2->Py)
                break;

            p2 = p2->next;
        }
        if (p2 != NULL)
        {
            float cf;
            p2->flag = 1;
            cf = p1->coef + p2->coef;

            poly3 = insert_end(poly3, cf, p1->Px, p1->Py);
        }
        else
        {
            poly3 = insert_end(poly3, p1->coef, p1->Px, p1->Py);
        }

        p1 = p1->next;
    }
    
    p2 = poly2;

    while (p2!=NULL)
    {
        if (p2->flag == 0)
        {
            poly3 = insert_end(poly3, p2->coef, p2->Px, p2->Py);
           
        }
       
            p2 = p2->next;
    }
    return poly3;
}


int main()
{
    poly1 = NULL;
    poly2 = NULL;
    poly3 = NULL;

    float cf;
    int px, py;

    printf("Enter coefficient...For polynomial 1\n");
    scanf("%f", &cf);
    while (cf != -999)
    {
        printf("Enter powers of x and y...\n");
        scanf("%d %d", &px, &py);
        poly1 = insert_end(poly1, cf, px, py);
        printf("Enter coefficient...For polynomial 1\n");
        scanf("%f", &cf);
    }

    printf("Enter coefficient...For polynomial 2\n");
    scanf("%f", &cf);
    while (cf != -999)
    {
        printf("Enter powers of x and y...\n");
        scanf("%d %d", &px, &py);
        poly2 = insert_end(poly2, cf, px, py);
        printf("Enter coefficient...For polynomial 2\n");
        scanf("%f", &cf);
    }

    display(poly1);
    printf("\n");
    display(poly2);
    printf("\n");

    poly3 = add_poly(poly1, poly2, poly3);
    display(poly3);
    // printf("\nThe evaluated polynomial is %f\n", evaluate(poly3));

    return 0;
}