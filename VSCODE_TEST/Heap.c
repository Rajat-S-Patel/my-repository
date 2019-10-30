#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b);
void Display(int A[],int N);
void MAX_HEAPIFY(int A[],int i,int N);
void heap_sort(int A[],int N);
void build_maxHeap(int A[],int N);
int main(){
      int A[] = {1,2,5,6,11,12,9,0};
      heap_sort(A,8);
      Display(A,8);
}
void MAX_HEAPIFY(int A[],int i,int N){
      int left = 2*i;
      int right = 2*i+1; 
      int largest = i;
      if(A[largest]<A[left]&&left<N){
            largest=left;
      }
      if(A[largest]<A[right]&&right<N){
           largest=right;
      }
      if(largest!=i){
            swap(&A[largest],&A[i]);
            MAX_HEAPIFY(A,largest,N);
      }


      
}
void build_maxHeap(int A[],int N){
    int i;
      for( i=N/2;i>=0;i--){
            MAX_HEAPIFY(A,i,N);
      }
}
void heap_sort(int A[],int N){
      build_maxHeap(A,N);
      int i;
      for(i=N-1;i>=0;i--){
            swap(&A[0],&A[i]);
             N--;
            MAX_HEAPIFY(A,0,N);
            
      }
}
void Display(int A[],int N){
      int i;
      for(i=0;i<N;i++){
            printf("%d ",A[i]);
      }
}
void swap(int *a,int *b){
     // printf("\na : %d and b : %d before\n",*a,*b);
      int temp = *a;
      *a=*b;
      *b=temp;
     // printf("\na : %d and b : %d after\n",*a,*b);
}