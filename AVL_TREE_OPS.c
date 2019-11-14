#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
typedef struct Node * node;
int height(node n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}
int max(int a,int b){
    return a>b?a:b;
}
node newNode(int data){
    node temp = (node)malloc(sizeof(struct Node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return temp;
}
node rightRotate(node n){
    node n1=n->left;
    node n2 = n1->right;
    n1->right=n;
    n->left=n2;

    n->height=max(height(n->left),height(n->right))+1;
    n1->height=max(height(n1->left),height(n1->right))+1;

    return n1;
}
node leftRotate(node x){
    node y=x->right;
    node q = y->left;
    y->left=x;
    x->right=q;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}
int getBalance(node n){
    if(n==NULL){
        return 0;
    }
    return (height(n->left)-height(n->right));
}
node insert(node n,int data){
    if(n==NULL)
        return newNode(data);
     if (data <n->data) 
        n->left  = insert(n->left, data); 
    else if (data > n->data) 
        n->right = insert(n->right,data);
    else
        return n; 

        n->height=1+max(height(n->left),height(n->right));

        int balance=getBalance(n);

        if(balance>1){
            if(data<n->left->data)
                return rightRotate(n);
            if(data>n->left->data)
            {
                n->left=leftRotate(n->left);
                return rightRotate(n);
            }   
        }
        if(balance<-1){
            if(data>n->right->data)
            return leftRotate(n);
            if(data<n->right->data)
            {
                n->right=rightRotate(n->right);
                return leftRotate(n);
            }
        } 
        return n;   
}
void preOrderTraversal(node root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main(){
    node root = NULL;
    start:

    printf("\n1. Insert \n2. Preordertraversal\n");
    int choice;
    int n;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter number to insert : ");
        scanf("%d",&n);
        root = insert(root,n);
        break;
   case 2:
    preOrderTraversal(root);
}
 goto start;   

}

