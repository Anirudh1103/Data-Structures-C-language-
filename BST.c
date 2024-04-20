#include<stdlib.h>
#include<stdio.h>
typedef struct bst
{
    int data;
    struct bst *rchild,*lchild;
}node;
node *root = NULL;
void main()
{
    int x,ch,i,n;
    void create(int);
    void display(node *);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);

    while(1)
    {
        printf("Enter your choice:\n1:create\n2:display\n3:Inorder\n4:preorder\n5:postorder\n6:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number of nodes to be created\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("Enter the data part of node %d\n",i+1);
                scanf("%d",&x);
                create(x);
            }
            break;

            case 2:if(root == NULL)printf("BST is empty");
            printf("Elements in BST are:\n");
            display(root);
            break;

            case 3:if(root == NULL)printf("BST is empty");
            printf("Inorder traversal\n");
            inorder(root);
            break;

            case 4:if(root == NULL)printf("BST is empty");
            printf("preorder traversal\n");
            preorder(root);
            break;

            case 5:if(root == NULL)printf("BST is empty");
            printf("postorder traversal\n");
            postorder(root);
            break;

            case 6:printf("Thank you\n");
            exit(0);

            default: printf("Invalid choice\n");
        }
    }
}
void create(int x)
{
    node *new,*temp;
    new = (node*)malloc(sizeof(node));
    new->data=x;
    new->lchild = new ->rchild = NULL;

    if(root == NULL)root = new;
    else
    {
        temp = root;
     while(1)
    {
        if(x<temp->data)
        if(temp->lchild==NULL)
        {
            temp->rchild=new;
            break;
        }
        else
        temp = temp->lchild;

        else if(x>temp->data)
        if(temp->rchild==NULL)
        {
            temp->rchild = new;
            break;

        }
        else
        temp = temp->rchild;
    else
    {
        printf("Node with element %d already exists\n enter  a new data\n");
        scanf("%d",&x);
        create(x);
        break;

    }


     }
    } 
}
void display(node *root)
{
    if(root != NULL)
    {
        display(root->lchild);
        printf("%d\t",root->data);
        display(root->rchild);
    }
}

void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->lchild);
        printf("%d\t",root->data);
        inorder(root->rchild);
    }
}

void preorder(node *root)
{
    if(root != NULL)
    {
        printf("%d\t",root->data);
        preorder(root->lchild);
        
        preorder(root->rchild);
    }
}

void postorder(node *root)
{
    if(root != NULL)
    {
        
        postorder(root->lchild);
        
        postorder(root->rchild);
        printf("%d\t",root->data);
    }
}