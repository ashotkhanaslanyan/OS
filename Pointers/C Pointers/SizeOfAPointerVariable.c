#include <stdio.h>

int main() {

  int x = 10;
  float y = 1.3f;
  char z = 'p';

  int * ptr_x = & x;
  float * ptr_y = & y;
  char * ptr_z = & z;

  printf("Size of integer pointer : %lu\n", sizeof(ptr_x));
  printf("Size of float pointer : %lu\n", sizeof(ptr_y));
  printf("Size of char pointer : %lu\n", sizeof(ptr_z));
  
  return 0;
}