#include<stdio.h>
#include<stdlib.h>

struct MinHeapNode{
    char data;
    unsigned freq;
    struct MinHeapNode *left,*right;
};

struct MinHeap{
    unsigned size;
    unsigned capacity;

    struct MinHeapNode ** array;
};

struct MinHeapNode* newNode(char data,unsigned freq){
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));

    temp->left = temp->right;
    temp->data=data;
    temp->freq = freq;

    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity){
    struct MinHeap *minheap = (struct MinHeap*)malloc(sizeof(struct MinHeap));

    minheap->size=0;
    minheap->capacity=capacity;

     minheap->array = (struct MinHeapNode**)malloc(minheap->capacity * sizeof(struct MinHeapNode*)); 
   
    return minheap; 

}

void swapMinHeapNode(struct MinHeapNode **a,struct MinHeapNode **b){
    struct MinHeapNode *temp = *a;
    *a=*b;
    *b=temp;
}
void MIN_HEAPIFY(struct MinHeap *minHeap,int index){
    int min = index;
    int left = 2*index+1;
    int right = 2*index+2;
      if (left < minHeap->size && minHeap->array[left]-> 
freq < minHeap->array[min]->freq) 
        min = left; 
  
    if (right < minHeap->size && minHeap->array[right]-> 
freq < minHeap->array[min]->freq) 
        min = right; 
  
    if (min != index) { 
        swapMinHeapNode(&minHeap->array[min], 
                        &minHeap->array[index]); 
       MIN_HEAPIFY(minHeap, min); 
    } 
}
int isSizeOne(struct MinHeap* minHeap){
    return minHeap->size==1;
}
struct MinHeapNode* extractMin(struct MinHeap* minHeap){
    struct MinHeapNode* temp=minHeap->array[0];
    minHeap->array[0]=minHeap->array[minHeap->size-1];
    --minHeap->size;
    MIN_HEAPIFY(minHeap,0);

    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, 
                   struct MinHeapNode* minHeapNode) 
  
{ 
  
    ++minHeap->size; 
    int i = minHeap->size - 1; 
  
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 
  
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 
  
    minHeap->array[i] = minHeapNode; 
} 
void buildMinHeap(struct MinHeap* minHeap) 
  
{ 
  
    int n = minHeap->size - 1; 
    int i; 
  
    for (i = (n - 1) / 2; i >= 0; --i) 
        MIN_HEAPIFY(minHeap, i); 
} 
 void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%d", arr[i]); 
  
    printf("\n"); 
}
int isLeaf(struct MinHeapNode* root) 
  
{ 
  
    return !(root->left) && !(root->right); 
}
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){
  
    struct MinHeap* minHeap = createMinHeap(size); 
  int i;
    for ( i = 0; i < size; ++i) 
        minHeap->array[i] = newNode(data[i], freq[i]); 
  
    minHeap->size = size; 
    buildMinHeap(minHeap); 
  
    return minHeap; 
}
struct MinHeapNode* buildHuffmanTree(char data[],int freq[],int size){
    struct MinHeapNode *left,*right,*top;

    struct MinHeap* minHeap = createAndBuildMinHeap(data,freq,size);

    while(!isSizeOne(minHeap)){
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('#',left->freq+right->freq);

        top->left=left;
        top->right=right;

        insertMinHeap(minHeap,top);

        
    }
    return extractMin(minHeap);
}
void printCodes(struct MinHeapNode* root,int arr[],int top){
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
    struct MinHeapNode* root = buildHuffmanTree(data,freq,size);
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