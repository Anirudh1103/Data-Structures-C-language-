#include<stdio.h>
#include<stdlib.h>
#define MS 5
int q[MS],f=-1,r=-1;
void main()
{
    void qinsert(int);
    void delete();
    void display();
    int x,ch;
    while(1)
    {
        printf("Enter your choice\n1:insert\n2:delete\n3:display\n4:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the element to be inserted into the queue\n");
            scanf("%d",&x);
            qinsert(x);
            break;

            case 2:delete();
            break;

            case 3:display();
            break;

            case 4: printf("Thank you\n");
            exit(0);

            default: printf("Invalid choice\n");

        }
    }

}
void qinsert(int x)
{
    if(r==MS-1)
    {
        printf("queue is full\n");
        return;
    }
    r++;
    q[r]=x;
    if(f==-1)f=0;
    printf("Element %d is successfully inserted\n",x);
}

void delete()
{
    int t;
    if(f==-1)
    {
        printf("queue is empty\n");
        return;
    }
    t=q[f];
    if(f==r)
    f=r=-1;
    else
    f++;
    printf("element %d is successfully deleted from the queue\n",t);
   }
 void display()
{
    int t;
    if(f==-1)
    {
        printf("queue is empty\n");
        return;
    }
    else 
    {
        printf("Elements in the queue are:\n");
        for(t=f;t<=r;t++)printf("%d\t",q[t]);
    }
    

 }
