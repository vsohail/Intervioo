#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
  char x[100]="Hello from home!              ";
  printf("%s\n",x);
  int len=16;
  int newlen=len;
  for(int i=0;i<len;i++) {
    if(*(x+i)==' ')
      newlen+=2;
  }
  *(x+newlen)='\0';
  for(char *j=x,i=len-1;i!=newlen-1;i--) {
    if(*(j+i)==' ') {
      *(j+newlen-1)='0';
      newlen--;
      *(j+newlen-1)='2';
      newlen--;
      *(j+newlen-1)='%';
      newlen--;
    }
    else {
      *(j+newlen-1)=*(j+i);
      newlen--;
    }
  }
  printf("%s\n",x);
  return 0;
}
