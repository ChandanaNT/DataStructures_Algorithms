#include<stdio.h>
#include<stdlib.h>

struct node 
{
 int data;
 struct node* next;
};

void push(struct node** head_ref,int val)
{
 struct node *new_node;
 new_node=(struct node*)malloc(sizeof(struct node));
 new_node->data=val;
 new_node->next=NULL;

 if(*head_ref==NULL)
    *head_ref=new_node;
 else
 {
   new_node->next=*head_ref;
   *head_ref=new_node;
 }
}

void print(struct node *head)
{
  if(head==NULL)
     return;
  else
  {
    while(head!=NULL)
    {
      printf(" %d --> ",head->data);
      head=head->next;
    }
  }
}
  
struct node* rev(struct node *head,int k)
{
  int ct=0;
  struct node *prev,*curr,*next;
  prev=NULL;
  curr=head;

  while(curr!=NULL && ct<k)
  {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    ct++;
  }

  if(next!=NULL)
    head->next=rev(next,k);

  return prev;
}

void main()
{
 int k;
 struct node *head=NULL;

 printf("\n Enter a value for k  ");
 scanf("%d",&k);

 push(&head,1);
 push(&head,2);
 push(&head,3);
 push(&head,4);
 push(&head,5);
 push(&head,6);
 push(&head,7);

 printf("\n List before reversal ");
 print(head);
 head=rev(head,k);
 printf("\n List after reversal ");
 print(head);

}
 
