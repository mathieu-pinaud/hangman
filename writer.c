#include "hangman.h"

void create_drawing(char hangman_art[6][7][8]) {
    // Étape 1
    strcpy(hangman_art[0][0], " _____");
    strcpy(hangman_art[0][1], " |   |");
    strcpy(hangman_art[0][2], "     |");
    strcpy(hangman_art[0][3], "     |");
    strcpy(hangman_art[0][4], "     |");
    strcpy(hangman_art[0][5], "     |");
    strcpy(hangman_art[0][6], "_____|");

    // Étape 2
    strcpy(hangman_art[1][0], " _____");
    strcpy(hangman_art[1][1], " |   |");
    strcpy(hangman_art[1][2], " 0   |");
    strcpy(hangman_art[1][3], "     |");
    strcpy(hangman_art[1][4], "     |");
    strcpy(hangman_art[1][5], "     |");
    strcpy(hangman_art[1][6], "_____|");

    // Étape 3
    strcpy(hangman_art[2][0], " _____");
    strcpy(hangman_art[2][1], " |   |");
    strcpy(hangman_art[2][2], " 0   |");
    strcpy(hangman_art[2][3], " |   |");
    strcpy(hangman_art[2][4], "     |");
    strcpy(hangman_art[2][5], "     |");
    strcpy(hangman_art[2][6], "_____|");

    // Étape 4
    strcpy(hangman_art[3][0], " _____");
    strcpy(hangman_art[3][1], " |   |");
    strcpy(hangman_art[3][2], " 0   |");
    strcpy(hangman_art[3][3], "/|   |");
    strcpy(hangman_art[3][4], "     |");
    strcpy(hangman_art[3][5], "     |");
    strcpy(hangman_art[3][6], "_____|");

    // Étape 5
    strcpy(hangman_art[4][0], " _____");
    strcpy(hangman_art[4][1], " |   |");
    strcpy(hangman_art[4][2], " 0   |");
    strcpy(hangman_art[4][3], "/|\\  |");
    strcpy(hangman_art[4][4], "     |");
    strcpy(hangman_art[4][5], "     |");
    strcpy(hangman_art[4][6], "_____|");

    // Étape 6
    strcpy(hangman_art[5][0], " _____");
    strcpy(hangman_art[5][1], " |   |");
    strcpy(hangman_art[5][2], " 0   |");
    strcpy(hangman_art[5][3], "/|\\  |");
    strcpy(hangman_art[5][4], "/ \\  |");
    strcpy(hangman_art[5][5], "     |");
    strcpy(hangman_art[5][6], "_____|");
}

void print_game(t_game_status status, char hangman_art[6][7][8]){
    int i = 0;
    clear();
    while (i <= 6) {
        printw("%s", hangman_art[6 - status.tries][i]);
        if (i == 1)
            printw("Category: %s", status.word->category);
        if (i == 2)
            printw("Letters tried: %s", status.tried_letters);
        if (i == 3)
            printw("Tried words: %s %s %s", status.tried_words[0] ? status.tried_words[0] : "", status.tried_words[1] ? status.tried_words[1] : "", status.tried_words[2] ? status.tried_words[2] : "");
        printw("\n");
        i += 1;
    }
    printw("Word: %s\n", status.hidden_word);
    refresh();
}