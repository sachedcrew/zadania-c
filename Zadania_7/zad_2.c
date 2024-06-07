#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_GAMES 100

struct Game {
    int id;
    int red;
    int green;
    int blue;
};

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

int possible_games(const char* input) {
    int red_total = 0, green_total = 0, blue_total = 0;
    struct Game games[MAX_GAMES];
    char *token, *str, *tofree;
    int num1, num2, count = 0;

    tofree = str = strdup(input);
    while ((token = strsep(&str, "\n")) != NULL) {
        int i = 0;
        games[count].id = atoi(strtok(token, " "));
        while(i++ < 3) {
            char* part = strtok(NULL, " ");
            if (part == NULL)
                break;
            if (isdigit(part[0])) {
                if (i == 1)
                    games[count].red = atoi(part);
                else if (i == 2)
                    games[count].green = atoi(part);
                else if (i == 3)
                    games[count].blue = atoi(part);
            }
        }
        count++;
    }
    free(tofree);

    int i;
    for (i = 0; i < count; i++) {
        red_total += games[i].red;
        green_total += games[i].green;
        blue_total += games[i].blue;
    }

    int sum = 0;
    int min_red = red_total, min_green = green_total, min_blue = blue_total;

    for (i = 0; i < count; i++) {
        int power = games[i].red * games[i].green * games[i].blue;
        if (games[i].red <= min_red && games[i].green <= min_green && games[i].blue <= min_blue) {
            min_red = games[i].red;
            min_green = games[i].green;
            min_blue = games[i].blue;
            sum += power;
        }
    }
    return sum;
}

int main() {
    char* input = read_input_file("input.txt");
    int result = possible_games(input);
    printf("Suma identyfikatorów możliwych gier: %d\n", result);
    free(input);
    return 0;
}
