  #include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 2
int pq[3][MAX_SIZE],pf[3]={-1,-1,-1},pr[3]={-1,-1,-1};
void main()
{
int ch,x,p;
void pqinsert(int,int);
void pqdelete();
void pqdisplay();
while(1)
   {
     printf("\n enter your choice:\n 1.insert\n 2.delete\n 3.display\n 4.exit\n");
     scanf("%d",&ch);
     switch(ch)
	{
	 case 1: printf("enter the element to be inserted and priority\n");
	        scanf("%d%d",&x,&p);
	        pqinsert(x,p-1);
	        break;
	 case 2:pqdelete();
	        break;
	 case 3:pqdisplay();
	        break;
	 case 4:printf("\n thank you\n");
	        getchar();
                exit(0);
         default :printf("\n invalid choice\n");
		 
         }
     
     }
}
void pqinsert(int x,int i)
{
 if(pr[i]==MAX_SIZE-1)
 {
  printf("queue with priority %d is full, insertion is not possiblr\n",i+1);
  return;
 }
 pr[i]++;
 pq[i][pr[i]]=x;
 printf("element %d is inserted into queue with priority %d \n",x,i+1);
 if(pf[i]==-1)
 pf[i]=0;
}

void pqdelete()
{
 int temp,i;
 for(i=0;i<3;i++)
  {
   if(pf[i]==-1)
    printf("\n queue %d is empty\n",i+1);
    else
    {
     temp=pq[i][pf[i]];
     if(pf[i]==pr[i])
      pf[i]=pr[i]=-1;
     else
     pf[i]++;
     printf("\nelement %d is deleted from queue with the priority %d\n",temp,i+1);
     break;
    }
  }
}
void pqdisplay()
{
int i,j;
for(i=0;i<3;i++)
 {
  if(pf[i]==-1)
   printf("\n queue with priority %d is empty\n",i+1);
   else
    {
     printf("\n elements in queue with a priority %d :\n",i+1);
     for(j=pf[i];j<=pr[i];j++)
     printf("%d\t",pq[i][j]);
     }
   } 
}

     
