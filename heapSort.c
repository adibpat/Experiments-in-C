#include <stdio.h>
#include <stdlib.h>

void buildHeap(int [],int);

void heapify(int [],int,int);

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){

  int n;
  printf("Enter the number of elements in the array:\n");
  scanf("%d",&n);
  int *array = (int*)malloc(sizeof(int)*(n+1));
  *array = 0;
  printf("Start entering the number of elements:\n");
  for(int i=1;i<=n;i++){
    scanf("%d",array+i);
  }

  buildHeap(array,n);

  for(int i=1;i<=n;i++){
    printf("%d ",array[i]);
  }
  printf("\n");

  return(0);
}

void heapify(int *ar,int pos,int size){
  if(pos<=(size/2)){
      int c1 = pos*2, c2 = 2*pos+1;
      int maxChild = ar[c1]>ar[c2]?c1:c2;
      if(ar[maxChild]>ar[pos]){
	swap((ar+maxChild),(ar+pos));
	heapify(ar,maxChild,size);
      }
    }
}

void buildHeap(int *a, int size){
  for(int i=size/2;i>=1;i--){
    heapify(a,i,size);
  }
}
       
