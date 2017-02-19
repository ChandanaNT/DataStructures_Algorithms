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

struct node* mid(struct node *head)
{

 struct node *slow,*fast;
 slow=fast=head;

 while(fast!=NULL && fast->next!=NULL)
 {
   slow=slow->next;
   fast=fast->next->next;
 }

 return slow;
}

void main()
{
  struct node *head=NULL,*mid_node;
 
 push(&head,5);
 push(&head,4);
 push(&head,3);
 push(&head,2);
 push(&head,1);

 print(head);
 mid_node =mid(head);
 printf("\n Middle node is %d \n ",mid_node->data);

}
