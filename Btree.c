#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{
 int data;
 struct bst *lchild,*rchild;
}node;
 node *root=NULL;
 void main()
 {
  int n,i,x,ch;
  void create(int);
  void display(node*);
  void inorder(node*);
  void preorder(node*);
  void postorder(node*);
while(1)
{
printf("enter the choice\n");
printf("\n1.create\n2.display\n3.inorder traversal\n4.preorder traversal\n5.postorder traversal\n6.exit\n");

scanf("%d",&ch);
switch(ch)
{
 case 1:printf("enter the number of nodes to be created in a bst\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
          printf("\n enter the data part of node %d\n",i+1);
   	  scanf("%d",&x);
   	  create(x);
        }
        break;
 case 2:if(root==NULL)
          printf("\n bst is empty");
        else
        {
        printf("element of the BST are\n");
        display(root);
        }
        break;
 case 3:if(root==NULL)
           printf("\n bst is empty\n");
        else
        {
         printf("\n inorder tree traversal\n");
         inorder(root);
        }
        break;
 case 4:if(root==NULL)
          printf("\n bst is empty\n");
        else
        {
         printf("\n preorder tree traversal\n");
         preorder(root);
        }
         break;
 case 5:if(root==NULL)
          printf("\n bst is empty\n");
        else
        {
         printf("\n postorder tree traversal\n");
         postorder(root);
        }
         break;
 case 6:printf("\n thankyou\n");
 	  getchar();
	  exit(0);
 default:printf("\n  invalid choice\n");
}
printf("\n press any key to continue\n");
getchar();
}
}
void create(int x)
{
 node *new,*temp;
 new=(node*)malloc(sizeof(node));
 new->data=x;
 new->lchild=new->rchild=NULL;
 if(root==NULL)
   root=new;
 else
 {
  temp=root;
  while(1)
  {
   if(x<temp->data)
          if(temp->lchild==NULL)
                {
                   temp->lchild=new;
                   break;
                 }
                   else
                   temp=temp->lchild;
      else if(x>temp->data)
            if(temp->rchild==NULL)
                 {
                   temp->rchild=new;
                    break;
                  }
                    else
	       temp=temp->rchild;
            else
                {
                  printf("\n node with data %d already exists, enter the new data \n",x);
   	          scanf("%d",&x);
   	          create(x);
                  break;
                }
  }
 }
}
void display(node *root)
{
 if(root!=NULL)
 {
  display(root->lchild);
  printf("%d\t",root->data);
  display(root->rchild);
 }
}
void inorder(node *root)
{
 if(root!=NULL)
 {
  inorder(root->lchild);
  printf("%d\t",root->data);
  inorder(root->rchild);
 }
}
void preorder(node *root)
{
 if(root!=NULL)
 {
  
  printf("%d\t",root->data);
  preorder(root->lchild);
  preorder(root->rchild);
 }
}
void postorder(node *root)
{
 if(root!=NULL)
 {
  postorder(root->lchild);
  postorder(root->rchild);
  printf("%d\t",root->data);
 }
}
