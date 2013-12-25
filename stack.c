#include<stdio.h>
#include<stdlib.h>
struct stack {
  int maxsize;
  int top;
  int *val;
};
int is_empty(struct stack *s);
int is_full(struct stack *s);
void push(struct stack *s,int num)
{
  if(!is_full(s)) {
    s->top++;
    s->val[s->top]=num;
    printf("Pushed %d\n",num);
    return;
  }
  printf("Stack Full!!\n");
  return;
}
int pop(struct stack *s)
{
  if(is_empty(s)) {
    printf("Stack Empty!!\n");
    return -999;
  }
  printf("Popped %d\n",s->val[s->top]);
  s->top--;
  return s->val[s->top];
}
int is_empty(struct stack *s)
{
  return (s->top==-1);
}
int is_full(struct stack *s)
{
  int temp = s->top;
  return ((temp++)==(s->maxsize-1));
}
void * create(int size)
{
  struct stack *s= calloc(1,sizeof(struct stack));
  s->maxsize=size;
  s->top=-1;
  s->val = calloc(size,sizeof(int));
  return s;
}
int main()
{
  struct stack *mystack;
  mystack = (struct stack *)create(5);
  for(int i=0;i<10;i++) {
    push(mystack,i);
    printf("Top->%d\n",mystack->top);
  }
  for(int i=0;i<10;i++) {
    pop(mystack);
    printf("Top->%d\n",mystack->top);
  }
  return 0;
}
