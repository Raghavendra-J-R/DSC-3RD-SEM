// #include<stdio.h>

// int fib (int n)
// {
//     if(n<=1)
//     return n;

//     else 
//     return fib(n-1)+fib(n-2);
// }



// int main()
// {

// int n;
// printf("Enter n\n");
// scanf("%d",&n);

// printf("The fibonacci number is %d\n",fib(n));

// }

// Fibonacci Series using Recursion
#include <stdio.h>
int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

int main()
{

	printf("%d", fib(5));
	getchar();
	return 0;
}
