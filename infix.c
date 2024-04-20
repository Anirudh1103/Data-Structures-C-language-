#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MS 25
char s[MS];
int top = -1;
void main()
{
    void push(char);
    int pop();
    int priority(char);
    int i=0,j=0;
    char infix[25],postfix[25];
    push('#');
    printf("Enter a valid infix expression\n");
    gets(infix);
    puts(infix);
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
        postfix[j++]= infix[i];
        else if(infix[i] == '(')
        push(infix[i]);
        else if(infix[i] == ')')
        {
            while(s[top]!='(')
            {
                postfix[j++]=pop();
                pop();
            }
        }
        else if(infix[i] == '+' ||infix[i] == '-' ||infix[i] == '*' ||infix[i] == '/')
        {
            while(priority(s[top])>=priority(infix[i]))
            {
                postfix[j++]= pop();
                push(infix[i]);
            }
        }
        i++;
    }
    while(s[top]!='#')
    postfix[j++]=pop();
    postfix[j] = '\0';
    printf("Infix expression: %s\npostfix expression %s\n",infix,postfix);
}
void push(char ch)
{
    if(top == MS -1)
    {
        printf("Stack overflow\n");
        exit(0);
    }
    else 
    s[top++] = ch;
}
int  pop()
{
    if(top == -1)
    {
        printf("Stack underflow");
        exit(0);
    }
    else
    return s[top--];
}