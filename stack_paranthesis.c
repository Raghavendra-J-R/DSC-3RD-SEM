#include <stdio.h>
#include <string.h>
int top = -1, stack[100];
void push(char symbol)
{
    stack[++top] = symbol;
}
int pop()
{
    if (top == -1)
    {
        printf("UNDERFLOW.....");
        return -1;
    }
    else
    {
        return stack[top--];
        
    }
}
void check_paranthesis(char infix[])
{
    char sym, temp;

    int len = strlen(infix);

    for (int i = 0; i < len; i++)
    {
        sym = infix[i];

        switch (sym)
        {

        case '(':
            push(sym);
            break;

        case ')':
            temp = pop();
            break;
        }
    }

    if (temp == -1)
        printf("No Matching paranthesis found......\n");
    else
        printf("Found\n");
}

int main()
{
    char infix[100];

    printf("Enter the infix expression\n");
    gets(infix);

    check_paranthesis(infix);
    return 0;
}