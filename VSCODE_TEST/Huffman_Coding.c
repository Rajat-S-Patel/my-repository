#include<stdio.h>
#include<stdlib.h>

struct Node{
    char data;
    unsigned freq;
    struct Node *left,*right;
};

struct PrioQ{
    unsigned size;
    unsigned capacity;

    struct Node ** array;
};
typedef struct Node* node;
typedef struct PrioQ* Q;
 node newNode(char data,unsigned freq){
    node temp = (node)malloc(sizeof(struct Node));

    temp->left = temp->right;
    temp->data=data;
    temp->freq = freq;

    return temp;
}

Q createQueue(unsigned capacity){
    Q prioQ  = (Q)malloc(sizeof(struct PrioQ));

    prioQ->size=0;
    prioQ->capacity=capacity;

     prioQ->array = (struct Node**)malloc(prioQ->capacity * sizeof(struct Node*)); 
   
    return prioQ; 

}

void swapNode(node *a,node *b){
    node temp = *a;
    *a=*b;
    *b=temp;
}
void MIN_HEAPIFY(Q prioQ,int index){
    int min = index;
    int left = 2*index+1;
    int right = 2*index+2;
    
      if (left < prioQ->size && prioQ->array[left]-> 
freq < prioQ->array[min]->freq) 
        min = left; 
  
    if (right < prioQ->size && prioQ->array[right]-> 
freq < prioQ->array[min]->freq) 
        min = right; 
  
    if (min != index) { 
        swapNode(&prioQ->array[min], 
                        &prioQ->array[index]); 
       MIN_HEAPIFY(prioQ, min); 
    } 
}
int isSizeOne(Q prioQ){
    return prioQ->size==1;
}
node dequeue(Q prioQ){
    node temp=prioQ->array[0];
    prioQ->array[0]=prioQ->array[prioQ->size-1];
    --prioQ->size;
    MIN_HEAPIFY(prioQ,0);

    return temp;
}

void enqueue(Q prioQ, 
                   node element) 
  
{ 
  
    ++prioQ->size; 
    int i = prioQ->size - 1; 
  
    while (i && element->freq < prioQ->array[(i - 1) / 2]->freq) { 
  
        prioQ->array[i] = prioQ->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 
  
    prioQ->array[i] = element; 
} 
void buildMinHeap(Q prioQ) 
  
{ 
  
    int n = prioQ->size - 1; 
    int i; 
  
    for (i = (n) / 2; i >= 0; --i) 
        MIN_HEAPIFY(prioQ, i); 
} 
 void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%d", arr[i]); 
  
    printf("\n"); 
}
int isLeaf(node root) 
  
{ 
  
    return !(root->left) && !(root->right); 
}
Q createAndBuildMinHeap(char data[], int freq[], int size){
  
    Q prioQ = createQueue(size); 
  int i;
    for ( i = 0; i < size; ++i) 
        prioQ->array[i] = newNode(data[i], freq[i]); 
  
   prioQ->size = size; 
    buildMinHeap(prioQ); 
  
    return prioQ; 
}
node buildHuffmanTree(char data[],int freq[],int size){
   node left,right,top;

    Q prioQ = createAndBuildMinHeap(data,freq,size);

    while(!isSizeOne(prioQ)){
        left = dequeue(prioQ);
        right = dequeue(prioQ);
       // printf("left : %d\n",left->freq);
       // printf("right : %d\n",right->freq);
        top = newNode('#',left->freq+right->freq);

        top->left=left;
        top->right=right;

        enqueue(prioQ,top);

        
    }
    return dequeue(prioQ);
}
void printCodes(node root,int arr[],int top){
    if(root->left){
        arr[top]=0;
        printCodes(root->left,arr,top+1);
    }
    if(root->right){
        arr[top]=1;
        printCodes(root->right,arr,top+1);
    }

    if(isLeaf(root)){
        printf("%c : ",root->data);
        printArr(arr,top);
    }
}
void HuffmanCodes(char data[],int freq[],int size){
    node root = buildHuffmanTree(data,freq,size);
    int arr[10],top=0;
    printCodes(root,arr,top);
}   
int main(){
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    HuffmanCodes(arr, freq, size); 
    return 0;
}