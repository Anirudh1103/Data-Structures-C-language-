#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sll
{
    int id;
    char name[25];
    int sem;
    struct sll *link;
}node;
node *first = NULL;
void main()
{
    int id,sem,n,i,ch,pos;
    char name[25];
    void insfront(int,char name[],int);
    void insend(int,char name[], int);
    void inspos(int, char name[], int , int);
    void delid(int);
    void search_up(int);
    void display();
    while(1)
    {
        printf("Enter your choice:\n1:Create\n2:Insertion at front\n3:Insertion at the end\n4:insertion at given pos\n5:delete using id\n6:search and update\n7:display\n8:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the number nodes to be initially created\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("Enter the id, name and sem of student %d",i+1);
                scanf("%d%s%d",&id,name,&sem);
                insend(id,name,sem);
            }
            break;

            case 2:printf("\nEnter the id, name and sem of student to insert at the front\n");
            scanf("%d%s%d",&id,name,&sem);
            insfront(id,name,sem);
            break;

            case 3:printf("\nEnter the id, name and sem of student to be inserted at the end\n");
            scanf("%d%s%d",&id,name,&sem);
            insend(id,name,sem);
            break;

            case 4:printf("\nEnter the id, name and sem and also pos of student to be inserted at the end\n");
            scanf("%d%s%d%d",&id,name,&sem,&pos);
            inspos(id,name,sem,pos);
            break;

            case 5:printf("\nenter the id of the student to be deleted\n");
            scanf("%d",&id);
            delid(id);
            break;

            case 6:printf("\nenter the id of the student to search and update his/her details\n");
            scanf("%d",&id);
            search_up(id);
            break;

            case 7:display();
            break;

            case 8:printf("Thank you\n");
            exit(0);

            default:printf("Invalid choice\n");


            
        }
    }

}
void insfront(int id,char name[25],int sem)
{
    node *new;
    new=(node*)malloc(sizeof(node));
    new->id=id;
    strcpy(new->name,name);
    new->sem=sem;
    new->link=NULL;
    if(first == NULL)first=new;
    else
    {
        new->link = first;
        first = new;
    }


}
void insend(int id,char name[25], int sem)
{
    node *new,*temp;
    new=(node*)malloc(sizeof(node));
    new->id=id;
    strcpy(new->name,name);
    new->sem=sem;
    new->link=NULL;
    if(first = NULL)
    {
        first = new;
    }
    else
    {
        temp = first;
        while(temp->link!=NULL)
        temp=temp->link;
        temp->link = new;
    }

}
void inspos(int id, char name[25], int sem , int pos)
{
    int i;
    node *new,*temp,*prev;
    new=(node*)malloc(sizeof(node));
    new->id=id;
    strcpy(new->name,name);
    new->sem=sem;
    new->link=NULL;
    temp=first;
    for(i=0;i<=pos;i++)
    {
        prev = temp;
        temp = temp->link;
    }
    if(pos == 1)
    {
        new->link = first;
        first = new;
    }
    else{ 
    prev->link = new;
    new->link = temp;
    }

}
void delid(int id)
{
    node *temp,*prev;
    if(first == NULL)
    {
        printf("list is empty\n");
        return;
    }
    else{
        temp = first;
        while((temp!=NULL)&&(temp->id!=id))
        {
            prev = temp;
            temp=temp->link;
        }
        if(temp == NULL)
        {
            printf("Student with id %d isnot found",id);
            return;
        }
        else if(temp == first)
        {
            first = first->link;
            free(first);
        }
        else{
        prev->link=temp->link;
        free(temp);
        }
    }

}
void search_up(int id)
{
    node *temp;
    temp = first;
    while((temp!=NULL)&&(temp->id!=id))
    temp = temp->link;
    if(temp == NULL)
    {
        printf("Student with id %d not found",id);
    }
    else
    {

    printf("Enter the id, name and sem of the student to update details\n");
    scanf("%d%c%d",&temp->id,temp->name,&temp->sem);
    }


}
void display()
{
    node *temp;
    if(first == NULL)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        temp = first;
        printf("Contents of list are:\n");
        while(temp!=NULL)
        {
            printf("%d%s%d",temp->id,temp->name,temp->sem);
            temp=temp->link;
        }
    }

}
