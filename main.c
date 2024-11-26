#include <stdio.h>
int main() {
int num;
  printf("enter a number:");
  scanf("%d",&num);
  for(inti=1;i<=10;i++){
    printf("%x%d=%d\n",num,i,num*i);
  }
  return 0;
}
  