#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char array[4];
}my_array;

my_array array = { .array = {1,1,1,1} };

void assign(my_array a)
{
  array.array[0] = a.array[0];
  array.array[1] = a.array[1];
  array.array[2] = a.array[2];
  array.array[3] = a.array[3]; 

  }

char num = 5;
char ber = 6;

int main(void)
{
  printf("%d\n", array.array[0]);
  printf("%d\n", array.array[1]);
  printf("%d\n", array.array[2]);
  printf("%d\n", array.array[3]);

  // this works even after initialisation
  assign((my_array){ .array = {num,ber,num,ber} });
   
  printf("%d\n", array.array[0]);
  printf("%d\n", array.array[1]);
  printf("%d\n", array.array[2]);
  printf("%d\n", array.array[3]);


  
#ifdef _WIN32
  system("pause");
#endif
  return 0;
}
