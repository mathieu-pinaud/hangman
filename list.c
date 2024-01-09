#include "hangman.h"

t_words *create_word(char *word, char *category, char *difficulty) {
    t_words *new = malloc(sizeof(t_words));
    new->word = my_strdup(word);
    new->category = my_strdup(category);
    new->difficulty = my_strdup(difficulty);
    new->next = NULL;
    return (new);
}

void push_back_word(t_words *list, t_words *new) {
    t_words *tmp = list;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}

void my_free_list(t_words *list) {
    t_words *tmp = list;
    while (tmp != NULL) {
        t_words *next = tmp->next;
        free(tmp->word);
        free(tmp->category);
        free(tmp->difficulty);
        free(tmp);
        tmp = next;
    }
}

void my_print_list(t_words *list) {
    t_words *tmp = list;
    while (tmp != NULL) {
        printf("%s, %s, %s\n", tmp->word, tmp->category, tmp->difficulty);
        tmp = tmp->next;
    }
}