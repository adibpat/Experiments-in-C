#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STKSZ 100

typedef struct node{
  int data;
  struct node *left;
  struct node *right;
  int ht;
}node;

int size(node *root){
  if(root == NULL){
    return(0);
  }
  return(1+size(root->left)+size(root->right));
}

int maxdepth(node *root){
  if(root==NULL){
    return(0);
  }
  int a = maxDepth(root->left);
  int b = maxDepth(root->right);
  int max = a>b?a:b;
  return(1+max);
}

int minValue(node *root){
  assert(root!=NULL);
  node *current = root;
  while(current->left!=NULL){
    current=current->left;
  }
  return current->data;
}

int hasPathSum(node *root,int sum){
  if(root==NULL){
    return;
  }
  sum = sum - root->data;
  if(sum==0 && root->left==NULL && root->right==NULL){
    return(1);
  }
  return (hasPathSum(root->left) || hasPathSum(root->right));
}

int array[STKSZ];
int index = -1;

void push(int data){
  if(index<(STKSZ-1)){
    index++;
    array[index]=data;
  }
  return;
}

int pop(){
  if(index>-1){
    int temp = array[index];
    index--;
    return(temp);
  }
}


/* To Do: 
void printPaths(node *root){
  if(root==NULL){
    // Decide what to do
  }
  push(root->data);
  printPaths(root->left);
  pop();
  printPaths(root->right);

/* To Do: This function is not yet complete
node *selfBalance(node *root , int value){
  if(root==NULL){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->ht=0;
    return newNode;
  }
  else if(root->data>=value){
    root->ht++;
    node *temp = root->left;
    root->left = selfBalance(root->left,value);
  }
  else{
    root->ht--;
    node *temp = root->right;
    root->right = selfBalance(root->right,value);
  }
}
*/

int isBST(node *root){
  if(root=NULL){
    return(1);
  }
  if(root->left!=NULL && minValue(root->left)>root->data){
    return(0);
  }
  if(root->right!=NULL && minValue(root->right)<=root->data){
    return(0);
  }
  int a = isBST(root->left);
  int b = isBST(root->right);
  if(!a*b){
    return(0);
  }
  return(1);
}
  

int main(){
  
  return(0);
}
