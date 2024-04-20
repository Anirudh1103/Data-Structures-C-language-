#include<stdio.h>
#include<stdlib.h>
typedef struct dll
{
    int data;
    struct dll *llink,*rlink;
}node;
node *first = NULL;
void main()
{
    int x,ch,i,key,n;
    void ins_front(int);
    void ins_key(int,int);
    void del(int);
    void display();
    while(1)
    {
        printf("Enter your choice:\n1:create\n2:insertion at given key value\n 3:delete \n 4:display\n 4:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of nodes to be initially created\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("Enter the datat part of node %d",i+1);
                scanf("%d",x);
                ins_front(x);
            }
            break;

            case 2:printf("Enter the key value\n");
            scanf("%d",&key);
            printf("ENter the data part of the new node to be inserted\n");
            scanf("%d",&x);
            ins_key(key,x);
            break;

            case 3:printf("Enter the value of the key to be deleted\n");
            scanf("%d",&key);
            del(key);
            break;

            case 4:display();
            break;

            default:printf("Invalid choice\n");


        }
    }
}
void ins_front(int x)
{
    node *new;
    new = (node*)malloc(sizeof(node));
    new->data = x;
    new ->llink = new->rlink = NULL;
    if(first == NULL)
    {
        first = new;
    }
    else{
        new->rlink = first;
        first->llink= new;
        first = new;

    }
}
void del(int key)
{

}
void ins_key(int key, int x)
{
    node *new,*next,*temp;
    new = (node*)malloc(sizeof(node));
    new->data = x;
    new->llink=new->rlink= NULL;
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        temp = first;
        while((temp!=NULL)&&(temp->data != key))
        {
            temp = temp->rlink;
            next = temp->rlink;
        }
        if(temp == NULL)
        {
            printf("Element with key value %d is not found\n",key);
            return;
        }
        else if(temp == first)
        {
            new->rlink = first;
            first ->llink = new;
            first = new;
        }
        else{
            temp->rlink = new;
            new->llink = temp;
            new->rlink = next;
            next->llink = new;
        }
    }
}
void display()
{
    node *temp;
    if(first == NULL)
    {
        printf("List is emty");
        return;

    }
    else{
        temp = first;
        while(temp!=NULL)
        {
            printf("%d<-->",temp->data);
            temp=temp->rlink;
        }

    }
}