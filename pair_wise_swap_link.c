#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};

void push(struct node **head_ref , int val)
{
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data=val;
  new_node->next=NULL;

  if(*head_ref==NULL)
    *head_ref = new_node;
  else
  {
    new_node->next=*head_ref;
    *head_ref = new_node;
  }
}


void print(struct node *head_ref)
{
  while(head_ref!=NULL)
  {
      printf(" %d --> ",head_ref->data);
      head_ref=head_ref->next; 
   }
}

void swap(struct node **head_ref)
{
 struct node *prev,*curr;

 if(*head_ref==NULL || (*head_ref)->next==NULL)
    return ;

 prev=*head_ref;
 curr=(*head_ref)->next;
 
 *head_ref=curr;
  
 while(1)
 {
   struct node *next=curr->next;
   curr->next=prev;
   
   if(next==NULL || next->next ==NULL)
   {
      prev->next=next;
      break;
   }
   
   prev->next=next->next;
   prev=next;
   curr=prev->next;
}

 
}


void main()
{

   struct node *head=NULL;
  
  push(&head,4);
  push(&head,3);
  push(&head,2);
  push(&head,1);

  printf("\n Linked list before swap - \n");
  print(head);
  swap(&head);
  printf("\n Linked list after swap - \n");
  print(head);
}
