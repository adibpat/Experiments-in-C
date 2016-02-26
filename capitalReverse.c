#include <stdlib.h>
#include <stdio.h>

void swap(char *a,char *b){
  char temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  
  char str[101];
  printf("Enter your string upto 100 characters\n");
  scanf("%s",str);

  char *start=str;
  char *end=str;

  while(*end!='\0'){
    end = end +1;
  }
  end = end-1;

  while(end>=start){
    while(*end>=97){
      end=end-1;
    }
    while(*start>=97){
      start=start+1;
    }
    swap(start,end);
    end=end-1;
    start=start+1;
  }

  printf("The string after capital alphabets are reversed is %s\n",str);
  
  return(0);
}
