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
NODE*insertbst(NODE *root, int x)
{
	if (root == NULL)
	{
            root =(NODE*)malloc(sizeof(NODE));
            root->info = x;
            root->left = root->right = NULL;
            return root;
	}
	else if (x < root->info)
            root->left = insertbst(root->left, x);
	else if (x > root->info)
            root->right = insertbst(root->right, x);
	return root;
}
int main()
{
    int key,x;
    char ch;
    NODE*root=NULL;
    root=createbst(root);

    printf("\nPreorder:");   //function call for preorder
    preorder(root);

    printf("\nEnter data to be inserted:");
    scanf("%d",&x);
    root=insertbst(root,x);
    printf("\nDo you want to enter another element Y for Yes and N for No:");
    scanf(" %c",&ch);
    while (ch == 'y')
    {
        printf("\nEnter an element:");
        scanf("%d", &x);
        root = insertbst(root,x);
        printf("\nPress Y or N to insert another element: ");
        scanf(" %c", &ch);
    }
    printf("Data is Inserted sucessfully\n");
    preorder(root);
}
