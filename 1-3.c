#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
  int *count;
  count = calloc(256,sizeof(int));
  for(char *str1=argv[1];*str1!='\0';str1++) {
    count[(int)*str1]++;
  }
  for(char *str2=argv[2];*str2!='\0';str2++) {
    count[(int)*str2]--;
    if(count[(int)*str2]<0) {
      printf("Not a Permutation\n");
      return 0;
    }
  }
  for(int i=0;i<256;i++) {
    if(count[i]!=0) {
      printf("Not a Permutation\n");
      return 0;
    }
  }
  printf("Permutation\n");
}
