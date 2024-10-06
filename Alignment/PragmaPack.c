#include <stdio.h>

struct MyStruct {
    char a;
    int b;
    double c;
};

#pragma pack(1)
struct MyStructPacked {
    char a;
    int b;
    double c;
};

int main() {
    struct MyStruct s1;
    struct MyStructPacked s2;

    printf("Without #pragma pack:\n");
    printf("Size of struct MyStruct: %lu bytes\n", sizeof(s1));
    printf("Address of a: %p\n", &s1.a);
    printf("Address of b: %p\n", &s1.b);
    printf("Address of c: %p\n", &s1.c);

    printf("\nWith #pragma pack(1):\n");
    printf("Size of struct MyStructPacked: %lu bytes\n", sizeof(s2));
    printf("Address of a: %p\n", &s2.a);
    printf("Address of b: %p\n", &s2.b);
    printf("Address of c: %p\n", &s2.c);

    return 0;
}