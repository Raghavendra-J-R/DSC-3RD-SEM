

#include <stdio.h>

#include <string.h>
#define MAX 10
char stack[MAX], infix[MAX], postfix[MAX];
int count = 0, pos = 0, top = -1, len;
char symb, temp;
void push(char symb)
{
    top = top + 1;
    stack[top] = symb;
}
char pop()
{
    symb = stack[top];
    top = top - 1;
    return symb;
}

int preced(char symb)
{
    int p;
    switch (symb)
    {
    case '^':
        p = 3;
        break;
    case '/':
        p = 2;
        break;
    case '*':
        p = 2;
        break;
    case '+':
        p = 1;
        break;
    case '-':
        p = 1;
        break;
    case '(':
    case ')':
        p = 0;
        break;
    }
    return p;
}

void itop(char infix[], char postfix[])
{
    char symbol, temp;
    len = strlen(infix);
    while (count < len)
    {
        symbol = infix[count];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            temp = pop();
            while (temp != '(')
            {
                postfix[pos] = temp;
                pos++;
                temp = pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/': 
        case '^':
            while (preced(stack[top]) >= preced(symbol))
            {
                temp = pop();
                postfix[pos] = temp;
                pos++;
            }
            push(symbol);
            break;
        default:
            postfix[pos++] = symbol;
            break;
        }
    count++;
    }
}

void main()
{

    printf("Enter infix; \n");
    scanf("%s", infix);
    itop(infix, postfix);
    printf("%s\n", postfix);
}


// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
//  int arr[10], top = -1;


//  void push(int x)
//  {
//     arr[++top] = x;
//  }

//  int pop()
//  {
//     return arr[top--];
//  }


//  int isdig(char symbol)
//  {
//     return (symbol >='0' && symbol <='9');
//  }


//  int op(int op1, int op2, char symbol)
//  {
//     switch(symbol)
//     {
//         case '+':
//         return op2 + op1;
//         break;

//         case '-':
//         return op2 - op1;
//         break;


//         case '*':
//         return op2 * op1;
//         break;


//         case '/':
//         return op2 / op1;
//         break;
//     }
//  }

//  void main()
//  {
//     char symbol , postfix[10];
//     int op1, op2, res;

//     printf("Enter Postfix expression\n");
//     gets(postfix);


//     for(int i = 0; i < strlen(postfix); i++)
//     {
//         symbol = postfix[i];


//         if(isdig(symbol))

//         push(symbol - '0');

//         else
//         {
//             op2 = pop();
//             op1 = pop();

//             res = op(op2,op1,symbol);
//             push(res);

//         }
//     }
//     printf("Result is %d\n",pop());
    
//  }