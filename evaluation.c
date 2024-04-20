#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MS 25
int s[MS],top= -1;
char postfix[23];
void main()
{
    void push(int);
    int pop();
    int x,i=0,op1,op2;
    printf("Enter a  valid postfix expression\n");
    gets(postfix);
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
        push(postfix[i]);
        else{
            op2 = pop();
            op1 = pop();
            switch(postfix[i])
            {
                case '+': x = op1 + op2;
                break;
                case '-': x = op1 - op2;
                break;
                case '/': x = op1 / op2;
                break;
                case '*': x = op1 * op2;
                break;

                default:printf("Invalid postfix expression\n");
            }
            push(x);
        }
        i++;
    }
    if(top>0)
    {
        printf("Invalid postfix expression\n");
        exit(0);
    }
    else
    {
        printf("The result of the postfix expression %s is %d",postfix,s[top]);
    }
}
void push(int x)
{
    if(top == MS -1)
    {
        printf("Stack overflow\n");
        exit(0);
    }
    else 
    s[++top]=x;
}
int pop()
{
    if(top == -1)
    {
        printf("Stack underflow\n");
        exit(0);
    }
    else 
    return s[top--];
}