#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

typedef struct wrong_line {
    char *line;
    int line_number;
    struct wrong_line *next;
} t_wrong_line;

typedef struct words {
    char *word;
    char *category;
    char *difficulty;
    struct words *next;
} t_words;

typedef struct game_status {
    t_words *word;
    char *hidden_word;
    int tries;
    int word_tries;
    char tried_letters[27];
    char *tried_words[4];
} t_game_status;

int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char *str);
char **split(char *src, char c);
void my_free_array(char **array);
char *my_itoa(int n);
int tab_len(char **tab);
t_words *create_word(char *word, char *category, char *difficulty);
void push_back_word(t_words *list, t_words *new);
t_words *file_to_list(int fd, char *difficulty, char *category, t_wrong_line **wrong_lines);
void my_free_list(t_words *list);
void my_print_list(t_words *list);
void game_launcher(t_words *list);
void print_game(t_game_status status, char hangman_art[6][7][8]);
void create_drawing(char hangman_art[6][7][8]);
t_wrong_line *create_wrong_line(char *line, int line_number);
void push_back_wrong_line(t_wrong_line *list, t_wrong_line *new);
void my_free_wrong_lines(t_wrong_line *list);
void my_print_wrong_lines(t_wrong_line *list);

#endif // HANGMAN_H
