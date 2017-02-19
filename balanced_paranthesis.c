#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int

struct stack
{
  int top;
  unsigned size;
  char* arr;
};

struct stack* create(unsigned size)
{

 struct stack* s=(struct stack*)malloc(sizeof(struct stack));
 s->top=-1;
 s->size=size;
 s->arr=(char*)malloc(size*sizeof(char));

}

void push(struct stack* s,char c)
{
  if(s->top==s->size-1)
  {
    printf("\nOverflow!\n");
    return;
  }
  s->top++;
  s->arr[s->top]=c;
}

char pop(struct stack* s)
{
  if(s->top==-1)
  {
    printf("\nUnderflow!\n");
    return;
  }

 char r=s->arr[s->top];
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

void main()
{

 char str[20],r;
 printf("\n Enter a string ");
 scanf("%s",str);
 int i,n,flag=1;
 n=strlen(str);
 struct stack* s;

 s=create(n);

 for(i=0;i<n;++i)
 {
   if(str[i]=='(' || str[i]=='[' || str[i]=='{')
     push(s,str[i]);
  else if(str[i]==')')
  {
    r=pop(s);
    if(r!='(')
     flag=0;
  } 
   else if(str[i]=='}')
  {
    r=pop(s);
    if(r!='{')
     flag=0;
  } 
  else if(str[i]==']')
  {
    r=pop(s);
    if(r!='[')
     flag=0;
  } 
 }

 if(isempty(s) && flag)
   printf("\n Balanced expression ");
 else
   printf("\n It's not a balanced expression ");

}

 


