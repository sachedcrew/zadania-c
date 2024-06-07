#include <stdio.h>

int main() {
    char name[50];
    printf("Podaj swoje imię: ");
    scanf("%49s", name);
    printf("Witaj, %s!\n", name);
    return 0;
}
