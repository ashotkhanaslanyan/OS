#include <stdio.h>

int main() {

  int x = 10;
  int * ptr = & x;

  printf("Value of x = %d\n", * ptr);

  * ptr = 20;

  printf("Value of x = %d\n", * ptr);

  return 0;
}