#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int vercmp(char *v1, char *v2){
  char *str1,*str2;
  assert(v1!=NULL && v2!=NULL);
  str1=v1;str2=v2;
  while(1){
    int a = atoi(str1);
    int b = atoi(str2);
    if(a>b){
      return(1);
    }
    else if(a<b){
      return(-1);
    }
    else{
      while(*str1!='.' && *str1!='\0'){
	str1++;
      }
      while(*str2!='.' && *str2!='\0'){
	str2++;
      }
      if(*str1 && *str2)break;
      str1++;str2++;
    }
  }
  if(*str1 == '\0' && *str2== '.')return(-1);
  if(*str2 == '\0' && *str1== '.')return(1);
  if(*str1 == '\0' && *str2 == '\0')return(-0);
  
  
}


int main(){
  assert(vercmp("1","2")==-1);
  assert(vercmp("1","1.0")==-1);
  assert(vercmp("1.0.0.5","1.0.0.0.6")==1);
  assert(vercmp("1.0.5","6.0.0.2")==-1);
  assert(vercmp("1","1.0")==-1);
  printf("All test cases passed\n");
  return(0);
}
