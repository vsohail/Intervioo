#include<stdio.h>
#include<string.h>
int main()
{
  char str[100];
  fgets(str,sizeof(str),stdin);
  unsigned int count=0;
  int i;
  for(i=0;i<strlen(str)-1;i++)
  {
    printf("%d\n",(int)str[i]-97);
    if((1 & count>>((int)str[i]-97))!=1) {
      count = 1<<((int)str[i]-97) | count;
    }
    else {
      printf("Not Unique\n");
      return 0;
    }
  }
  printf("Unique\n");
  return 0;
}
