#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int

struct stack
{
  int top;
  unsigned size;
  int* arr;
};

struct stack* create(unsigned size)
{

 struct stack* s=(struct stack*)malloc(sizeof(struct stack));
 s->top=-1;
 s->size=size;
 s->arr=(int*)malloc(size*sizeof(int));

}

void push(struct stack* s, int c)
{
  if(s->top==s->size-1)
  {
    printf("\nOverflow!\n");
    return;
  }
  s->top++;
  s->arr[s->top]=c;

}

int pop(struct stack* s)
{
  if(s->top==-1)
  {
    printf("\nUnderflow!\n");
    return;
  }

 int r=s->arr[s->top];
 s->top--;
 return r;
}

bool isempty(struct stack* s)
{
 if(s->top==-1)
   return 1;
 else 
  return 0;
}

void print(struct stack* s)
{
 int i;
 for(i=(s->top);i>=0;--i)
   printf("\n %d ",s->arr[i]);
}

void main()
{

 struct stack *s,*aux;
 s=create(100);
 aux=create(100);
 int ch,con,val,rem;
 do
 {
  printf("\n MENU- \n1.Push \n2.Pop \n3.Get minimium \n4.Print stack \n5.Print auxillary stack \n Enter your choice ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1 : 
             printf("\n Enter value to be pushed ");
             scanf("%d",&val); 
             if(val<=(aux->arr[aux->top]) )
               push(aux,val);
             else if(isempty(aux))
               push(aux,val);
             push(s,val);
             break;

   case 2 : rem=pop(s);
            if(rem==aux->arr[aux->top])
              pop(aux);
            break;

  case 3 : printf("\n Minimium element is %d ",aux->arr[aux->top]);
           break;

  case 4 : print(s); break;
  
  case 5 : print(aux); break;
  }
  printf("\n Press 1 to continue ");
  scanf("%d",&con);

 }while(con==1);

}

























            


 


