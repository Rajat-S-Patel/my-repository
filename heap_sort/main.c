
// Sample code to perform I/O:
#include <stdio.h>
#include<time.h>
int main(){
	int num;
	scanf("%d", &num);
	int a[num],i=0;
	srand(time(0));
	for(i=0;i<num;i++)
        a[i]=rand()%100000;
	    //scanf("%d",&a[i]);
	heap_sort(&a,num);
    printf("Sorted");
/*	for (i=0;i<num;i++){
	    printf("%d ",a[i]);
	}*/
}
void heap_sort(int *a,int n){
    int i;
    clock_t start_t,end_t,total_t;
    start_t=clock();
    for(i=n/2;i>=0;i--){
        max_heapify(a,i,n);
    }
    for(i=n-1;i>=0;i--){
        int temp = a[0];
        a[0]=a[i];
        a[i]=temp;
        n--;
        max_heapify(a,0,n);
    }
    end_t=clock();
    double time =(end_t-start_t);
    printf("end time : %ld %ld",end_t-start_t,CLOCKS_PER_SEC);
    printf("Time taken : %ld",time/1000.0);
}
void max_heapify(int *a,int i,int n){
    int largest = i;
    int l = 2*i;
    int r=2*i+1;

    if(n>l&&a[l]>a[largest]){
        largest=l;
    }
    if(n>r&&a[r]>a[largest]){
        largest=r;
    }

    if(largest!=i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        max_heapify(a,largest,n);
    }

}

