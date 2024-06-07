#include <stdio.h>

int main() {
    int num = 10;  
    int *ptr = &num; 

    *ptr = 20;

    printf("Wartość zmiennej bezpośrednio: %d\n", num);
    printf("Wartość zmiennej przez wskaźnik: %d\n", *ptr);

    return 0;
}
