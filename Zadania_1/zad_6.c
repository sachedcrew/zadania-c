#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

const char *choices[] = {"Kamień", "Papier", "Nożyce"};

void print_scores(int rounds, int scores[], int moves[][2]) {
    printf("Wyniki:\n");
    for (int i = 0; i < rounds; i++) {
        printf("Runda %d: Gracz - %s, Komputer - %s, Wynik: %s\n", i + 1, choices[moves[i][0]], choices[moves[i][1]], scores[i] == 0 ? "Remis" : (scores[i] == 1 ? "Wygrana" : "Przegrana"));
    }
}

int main() {
    int scores[100];
    int moves[100][2];
    int rounds = 0;
    char command[10];
    
    srand(time(NULL));
    
    while (1) {
        printf("Wybierz: Kamień (0), Papier (1), Nożyce (2), Wyjdź (3), Wyniki (4): ");
        int player_choice;
        scanf("%s", command);
        
        if (command[0] == '3') break;
        if (command[0] == '4') {
            print_scores(rounds, scores, moves);
            continue;
        }
        
        player_choice = atoi(command);
        int computer_choice = rand() % 3;
        
        moves[rounds][0] = player_choice;
        moves[rounds][1] = computer_choice;
        
        if (player_choice == computer_choice) {
            scores[rounds] = 0;
            printf("Remis! Obaj wybraliście %s.\n", choices[player_choice]);
        } else if ((player_choice == ROCK && computer_choice == SCISSORS) ||
                   (player_choice == PAPER && computer_choice == ROCK) ||
                   (player_choice == SCISSORS && computer_choice == PAPER)) {
            scores[rounds] = 1;
            printf("Wygrałeś! Wybrałeś %s, komputer wybrał %s.\n", choices[player_choice], choices[computer_choice]);
        } else {
            scores[rounds] = -1;
            printf("Przegrałeś! Wybrałeś %s, komputer wybrał %s.\n", choices[player_choice], choices[computer_choice]);
        }
        
        rounds++;
    }
    
    printf("Koniec gry!\n");
    return 0;
}
