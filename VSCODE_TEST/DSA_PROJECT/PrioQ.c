#include<stdio.h>
#include<stdlib.h>

struct PrioQ{
    int *arr;
    unsigned capacity;
    unsigned size;

};
typedef struct PrioQ* queue;
queue createQ(unsigned capacity){
    queue temp = (queue)malloc(sizeof(struct PrioQ));
    temp->arr = (int *)malloc(sizeof(int)*capacity);
    temp->capacity=capacity;
    temp->size=0;
    return temp;
}
void MIN_HEAPIFY(queue q,int index){
    int min = index;
    int left=2*index+1;
    int right = 2*index+2;
    if(left<q->size&&q->arr[left]<q->arr[min]){
        min = left;
    }
    if(right<q->size&&q->arr[right]<q->arr[min]){
        min=right;
    }
    if(min!=index){
        int temp=q->arr[index];
        q->arr[index]=q->arr[min];
        q->arr[min]=temp;

        MIN_HEAPIFY(q,min);
    }
}
void build_min_heap(queue q) {
  int i;
  for(i=q->size/2; i>=0; i--) {
    MIN_HEAPIFY(q, i);
  }
}
void enqueue(queue q,int n){
    
    ++q->size; 
    q->arr[q->size-1] = n;
    build_min_heap(q);
    //int i = q->size - 1; 
  
   /* while (i && n < q->arr[(i - 1) / 2]) { 
  
        q->arr[i] = q->arr[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    }*/ 
  
     
}



int dequeue(queue q){
    if(q->size<=0){
        printf("Empty ...");
        return;
    }
    int temp=q->arr[0];
    q->arr[0]=q->arr[q->size-1];
    q->size--;
    MIN_HEAPIFY(q,0);
    return temp;
}
int peek(queue q){
    return q->arr[0];
}
void display(queue q){
    int i=0;
    
    for(i=0;i<q->size;i++){
        printf("%d ",q->arr[i]);
    }
}
void main(){
    queue q = createQ(10);
    start:
    printf("\n1. enqueue\n2. dequeue\n3. peek\n4. display");
    int choice,data;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("data : ");
            scanf("%d",&data);
            enqueue(q,data);
            break;
             case 2:
          //  printf("data : ");
            //scanf("%d",&data);
            data=dequeue(q);
            printf("Data : %d",data);
            break;
            case 3:
            data = peek(q);
            printf("Data : %d",data);
            break;
            case 4:
            display(q);
            break;
    }
    goto start;
}