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

void rev(struct node **head_ref)
{
 
 struct node *prev=NULL,*curr=*head_ref,*next;
  
 if(*head_ref==NULL || (*head_ref)->next==NULL)
    return;

 while(curr!=NULL)
 {
   next=curr->next;
   curr->next=prev;
   prev=curr;
   curr=next;
 }

 *head_ref=prev;
}
  
 


void main()
{
  struct node *head=NULL;
  
 push(&head,4);
 push(&head,3);
 push(&head,2);
 push(&head,1);

 printf("\n List before reversal \n");
 print(head);
 rev(&head);
 printf("\n List after reversal \n");
 print(head);

}
