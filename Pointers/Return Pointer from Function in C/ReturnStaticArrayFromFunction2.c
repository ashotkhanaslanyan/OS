#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *getRandom() {
   static int  r[10];
   srand((unsigned)time(NULL));
  
   for(int i = 0; i < 10; ++i){
      r[i] = rand();
   }
    
   return r;
}

int main(){

   int *p;
   p = getRandom();

   for(int i = 0; i < 10; i++) {
      printf("*(p + %d): %d\n", i, *(p + i));
   }

   return 0;
}