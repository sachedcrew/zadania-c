#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* read_input_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* content = (char*)malloc(length * sizeof(char));
    if (content == NULL) {
        printf("Błąd alokacji pamięci\n");
        exit(1);
    }

    fread(content, sizeof(char), length, file);
    fclose(file);
    return content;
}

int calculate_energy_sum(const char* input) {
    int sum = 0;
    int num1, num2;
    char *token, *str, *tofree;

    tofree = str = strdup(input);
    while ((token = strsep(&str, "\n")) != NULL) {
        num1 = token[0] - '0'; 
        num2 = token[strlen(token) - 1] - '0'; 
        sum += num1 * 10 + num2;
    }
    free(tofree);
    return sum;
}

int main() {
    char* input = read_input_file("input.txt");
    int energy_sum = calculate_energy_sum(input);
    printf("Suma wszystkich wartości energetycznych: %d\n", energy_sum);
    free(input);
    return 0;
}
