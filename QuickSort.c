#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b= temp;
}
int PARTITION(int *arr,int low,int high){
    int pivot = arr[high];
    int i = low-1;
    int j;
    for(j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
           // printf("%d ",arr[j]);
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void QuickSort(int *arr,int low,int high){
    //srand(time(0));
    if(low<high){
        int pi = PARTITION(arr,low,high);
       
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);


    }
}

int main(){
    printf("Enter size : ");
    int size;
    scanf("%d",&size);
    srand(time(0));
    int arr[size];
    int i;
    for(i=0;i<size;i++){
        arr[i]=rand()%100;
    }
    QuickSort(arr,0,size-1);
     for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}