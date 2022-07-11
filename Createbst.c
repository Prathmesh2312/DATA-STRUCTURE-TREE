#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node*left;
    int info;
    struct node*right;
}NODE;
NODE*createbst(NODE*root)           //Create tree
{
    NODE *newnode,*temp,*parent;
    int i,n,num;
    printf("Enter how many nodes:");
    scanf("%d",&n);
    printf("Enter nodes:\n");
    for(i=1;i<=n;i++)
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        scanf("%d",&num);
        newnode->info=num;
        newnode->left=newnode->right=NULL;
        //attach new node to the tree

        if(root==NULL)
        {
            root=newnode;
            continue;
        }
        temp=root;
        while(temp!=NULL)       //loop to find parent of the new element
        {
            parent=temp;
            if(num<temp->info)
                temp=temp->left;
            else
                temp=temp->right;
        }
        if(num<parent->info)
            parent->left=newnode;
        else
            parent->right=newnode;
    }
    return root;
}
int main()
{
    NODE*root=NULL;
    root=createbst(root);
}
