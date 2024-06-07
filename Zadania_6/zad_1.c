#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    data.i = 42;
    printf("Przechowywana wartość int: %d\n", data.i);

    data.f = 3.14;
    printf("Przechowywana wartość float: %f\n", data.f);

    data.c = 'A';
    printf("Przechowywana wartość char: %c\n", data.c);

    return 0;
}
