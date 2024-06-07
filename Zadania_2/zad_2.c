#include <stdio.h>

void doubleValue(float *value) {
    *value *= 2;
}

int main() {
    float number = 5.5;
    printf("Przed modyfikacją: %.2f\n", number);
    doubleValue(&number);
    printf("Po modyfikacji: %.2f\n", number);

    return 0;
}
