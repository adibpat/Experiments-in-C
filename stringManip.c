#include <stdio.h>
#include <stdlib.h>

void reverse(){

  printf("Enter your string:\n");
  char str[100],rev[100];
  scanf("%s",str);
  int count = 0;
  while( (*(str+count)) != '\0'){
    count++;
  }
  printf("\nCount is %d\n",count);
  count--;
  int i = 0;
  while((*(str+i)) != '\0'){
    *(rev+count)=*(str+i);
    count--;
    i++;
    
  }
  printf("Revrsed string is:%s\n",rev);
}

void altChar(){

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int N;
  scanf("%d",&N);
  char str[100000];
  while(N--){
    scanf("%s",str);
    int count = 0;
    char *strPtr = str;
    while(*strPtr!='\0'){
      if(*(strPtr)==*(strPtr+1)){
	count++;
      }
      strPtr=strPtr+1;
    }
    printf("%d",count);
  }
}


void findPalind(char *arr)
{
  
  int flag = 0, len = 0;
  // Find the required answer here. Print Yes or No at the end of this function depending on your inspection of the string
  int array[26];
  int check[26];
  for(int i=0;i<26;i++){
    array[i]=0;
    check[i]=0;
  }
  while(*(arr+len)!='\0'){
    printf("%d",*(arr+len));
    array[(*(arr+len))-97]++;
    len++;
  }
  printf("%d",len);
  if(len%2==0){
    for(int i=0;i<len;i++){
      if(array[(*(arr+i))-97]%2!=0){
	printf("%c",(array[(*(arr+i))-97]));
	flag = 1;
	break;
      }
    }
  }
  else{
    flag = 2;
    for(int i=0;i<len;i++){
      if(array[(*(arr+i))-97]%2!=0 && flag==2){
	printf("TEST\n");
	check[(*(arr+i))-97]=1;
	flag = 0;
      }
      else if(array[(*(arr+i))-97]%2!=0 && flag==0){
	if(check[(*(arr+i))-97]==0){
	  flag = 1;
	  break;   
	}
      }
    }
  }
  if (flag==0 || flag==2)
    printf("YES\n");
  else
    printf("NO\n");
    
  return;
}

int gemStone() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N,ipnum;
    scanf("%d",&N);
    ipnum = N;
    int array[26],count=0;
    for(int i=0;i<26;i++){
        array[i]=0;
    }
    char str[100];
    while(ipnum--){
        scanf("%s",str);
        char *a = str;
        while(*a!='\0'){
            int j=0;
            while(*(str+j)!='\0'){
                if(*a==*(str+j) && a!=(str+j)){
                    break;
                }  
                j++;
            }
            if(*(str+j)=='\0'){
                array[*a-97]++;
                //printf("%d",*a-97);
            }
            a=a+1;
        }
    }
    for(int i=0;i<26;i++){
        if(array[i]==N){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}

int main(){
  //reverse();
  //altChar();
  char arr[100001];
  scanf("%s",arr);
  findPalind(arr);
  return(0);
}
