#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int a[5000];
  for(int i=0; i< 5000; i++){
    a[i] = rand()%100;
  }

  printf("\nElements of the array::");
    for(int i=0;i<5000;i++){
     printf("\nElement number %d::%d",i+1,a[i]);
   }

  return 0;
}


