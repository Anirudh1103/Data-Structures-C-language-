#include<stdio.h>
#include<stdlib.h>
#define MS 5
int cq[MS],cf=-1,cr=-1;
void main()
{
    void insert(int);
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
            insert(x);
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
void insert(int x)
{
    int temp;
    if(cr == MS-1){
    cr=0;
    temp=cr;
    }
    else cr++;
    if(cf==cr)
    {
        printf("queue is full\n");
        return;
    }
    else
    cq[cr]=x;
    printf("Element %d is successfully inserted into the queue\n",x);
    if(cf==-1)cf=0;

}
void delete()
{
    int t;
    if(cf==-1)
    {
        printf("queue is empty\n");
        return;
    }
    else
    t=cq[cf];
    if(cf==cr)cf=cr=-1;
    else if(cf==MS-1)cf=0;
    cf++;
    printf("element %d is deleted from the queue\n",t);
    
}
void display()
{
   
}
