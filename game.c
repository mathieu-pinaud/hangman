#include "hangman.h"

char *create_hidden_word(t_game_status status) {
    char *hidden_word = malloc(sizeof(char) * (my_strlen(status.word->word) + 1));
    int i = 1;
    hidden_word[0] = status.word->word[0];
    while (status.word->word[i + 1] != '\0') {
        if(status.word->word[i] == status.word->word[0] || status.word->word[i] == status.word->word[my_strlen(status.word->word) - 1])
            hidden_word[i] = status.word->word[i];
        else
            hidden_word[i] = '*';
        i += 1;
    }
    hidden_word[i] = status.word->word[i];
    hidden_word[i + 1] = '\0';
    return hidden_word;
}

bool is_in_word(char input, char *word) {
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] == input)
            return true;
        i += 1;
    }
    return false;
}

void update_hidden_word(char input, char *hidden_word, char *word) {
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] == input)
            hidden_word[i] = input;
        i += 1;
    }
}

int game(t_words *word) {
    t_game_status status = {word, NULL, 6, 3, {0}, {NULL, NULL, NULL}};
    status.tried_letters[0] = status.word->word[0];
    status.tried_letters[1] = status.word->word[my_strlen(status.word->word) - 1];
    status.tried_letters[2] = '\0';
    status.hidden_word = create_hidden_word(status);
    char *input = NULL;
    size_t len = 0;

    while(status.tries > 0 && status.word_tries > 0) {
        printf("Word: %s\n", status.hidden_word);
        printf("Tried letters: %s\n", status.tried_letters);
        getline(&input, &len, stdin);
        if (my_strlen(input) == 2) {
            if (is_in_word(input[0], status.word->word)) {
                update_hidden_word(input[0], status.hidden_word, status.word->word);
                if (my_strcmp(status.hidden_word, status.word->word) == 0) {
                    free(input);
                    free(status.hidden_word);
                    input = NULL;
                    return(0);
                }
            }
            else if (!is_in_word(input[0], status.word->word) && !is_in_word(input[0], status.tried_letters))       
                status.tries -= 1;
            if (!is_in_word(input[0], status.tried_letters)) {
                int len = my_strlen(status.tried_letters);
                status.tried_letters[len] = input[0];
                status.tried_letters[len + 1] = '\0';
            }
        }
        else if (my_strlen(input) > 2) {
            bool is_in_tried_words = false;
            for (int i = 0; i < 3; i++) {
                if (status.tried_words[i] != NULL && my_strcmp(input, status.tried_words[i]) == 0)
                    is_in_tried_words = true;
            }
            if (my_strcmp(input, status.word->word) == 0) {
                free(input);
                free(status.hidden_word);
                for (int i = 0; i < 3; i++) {
                    if (status.tried_words[i] != NULL)
                        free(status.tried_words[i]);
                }
                input = NULL;
                return(0);
            }
            else if (!is_in_tried_words) {
                status.word_tries -= 1;
                for (int i = 0; i < 3; i++) {
                    if (status.tried_words[i] == NULL) {
                        status.tried_words[i] = my_strdup(input);
                        break;
                    }
                }
            }
        }
        free(input);
        input = NULL;
    }
    for (int i = 0; i < 3; i++) {
        if (status.tried_words[i] != NULL)
            free(status.tried_words[i]);
    }
    free(status.hidden_word);
    return(1);
}

void game_launcher(t_words *list, char *difficulty, char *category) {
    int i = 0;
    char replay;
    t_words *tmp = list;
    while (tmp != NULL) {
        if (my_strcmp(tmp->difficulty, difficulty) == 0)
            if (category == NULL || my_strcmp(tmp->category, category) == 0)
                i += 1;
        tmp = tmp->next;
    }
    do {
        int random = rand() % i;
        tmp = list;
        while (random > 0) {
            if (my_strcmp(tmp->difficulty, difficulty) == 0)
            if (category == NULL || my_strcmp(tmp->category, category) == 0)
                random -= 1;
            tmp = tmp->next;;
        }
        if (game(tmp) == 0) {
            printf("You won !\n");
            printf("Do you want to play again? (Y/N): ");
            scanf(" %c", &replay);
        }    
        else {
            printf("You lost !\n");
            replay = 'N';
        }
    } while (replay != 'N' && replay != 'n');
}