// 1에서 10까지 더하기 
#include <stdio.h>

void main() {
  int i, sum=0;

  for(i=1;i<10;i++) {
	  sum = sum + i;
  }
  printf("sum = %d \n",sum);
}
