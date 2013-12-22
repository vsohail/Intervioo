#include<stdio.h>
#include<string.h>
int main(int argc,char * argv[])
{
  char *start = argv[1];
  char *end = argv[1]+strlen(argv[1])-1;
  char temp;
  for(;end!=start;end--,start++) {
    temp = *start;
    *start = *end;
    *end = temp;
  }
  printf("%s\n",argv[1]);
  return 0;
}
