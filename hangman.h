#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>

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
t_words *file_to_list(int fd, char *difficulty, char *category);
void my_free_list(t_words *list);
void my_print_list(t_words *list);
void game_launcher(t_words *list, char *difficulty, char *category);


#endif // HANGMAN_H
