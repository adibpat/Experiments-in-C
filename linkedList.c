#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
  int data;
  struct node *next;
}node;

/* This function puts a new node at the start of the list */
void push(node**headRef,int data){
  
    struct node * newNode = (struct node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

/* This function counts the number of times an integer occurs in the LL */
int count(node *head, int num){
  int count = 0;
  while(head!=NULL){
    if(head->data == num){
      count++;
    }
    head=head->next;
  }
  return(count);
}

/* This function deletes the LL and sets the head pointer to null*/
void deleteList(node **headRef){
  node *current = *headRef;
  while(current!=NULL){
    current = current->next; // smart use of this line
    free(*headRef);
    *headRef = current;
  }
}

/* This function deletes the node at the start of the list and return the value in the node */
int pop(node **headRef){
  assert(*headRef != NULL);
  int data = (*headRef)->data;
  node *current = *headRef;
  *headRef = (*headRef)->next;
  free(current);
  return(data);
}

/* Inserts a new node with provided data at Nth position : 1st node is at position zero */
void insertNth(node **headRef, int pos, int data){
  node *current = *headRef;
  if(pos == 0){
    push(headRef,data);
  }
  while(pos>=1){
    assert(current!=NULL);
    current = current ->next; 
    pos--;
  }

  assert(current!=NULL); // very important to check if the position exists //

  push(&current->next,data);
}

/* This function inserts a node at the right place in a sorted list */
void sortedInsert(node **headRef, node *newNode){
  if(*headRef==NULL || ((*headRef)->data) > newNode->data){
    newNode->next = *headRef;
    *headRef = newNode;
  }
  node *current = *headRef;
  while(current->next!=NULL && current->next->data < newNode->data){
    // Traverse the list to find a larger value 
    current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode;
}

void insertSort(node **headRef){
  if(*headRef == NULL){
    return;
  }
  node *current = *headRef;

  /* This is how it should "NOT" be done
   while(current!=NULL){
   sortedInsert(headRef,current);
   current = current->next;
   }
  */

  node *currNext = NULL, *result = NULL;

  while(current!=NULL){
    currNext = current->next;
    sortedInsert(&result,current); /* This is very smart way of using pointers if the sortedInsert  function is looked at */
    current = currNext;
  }
  /* The above method provides a NULL pointer as a reference to head. The sortedInsert function always return a pointer to the head of the sorted linked list. So a 
sorted linked list is created using a temp headRef called as the result*/

  *headRef = result;
}

/* This function appends a LL at the end of other LL */
void append(node **aRef, node **bRef){
  if(*aRef == NULL){
    *aRef = *bRef;
  }
  else{
    node *current = *aRef;
    while(current->next != NULL){
      current = current ->next;
    }
    current ->next = *bRef;
  }
  *bRef = NULL;
}

/* This function splits the LL in two balanced halves */
void frontBackSplit(node *source, node **frontRef, node **backRef){
  node *slow, *fast;
  if(source==NULL || source->next==NULL){
    *frontRef = source;
    *backRef = NULL;
  }
  else{
    slow = source; fast = source->next;
    while(fast!=NULL){
      fast = fast->next;
      if(fast!=NULL){
	slow = slow->next;
	fast = fast->next;
      }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}

/* This function removes duplicates from a LL */
void removeDuplicates(node *head){
  node *current = head, *currNext=NULL;
  assert(current!=NULL);
  /* currNext = current->next; This line can be avoided */
  //currNext = NULL;
  while(/*currNext!=NULL*/ current->next!=NULL){
    currNext = current->next;
    if(current->data == currNext->data){
      current->next = currNext->next;
      free(currNext);
      /*currNext = current->Next;*/
    }
    else{
      /*current = currNext;*/
      /*currNext = currNext->next;*/
      current = current->next;
    }
  }
}

/* This function just moves the first node from one list to the other list */
void moveNode(node **src, node **dest){
  assert((*src)!=NULL);
  node *current = *src;
  *src = (*src)->next;
  current->next = *dest;
  *dest = current;
}

void alternatingSplit(node *source, node **aRef, node **bRef){

  

  node *a = NULL, *b = NULL; /* This should not be done because aRef and bRef may be lastRef of two linkedLists : *aRef = NULL, *bRef = NULL is wrong */
  node *current = source;
  while(current!=NULL){
    moveNode(&current,&a);
    if(current!=NULL){
      moveNode(&current,&b);
    }
  }
  *aRef = a;
  *bRef = b;
}

node *sortedMerge(node *a, node *b){
  node *result = NULL;
  node **lastRef = &result;
  /* In the first iterartion, the value of result is filled with the address of smaller of nodes of the linked list */
  while(1){
    if(a==NULL){
      *lastRef = b;
      break;
    }
    else if(b==NULL){
      *lastRef = a;
      break;
    }
    else if(a->data < b->data){
      moveNode(&a,lastRef);
    }
    else{
      moveNode(&b,lastRef);
    }
    lastRef = &((*lastRef)->next); /* here the last pointer is now advanced to the next field of the next node */
  }
  return(result);
}

void mergeSort(node **headRef){
  node *head = *headRef;
  node *frontRef = NULL, *backRef = NULL;
  if(*headRef == NULL || (*headRef)->next == NULL){
    return;
  }
  frontBackSplit(head,&frontRef,&backRef);
  mergeSort(&frontRef);
  mergeSort(&backRef);

  *headRef = sortedMerge(frontRef,backRef);
}

void recursiveReverse(node **headRef){
  node *first, *rest;
  if(*headRef==NULL){
    return;
  }
  first = *headRef;
  rest = first->next;
  if(rest==NULL){
    return;
  }
  recursiveReverse(&rest);
  (first->next)->next = first;
  first->next = NULL;
  *headRef = rest;
}

void evenOddReverse(node *head){
  if(head==NULL || head->next==NULL){
      return;
    }
  node *even=head, *odd=NULL, *rest=even->next->next;
  
  while(1){
    if(even->next==NULL){
      break;
    }
    rest=even->next->next;
    even->next->next=odd;
    odd = even->next;
    if(rest==NULL){
      even->next = odd;
      return;
    }
    even->next = rest;
    even = rest;
  }
  even->next=odd;
}
  
  

int main(){
  
  



  
  return(0);
}
