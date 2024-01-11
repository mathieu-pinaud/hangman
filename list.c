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

t_wrong_line *create_wrong_line(char *line, int line_number) {
    t_wrong_line *new = malloc(sizeof(t_wrong_line));
    new->line = my_strdup(line);
    new->line_number = line_number;
    new->next = NULL;
    return (new);
}

void push_back_wrong_line(t_wrong_line *list, t_wrong_line *new) {
    t_wrong_line *tmp = list;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
}

void my_free_wrong_lines(t_wrong_line *list) {
    t_wrong_line *tmp = list;
    while (tmp != NULL) {
        t_wrong_line *next = tmp->next;
        free(tmp->line);
        free(tmp);
        tmp = next;
    }
}

void my_print_wrong_lines(t_wrong_line *list) {
    t_wrong_line *tmp = list;
    while (tmp != NULL) {
        write(1, "Error on line ", 14);
        char *line_nb = my_itoa(tmp->line_number + 1);
        write(1, line_nb, my_strlen(line_nb));
        write(1, " : \"", 4);
        write(1, tmp->line, my_strlen(tmp->line));
        write(1, "\"\n", 2);
        free(line_nb);
        tmp = tmp->next;
    }
}