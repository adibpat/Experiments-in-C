/* Author Information:
* Aditya B Patwradhan
*/	
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void problem1(){
  int N,M,i,j;
  printf("Enter N,M,i,j in order\n");
  scanf("%d%d%d%d",&N,&M,&i,&j);

  /* Check if i and j fit the values of  N and M */
  if(pow(2,j-i)>M || pow(2,j-i)>N){
    printf("Error in input\n");
    return;
  }

  int first = N>>j;
  first = first<<j;
  int last = pow(2,i);
  last = N & last;
  M = M<<i;
  
  N = first | M | last;

  printf("\n%d\n",N);  
}  

void problem2(){
  double num;
  int a[32];
  for(int i=0;i<32;i++){
    a[i]=0;
  }
  printf("Enter a number between 0 and 1\n");
  scanf("%lf",&num);
  int i = 0;
  while(num<1 && i<32){
    num = num*2;
    //printf("%lf\n",num);
    if(num == 1){
      a[i]=1;
      i++;
      break;
    }
    if(num>1){
      a[i]=1;
      num = num-1;
    }
    else{
      a[i]=0;
    }
    i++;
  }
  if(i==32){
    printf("ERROR\n");
    return;
  }
  printf("Binary Representation of the number is:\n 0.");
  for(int j=0;j<i;j++){
    printf("%d",a[j]);
  }
  printf("\nExiting,Bye");
  
}

void problem3(){
  int N;
  printf("Enter a number\n");
  scanf("%d",&N);
  int bits = ceil(log2(N));
  
  int ones = 0;
  int temp = N;
  while(bits>0){
    if(temp & 1) ones++;
    temp=temp>>1;
    bits--;
  }

  /* Finding the largest number */
  bits=ceil(log2(N));
  int mask = pow(2,ones);
  mask = mask<<(bits-ones);
  printf("Next largest number having same number of ones is %d\n",mask);

  /* Finding the next smallest number */
  int firstOne=0,firstZero;
  temp = N;
  
  while((!(temp&1))&&(firstOne<32)){
    temp=temp>>1;
    firstOne++;
  }
  temp=temp>>1;
  firstZero=firstOne+1;
  while(temp&1 && firstZero<32){
    temp=temp>>1;
    firstZero++;
  }
  //printf("Position of first one and first zero is %d and %d\n",firstOne,firstZero);
  int change= 1<<firstOne;
  N = N^change;
  change= 1<<firstZero;
  N = N^change;

  printf("%d",N);
}

void problem4(){
  int A,B;
  printf("Enter A and B:\n");
  scanf("%d%d",&A,&B);
  int count = 0;
  int i =0;
  while(i<32){
    int mask = 1;
    if((A & mask) != (B & mask)){
      count++;
    }
    A=A>>1;
    B=B>>1;
    i++;
  }
  printf("Number of bits reqired to be altered to change A to B is :%d\n",count);
}



int main(){

  //problem1();
  //problem2();
  //problem3();
  problem4();

  return(0);
}
