#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};



void rem( struct node *loop_node,struct node *head )
{
 int i,k=1;
 struct node *ptr1,*ptr2;
 ptr1=ptr2=loop_node;
 
 while(ptr2->next!=ptr1)
 {
   ptr2=ptr2->next;
   k++;
 }

 ptr1=ptr2=head;
 for(i=0;i<k;++i)
     ptr2=ptr2->next;

 while(1)
 {
    if(ptr1==ptr2)
       break;
 }

 while(ptr2->next!=ptr1)
      ptr2=ptr2->next;

 ptr2->next=NULL;
}

 
 
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


int detect (struct node *head_ref)
{
  struct node *slow_ptr,*fast_ptr;
  slow_ptr=fast_ptr=head_ref;

  while(slow_ptr && fast_ptr && fast_ptr->next)
  {
    slow_ptr=slow_ptr->next;
    fast_ptr=fast_ptr->next->next;
   
    if(slow_ptr==fast_ptr)
    {
       
       rem(slow_ptr,head_ref);
       return 1;
    }
  }

  return 0;
}




void main()
{
 
 int flag;
 struct node *head=NULL;
  
 push(&head,1);
 push(&head,2);
 push(&head,3);
 push(&head,4);
 

 print(head);

 flag=detect(head);

 if(flag==0)
   printf("\n NOOOOO LOOeP!!!");
 else
  printf("\n LOOOOOOOOOOOP!!!!! ");

 head->next->next->next->next=head;

 flag=detect(head);
 if(flag==0)
   printf("\n NOOOOO loop!!!");
 else
  printf("\n LOOOOOOOOOOOP!!!!! ");

 flag=detect(head);
 if(flag==0)
   printf("\n NOOOOO LOOP!!!");
 else
  printf("\n LOOOOOOOOOOOP!!!!! ");


}
 

