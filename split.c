#include "hangman.h"

char *my_itoa(int n) {
    char *str;
    int len = 0;
    int tmp = n;
    int sign = 1;
    while (tmp != 0) {
        tmp /= 10;
        len += 1;
    }
    if (n < 0) {
        sign = -1;
        len += 1;
    }
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    while (len > 0) {
        str[len - 1] = (n % 10) * sign + '0';
        n /= 10;
        len -= 1;
    }
    if (sign == -1)
        str[0] = '-';
    return (str);
}

int my_strlen(char *str) {
    int i = 0;
    while (str[i] != '\0')
        i += 1;
    return (i);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i])
            return (-1);
        else if (s1[i] > s2[i])
            return (1);
        i +=1;
    }
    return (0);
}

char *my_strdup(char *str) {
    int i = 0;
    char *new = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        new[i] = str[i];
        i += 1;
    }
    new[i] = '\0';
    return (new);
}

char **split(char *src, char c) {
    int i = 0;
    int spaces = 2;
    int j = 0;
    int tmp = 0;

    while (src[i] != '\0') {
        if (src[i] == c)
            spaces += 1;
        i++;
    }
    i = 0;
    char **result = malloc(sizeof(char *) * (spaces + 1));
    spaces = 0;
    while (src[i] != '\0') {
        if (src[i] == c || src[i + 1] == '\0') {
            result[spaces] = malloc(sizeof(char) * (i - tmp + 2));
            while (tmp <= i) {
                if (src[i] != c || tmp != i) {
                    result[spaces][j] = src[tmp];
                    j += 1;
                }
                tmp+= 1;
            }
            result[spaces][j] = '\0';
            spaces += 1;
            j = 0;
        }
        i+= 1;
    }
    result[spaces] = NULL;
    return (result);
}

void my_free_array(char **array) {
    int i = 0;
    while (array[i] != NULL) {
        free(array[i]);
        i += 1;
    }
    free(array);
}