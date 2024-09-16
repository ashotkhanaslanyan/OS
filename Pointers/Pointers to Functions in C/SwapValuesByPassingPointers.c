#include <stdio.h>

int swap(int *x, int *y){
   int z;
   z = *x;   
   *x = *y; 
   *y = z; 
}

int main (){

   int a = 10;
   int b = 20;
   printf("Before swap, value of a: %d\n", a);
   printf("Before swap, value of b: %d\n", b);
   
   swap(&a, &b);
   printf("After swap, value of a: %d\n", a);
   printf("After swap, value of b: %d\n", b);

   return 0;
}