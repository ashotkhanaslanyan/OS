#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char title[50];
  float price;
} Book;

const int MAX = 3;
int main() {
  Book *book[MAX];

  for (int i = 0; i < MAX; i++) {
    book[i] = malloc(sizeof(Book));
    snprintf(book[i]->title, 50, "Book %d", i + 1);
    book[i]->price = 100 + i;
  }

  for (int i = 0; i < MAX; i++) {
    printf("Title: %s, Price: %.2f\n", book[i]->title, book[i]->price);
  }

  for (int i = 0; i < MAX; i++) {
    free(book[i]);
  }

  return 0;
}