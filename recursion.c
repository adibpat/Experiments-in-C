#include <stdio.h>
#include <stdlib.h>

int getWays(int n){

  if(n<0){
    return(0);
  }
  else if(n==0){
    return(1);
  }
  else{
    return (getWays(n-1) + getWays(n-2) + getWays(n-3));
  }
}
  
int reach(int X, int Y){
  if(X==0 && Y==0){
    return 1;
  }
  else if(X==0 && Y!=0){
    return (reach(X,Y-1));
  }
  else if(X!=0 && Y==0){
    return (reach(X-1,Y));
  }
  else{
    return (reach(X-1,Y) + reach(X,Y-1));
  }
}

int magic(int a[],int lb, int ub){
  int mid = (lb+ub)/2;
  if(a[mid] == mid){
    return a[mid];
  }
  else if(a[mid]>mid){
    magic(a,lb,mid);
  }
  else{
    magic(a,mid+1,ub);
  }
}
  
int calCents(int cents, int denom[], int size, int index){
  int remaining = cents, ways=0;
  if(index>=size-1){
    return(1);
  }
  else{
    for(int i=0;i*denom[index]<=cents;i++){
      printf("Sent %d times %d\n",i,denom[index]);
      ways = ways + calCents(cents-(i*denom[index]),denom,size,index+1);
    }
    return(ways);
  }
}

void problem1(){
  int N;
  printf("Enter number of steps:\n");
  scanf("%d",&N);
  int ways = getWays(N);
  printf("\nThe number of ways in which you can do this is %d.\n",ways);
}

void problem2(){
  int X,Y;
  printf("Enter the values of X and Y:");
  scanf("%d%d",&X,&Y);
  int ways = reach(X,Y);
  printf("\nThe number of ways of reaching X,Y from (0,0) is %d\n",ways);
}

void problem3(){
  int *array;
  int N;

  printf("Enter the size of arary: ");
  scanf("%d",&N);
  array = (int*)malloc(sizeof(int)*N);
  printf("Enter %d elements of the array in sorted order:\n",N);

  for(int i=0;i<N;i++){
    scanf("%d",&array[i]);
  }

  printf("\n");

  int magicNum = magic(array,0,N-1);
  printf("The magic number in the sorted array is %d\n",magicNum);
}

void problem8(){
   
  int denom[]={25,10,5,1};
  for(int i=0;i<4;i++){
    printf("The denominations are:%d\n",denom[i]);
  }
  int cents;
  printf("Enter the number of cents as input: ");
  scanf("%d",&cents);
  int waysf = calCents(cents,denom,4,0);
  printf("The number of ways which make %d cents is %d ways.\n",cents,waysf);
}


int main(){

  //problem1();
  //problem2();
  problem8();
  return(0);
}
