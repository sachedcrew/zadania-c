#include <stdio.h>

int sum_multiples(int limit) {
    if (limit < 0) return 0;
    int sum = 0;
    for (int i = 1; i < limit; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int number;
    printf("Podaj liczbę: ");
    scanf("%d", &number);
    
    int result = sum_multiples(number);
    printf("Suma wielokrotności 3 lub 5 poniżej %d to: %d\n", number, result);
    
    return 0;
}
