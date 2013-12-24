#include<stdio.h>
#include<stdlib.h>
struct node {
  int num;
  struct node *next;
}*head,*head1,*tail1,*head2,*tail2;
void insert(int a,int ref)
{
  struct node *item;
  item = calloc(1,sizeof(struct node));
  item->num=a;
  if(ref) {
    item->next=head1;
    if(tail1==NULL)
      tail1=item;
    head1=item;
  }
  else {
    item->next=head2;
    if(tail2==NULL)
      tail2=item;
    head2=item;
  }
}
int main()
{
  int a;
  head=NULL;
  struct node *item;
  for(int i=0;i<10;i++) {
    scanf("%d",&a);
    item = calloc(1,sizeof(struct node));
    item->num=a;
    item->next=head;
    head=item;
  }
  struct node *move;
  move=head;
  while(move!=NULL) {
    printf("%d ",move->num);
    move=move->next;
  }
  printf("\n");
  printf("Which element to partition around?: ");
  scanf("%d",&a);
  head1=NULL;
  head2=NULL;
  tail1=NULL;
  tail2=NULL;
  int count=0;
  move=head;
  while(move!=NULL) {
    if(move->num<a)
      insert(move->num,1);
    else if(move->num>a)
      insert(move->num,0);
    else
      count++;
    move=move->next;
  }
  while(count!=0) {
    insert(a,0);
    count--;
  }
  tail1->next=head2;
  move=head;
  while(move!=NULL) {
    struct node *t=move;
    move=move->next;
    free(t);
  }
  move=head1;
  while(move!=NULL) {
    printf("%d ",move->num);
    move=move->next;
  }
  printf("\n");
}

