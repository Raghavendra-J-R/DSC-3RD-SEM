#include<stdio.h>
#include<stdlib.h>
int top = -1 , a[20];
void push(int a[], int ele)
{
    a[++top] = ele;
}
void reverse_k(){
    int k;
    int l = top;
    printf("Enter k to reverse first k element: ");
    scanf("%d",&k);
    if(k>top+1){
        printf("Reverse isn't possible");

    }
    else {
        int b[20];
        
        
        for(int i=0;i<k;i++){
            b[i]=a[i];
        }
        for (int i = 0; i < k; i++)
        {
            a[i] = b[k-i-1];
        }
    }
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
       push(a,arr[i]);
    }
   reverse_k();

    printf("\n");
    for(int i =top; i>=0; i--){
printf("%d\n",a[i]);
    }
return 0;
}