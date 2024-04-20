#include<stdio.h>
#include<stdlib.h>
#define MS 5
int s[MS],top=-1;
void main()
{
    void push(int);
    void pop();
    void display();
    int x,ch; 
    while(1)
    {
        printf("Enter your choice\n1:push\n2:pop\n3:display\n4:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the element to be inserted into the stack\n");
            scanf("%d",&x);
            push(x);
            break;

            case 2:pop();
            break;

            case 3: display();
            break;

            case 4:printf("thank you\n");
            exit(0);

            default: printf("Invalid choice\n");
        }
    }

}
void push(int x)
{
    if(top == MS-1)printf("Stack is full\n");
    else 
    {
        s[++top]=x;
        printf("Element %d is successfully inserted into the stack\n",x);
        
    }
}
void pop()
{
    int temp;
    if(top == -1)printf("Stack is empty\n");
    else{
        temp = s[top];
        top--;
        printf("Element %d is successfully deleted from the stack",temp);
        
    }
}
void display()
{
      int i;
    if(top == -1)printf("Stack is empty\n");
    else
    {
        printf("Elements in the stack are:\n");
        for(i=0;i<=top;i++)printf("%d\t",s[i]);
    }
}
