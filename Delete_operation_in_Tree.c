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
void preorder(NODE *root)           //Preorder function
{
    NODE *temp=root;
    if(temp!=NULL)
    {
        printf("%d\t",temp->info);      //data
        preorder(temp->left);           //left
        preorder(temp->right);          //right
    }
}
NODE *deletebst(NODE* root ,int key)
{
    NODE* temp;
    if(root==NULL)
        return NULL;
    if(key<root->info)
        root->left=deletebst(root->left,key);       //left subtree
    else if(key>root->info)
        root->right=deletebst(root->right,key);     //right subtree
    else                                            //Not found
    {
        //Leaf Node
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        //Node with no children. Find the inorder successor
        temp=root->right;
        while(temp&&temp->left!=NULL)
            temp=temp->left;
        //Copy the inorder successor's content to node to be deleted.
        root->info=temp->info;
        //Delete the inorder successor.
        root->right=deletebst(root->right,temp->info);
    }
    return root;
}
int main()
{
    int key,x;
    NODE*root=NULL;
    root=createbst(root);

    printf("\nPreorder:");   //function call for preorder
    preorder(root);

    printf("\nEnter number to be deleted:");
    scanf("%d",&x);
    root=deletebst(root,x);

    printf("\nNumber is deleted successfully\n");
    preorder(root);
}
