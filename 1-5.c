#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int len(int);
int main(int argc,char *argv[])
{
  char *clone;
  clone = calloc(strlen(argv[1]),sizeof(char));
  int count=1;
  int newlen=0;
  for(char *i=argv[1];*i!='\0';i++) {
    if(*i==*(i+1)) {
      count++;
    }
    else {
      newlen+=(len(count)+1);
      if(newlen>strlen(argv[1])) {
        printf("%s\n",argv[1]);
        return 0;
      }
      else {
        sprintf(clone,"%s%c%d",clone,*i,count);
        count=1;
      }
    }
  }
  printf("%s\n",clone);
  return 0;
}
int len(int num)
{
  int count=0;
  while(num!=0) {
    num/=10;
    count++;
  }
  return count;
}
