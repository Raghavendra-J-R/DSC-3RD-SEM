#include<stdio.h>

int GCD(int m , int n)
{
    if(n==0)
    return m;

    else if(n>m)
    return GCD(n,m);

    return GCD(m%n,n);


}
int main
()
{
    printf("GCD of 10 and 12 is %d",GCD(10,10));
    return 0;
}