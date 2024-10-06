#include <stdio.h>

struct MyStruct {
    char a;
    int b;
    double c;
};

struct MyStructReordered {
    double c;
    int b;
    char a;
};

int main() {
    struct MyStruct s;
    struct MyStructReordered sReordered;

    printf("Size of original struct: %lu bytes\n", sizeof(s));
    printf("Size of reordered struct: %lu bytes\n", sizeof(sReordered));

    printf("Original struct addresses:\n");
    printf("Address of a: %p\n", &s.a);
    printf("Address of b: %p\n", &s.b);
    printf("Address of c: %p\n", &s.c);

    printf("Reordered struct addresses:\n");
    printf("Address of c: %p\n", &sReordered.c);
    printf("Address of b: %p\n", &sReordered.b);
    printf("Address of a: %p\n", &sReordered.a);

    return 0;
}