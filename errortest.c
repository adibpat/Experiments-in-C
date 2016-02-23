#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char a[10];
  int array[0];
}my_struct;

int data[0];

int main(){
  my_struct adi;
  my_struct *pratz;
  pratz = (my_struct*)malloc(sizeof(my_struct)+(15*sizeof(int)));
  pratz->array = (int*) pratz+1;
  printf("Size of the structure is %ld\n",(long)sizeof(adi));
  printf("Size of the structure is %ld\n",(long)sizeof(*pratz));
  printf("Size of the structure is %ld\n",(long)sizeof(*pratz));
  return(0);
}
