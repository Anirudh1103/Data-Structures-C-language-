#include<stdio.h>
#include<stdlib.h>
#define MS 2
int pq[3][MS],pf[3]={-1,-1,-1},pr[3]={-1,-1,-1};
void main()
{
    int x,ch,p;
    void insert(int,int);
    void delete();
    void display();
    while(1)
    {
        printf("\nEnter your choice\n1:insert\n2:delete\n3:display\n4:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the element to be inserted and its priority\n");
            scanf("%d%d",&x,&p);
            insert(x,p-1);
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
void insert(int x, int i)
{
  if(pr[i]==MS-1)
  {
    printf("\nQueue with priority %d is full\n",i+1);
    return;
  }
  else{
    pr[i]++;
    pq[i][pr[i]]=x;
    printf("\nelement %d with priority %d is successfully inserted into the queue\n",x,i+1);
    if(pf[i]==-1)pf[i]=0;
  }
}
void delete()
{
    int t,i;
    for(i=0;i<3;i++)
    {
        if(pf[i]==-1)printf("\nqueue with priority %d is empty\n",i+1);
        else
        {
            t=pq[i][pf[i]];
            if(pf[i]==pr[i])pf[i]=pr[i]=-1;
            else
            pf[i]++;
            printf("\nelement %d with priority %d is successfully deleted \n",t,i+1);
            break;

        }
    }
    

}
void display()
{
    int i,j;
    for(i=0;i<3;i++)
    {
    if(pf[i]==-1)
    printf("queue with priority %d is empty",i+1);
    else
    {
    printf("\nElements in the queue with priority %d:\n",i+1);
    for(j=pf[i];j<=pr[i];j++)
    printf("%d\t",pq[i][j]);
    }
    }

    

}