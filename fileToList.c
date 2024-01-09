#include "hangman.h"

int tab_len(char **tab)
{
    int i = 0;
    while (tab[i] != NULL)
        i += 1;
    return (i);
}

t_words *file_to_list(int fd, char *difficulty, char *category){
    t_words *list = NULL;
    int i = 0;
    char buffer[4096];
    int size = read(fd, buffer, 4096);

    if (size == -1)
        return (NULL);
    buffer[size] = '\0';
    char **lines = split(buffer, '\n');
    while (lines[i] != NULL)
    {
        if (lines[i][0] == '#') {
            i += 1;
            continue;
        }
        char **wordParams = split(lines[i], ',');
        if (tab_len(wordParams) != 3) {
            write(1, "Error on line ", 14);
            char *tmp = my_itoa(i + 1);
            write(1, tmp, my_strlen(tmp));
            write(1, " : \"", 4);
            write(1, lines[i], my_strlen(lines[i]));
            write(1, "\"\n", 2);
            free(tmp);
        }
        else if(my_strcmp(wordParams[2], "facile") != 0 && my_strcmp(wordParams[2], "moyen") != 0 && my_strcmp(wordParams[2], "difficile") != 0) {
            write(1, "Error on line ", 14);
            char *tmp = my_itoa(i + 1);
            write(1, tmp, my_strlen(tmp));
            write(1, " : \"", 4);
            write(1, lines[i], my_strlen(lines[i]));
            write(1, "\"\n", 2);
            free(tmp);
        } else if (my_strcmp(difficulty, wordParams[2]) == 0) {
            if (category == NULL) {
                t_words *newWord = create_word(wordParams[0], wordParams[1], wordParams[2]);
                if (list == NULL)
                    list = newWord;
                else
                    push_back_word(list, newWord);
            }
            else if (strcmp(category, wordParams[1]) == 0) {
                t_words *newWord = create_word(wordParams[0], wordParams[1], wordParams[2]);
                if (list == NULL)
                    list = newWord;
                else
                    push_back_word(list, newWord);
            }
        }
        my_free_array(wordParams);
        i += 1;
    }
    my_free_array(lines);
    return (list);
}