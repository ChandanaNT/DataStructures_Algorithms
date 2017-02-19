#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void main()
{

 char str[20];
 printf("\n Enter a string ");
 scanf("%s",str);
 int i,n;
 n=strlen(str);
 struct stack* s;

 s=create(n);

 for(i=0;i<n;++i)
    push(s,str[i]);

 for(i=0;i<n;++i)
    str[i]=pop(s);

 printf("\n The reversed string is %s \n ",str);

}
