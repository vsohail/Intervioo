#include<stdio.h>
#include<stdlib.h>
struct node {
  int num;
  struct node *next;
}*head,*move,*move2;
void insert(int a)
{
  struct node *item;
  item = (struct node *)calloc(1,sizeof(struct node));
  item->num=a;
  item->next=head;
  head=item;
}
void delete(struct node *del)
{
  struct node *prev,*cur;
  prev=head;cur=head;
  int takeoff=0;
  if(cur==del) {
    head=cur->next;
    free(cur);
    return;
  }
  cur=head->next;
  while(cur!=del) {
    cur=cur->next;
    prev=prev->next;
  }
  prev->next=cur->next;
  free(cur);
}
int main()
{
  int a;
  head=NULL;
  for(int i=0 ; i<10 ; i++) {
    scanf("%d",&a);
    insert(a);
  }
  move=head;
  while(move!=NULL) {
    printf("%d ",move->num);
    move=move->next;
  }
  move=head;
  move2=head;
  int count=0;
  printf("\n");
  while(move!=NULL) {
    while(move2!=NULL) {
      if(move2->num==move->num) {
        count++;
        if(count>1) {
          struct node *temp = move2->next;
          delete(move2);
          move2=temp;
          continue;
        }
      }
      move2=move2->next;
    }
    move2=head;
    move=move->next;
    count=0;
  }
  printf("\n");
  move=head;
  while(move!=NULL) {
    printf("%d ",move->num);
    move=move->next;
  }
  printf("\n");
  return 0;
}
