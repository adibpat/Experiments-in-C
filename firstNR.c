#include <stdio.h>
#include <stdlib.h>

void strCheck(char *);

int main(){

  char str[100];
  printf("Enter string for analysis\n");

  gets(str,99);
  printf("Received String is : \n");
  puts(str);

  strCheck(str);
  return(0);
}

void strCheck(char *string){
  char * str = string, *chk;
  while(*str != '\0'){
    chk = string;
    //printf("Checking for %c\n",*str);
  here:
    while(*chk != *str && *chk != '\0'){
      //printf("%c does not match %c\n",*str,*chk);
      chk=chk+1;
    }
    if(*chk == *str && chk == str){
      chk=chk+1;
      goto here;
    }
    if(*chk == '\0'){
      printf("The first non-repeating character is %c\n",*str);
      return;
    }
    str=str+1;
  }
  printf("All Characters repeat\n");
}
