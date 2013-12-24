#include<stdio.h>
#include<stdlib.h>
struct node {
  int item;
  struct node *next;
}*head,*trail;
int main()
{
  struct node *elem;
  head=NULL;
  for(int i=0;i<10;i++) {
    elem = calloc(1,sizeof(struct node));
    int a;
    scanf("%d",&a);
    elem->item = a;
    elem->next = head;
    head = elem;
  }
  int a;
  printf("Kth to Last:");
  scanf("%d",&a);
  trail=head;
  for(int i=0;i<a;i++)
    trail=trail->next;
  while(trail->next!=NULL) {
    trail=trail->next;
    head=head->next;
  }
  printf("%d\n",head->item);
  return 0;
}
