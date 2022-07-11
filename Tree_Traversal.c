#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node*left;
    int info;
    struct node*right;
}NODE;
typedef struct
{
    NODE *data[20];
    int front,rear;
}QUEUE;
void initq(QUEUE *pq)
{
    pq->front = pq->rear=-1;
}
void addq(QUEUE *pq,NODE *treenode)
{
    pq->data[++pq->rear]=treenode;
}
NODE *removeq(QUEUE *pq)
{
    return pq->data[++pq->front];
}
int isempty(QUEUE *pq)
{
    return(pq->front==pq->rear);
}
int isfull(QUEUE *pq)
{
    return(pq->rear==20-1);
}
//**********************************TREE FUNCTION****************************
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
void inorder(NODE *root)            //Inorder function
{
    NODE *temp=root;
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d\t",temp->info);
        inorder(temp->right);
    }
}
void postorder(NODE *root)          //Postorder function
{
    NODE *temp=root;
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t",temp->info);
    }
}
void levelorder(NODE *root)
{
    int i,level=0;
    NODE *temp,*marker=NULL;
    QUEUE q;
    initq(&q);
    addq(&q,root);
    addq(&q,marker);
    printf("\nLevel %d ---->",level);
    while(!isempty(&q))
    {
        temp=removeq(&q);
    if(temp==marker)
        {
            level++;
            if(!isempty(&q))
            {
                addq(&q,marker);
                printf("\nLevel %d------>",level);
            }
        }
        else
        {
            printf("%d\t",temp->info);
            if(temp->left)
                addq(&q,temp->left);
            if(temp->right)
                addq(&q,temp->right);
        }
    }
}
int main()
{
    NODE*root=NULL;
    root=createbst(root);
    printf("\npreorder:");   //function call for preorder
    preorder(root);

    printf("\nInorder:");
    inorder(root);

    printf("\nPostorder:");
    postorder(root);

    printf("\nLevelorder traversal:");
    levelorder(root);
}
