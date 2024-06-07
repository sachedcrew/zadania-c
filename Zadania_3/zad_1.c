#include <stdio.h>

int binomial_coefficient(int n, int k) {
    int res = 1;
    if (k > n - k) {
        k = n - k;
    }
    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void print_pascals_triangle(int N) {
    for (int line = 0; line < N; line++) {
        for (int i = 0; i <= line; i++) {
            printf("%d ", binomial_coefficient(line, i));
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Podaj wysokość trójkąta Pascala: ");
    scanf("%d", &N);
    print_pascals_triangle(N);
    return 0;
}
