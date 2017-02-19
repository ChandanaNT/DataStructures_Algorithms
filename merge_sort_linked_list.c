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

void split(struct node *source,struct node **front,struct node **back)
{
  
  if(source==NULL || source->next==NULL)
  {
    *front=source;
    *back=NULL;
  }
  else
  {
    struct node *slow,*fast;
    slow=source;
    fast=source->next;

    while(fast->next!=NULL)
    {
       slow=slow->next;
       fast=fast->next->next;
    }

    *back=slow->next;
    *front=source;
    slow->next=NULL;
  }
}

struct node* merge(struct node *a,struct node *b)
{
  struct node* res=NULL;

  
  if(a==NULL)
    return b;
 else if(b==NULL)
    return a;
 else if(a->data >= b->data)
 {
    res=b;
    res->next=merge(a,b->next);
 }
 else
 {
    res=a;
    res->next=merge(a->next,b);
    
 }

 return res;
}
  


void sort(struct node **head_ref)
{
 if(*head_ref==NULL || (*head_ref)->next==NULL)
    return;

 struct node *a,*b;
 split(*head_ref,&a,&b);
 sort(&a);
 sort(&b);
 
 *head_ref=merge(a,b);
}
   
   
void main()
{

 struct node *head=NULL;
 struct node *new_head=NULL;

 //push(&head,2);
 push(&head,5);
 push(&head,9);
 push(&head,6);
 push(&head,1);
 push(&head,8);
 

 printf("\n List before sorting \n ");
 print(head);
 sort(&head);
 printf("\n List after sorting \n ");
 print(head);

}

