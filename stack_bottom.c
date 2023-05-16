#include <stdio.h>
#include <stdlib.h>

int topA = -1, topB = -1, stack1[12], stack2[20], stack[20];

void push(int stack[], int ele)
{
    stack[++topA] = ele;
}

void insert(int stack[], int k){
 int l=topA+1,item;
    while(l--){
        stack[l+1]=stack[l];

    }
  
stack[0]=k;
    topA=topA+1;

}



int main()

{
    int *arr, n , k;
    printf("Enter the elements of the array\n");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(n));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
       insert(stack , arr[i]);
    }
    
    printf("\n");

printf("Enter the element to be inserted at the bottom\n");
scanf("%d", &k);
  
insert(stack , k);
    for (int i = 0; i<=topA; i++)
        printf("%d\n", stack[i]);
        return 0;
}