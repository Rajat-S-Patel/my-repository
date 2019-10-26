#include<stdio.h>
#include<stdlib.h>

int height=0;
struct Tree
{
   int key;
   struct Tree *left;
   struct Tree *right;
   struct Tree *parent;
};

typedef struct Tree *node;
struct Queue{
    node data;
    struct Queue *next;

};


typedef struct Queue *queue;
queue front = NULL;
queue rear = NULL;
queue createNodeQueue(node data){
    queue temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->next=NULL;
    temp->data=data;
    return temp;
}
queue peek(){
   queue temp;
	if(front==NULL){
	//printf("Empty Queue");
	return front;
	}

	else{
	  return front;
	}
}
int isEmpty(){
	return front==NULL;
}
void insert(node data){
    queue temp = createNodeQueue(data);
    if(rear==NULL){
        rear = temp;
        front=temp;
    }
    else{
        rear->next = temp;
        rear = rear->next;
    }
}
queue deleteElement(){
    queue temp;
    if(front==NULL){
      printf("Empty");
      return front;
    }
    else{
        temp = front;
        front = front->next;
    }
    return temp;
}
void displayQ(){
    queue f = front;
    queue r = rear;
    while(f!=NULL){
        printf("%d ",f->data);
        f= f->next;
    }
}
int sizeTree=0;
node createNode(){
    node temp;

    temp = (node)malloc(sizeof(struct Tree)*1);
    temp->left=NULL;
    temp->key=0;
    temp->right=NULL;
    temp->parent = NULL;
    sizeTree++;
    return temp;

}
char treeRef[10];
int k = 0;
void dfsTraverse(){

        node temp;
        if(peek()!=NULL){
          temp = (peek())->data;

            printf("%d ",temp->key);
        }
        if(temp->left!=NULL){
                treeRef[k]='l';
                k++;
            insert(temp->left);

        }

        if(temp->right!=NULL){
                treeRef[k]='r';
                k++;
            insert(temp->right);
        }
        if(temp!=NULL&&!isEmpty()){
            deleteElement();
            dfsTraverse();
        }
        else{
            printTree();
        }



}
void printTree(){
    int i=0;
    for(i=0;i<sizeTree;i++){
        printf("%c ",treeRef[i]);

    }
}
void postorder(node root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
       /* if(root->parent!=NULL){
        if(root->parent->right!=NULL&&root->parent->right!=root)
        postorder(root->parent->right);
        }
        //printf("%d ",root->key);*/
    }
}
node inOrderSuccessor(node root){
   node current = root;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
   /* if(root==NULL){
        return root;
    }
    else{
        root = inOrderSuccessor(root->left);
    }*/
}
node prev=0;

node insertNode(node root , int key){

   if(root!=NULL){
       if(root->key>key){

          // root->left->parent = root;
          prev = root;
           root->left=insertNode(root->left,key);

       }
       if(root->key<key){

      //  root->right->parent = root;
            prev = root;

           root->right=insertNode(root->right,key);
       }
   }
   else if(root==NULL){
       node temp = createNode();
       temp->key=key;
       if(prev!=0)
       printf("root key %d",prev->key);
       temp->parent=prev;
       return temp;
   }
   return root;
}
void inOrder(node root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d  ",root->key);
        inOrder(root->right);
    }
}
void preorder(node root){
    if(root!=NULL){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void findHeight(node root){
    int hLeft=0,hRight=0;
    node temp = root;
    while(temp!=NULL){
        temp=temp->left;
        hLeft++;
    }
    temp = root;
    while(temp!=NULL){
        temp = temp->right;
        hRight++;
    }
    height = hLeft>hRight?hLeft:hRight;
}
node deleteNode(node root, int key){
   //  printf("key is root  : \n");
    if(root==NULL){
     //   printf("root NULL \n");
        return root;

    }
    else if(root->key<key){
       // printf("check 1\n");
        root->right=deleteNode(root->right,key);

    }
    else if(root->key>key){
        //printf("check 2\n");
        root->left=deleteNode(root->left,key);
    }
    else {
        //printf("Else condition\n");
        if(root->left==NULL){
            node temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node temp = root->left;
            free(root);
            return temp;
        }
       node tmp =  inOrderSuccessor(root->right);

       //tmp->left=root->left;
       root->key=tmp->key;
     //  printf("key is : %d",tmp->key);
        root->right=deleteNode(root->right,tmp->key);
    }
    return root;
}
int main(){
    node root=NULL;
    printf("BINARY SEARCH TREE OPERATIONS\n");
    start:
    printf("\nEnter your choice : \n");
    int choice;
    printf("1. Insert\n2. Delete\n3. Inorder Traversal\n4. Preorder Transversal\n5. Postorder Traversal\n6. DFS");
    int key;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter value to insert : ");
        scanf("%d",&key);
        root = insertNode(root,key);
        // inOrder(root);
        break;

    case 2:
        printf("Enter value to delete : ");
        scanf("%d",&key);
        root = deleteNode(root,key);
         //inOrder(root);
        break;
    case 3:
        inOrder(root);
        break;
    case 4:
        preorder(root);
        break;
    case 5:
        postorder(root);
        break;
        case 6:
        insert(root);
        treeRef[k] = 'r';
        k++;
        dfsTraverse();
        break;
    }

    goto start;
    return 0;
}
