#include <stdio.h>

int main() {
    float grades[2][5] = {
        {4.5, 3.7, 5.0, 4.2, 4.0}, 
        {3.5, 4.0, 3.8, 4.5, 4.2}  
    };
    
    float math_sum = 0.0, physics_sum = 0.0;
    for (int i = 0; i < 5; i++) {
        math_sum += grades[0][i];
        physics_sum += grades[1][i];
    }
    
    float math_avg = math_sum / 5;
    float physics_avg = physics_sum / 5;
    
    printf("Średnia ocen z matematyki: %.2f\n", math_avg);
    printf("Średnia ocen z fizyki: %.2f\n", physics_avg);
    
    return 0;
}

