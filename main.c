#include "hangman.h"

int argsCheck(int argc, char **argv)
{
    int fd;

    if (argc != 3 && argc != 4 && argc != 1)
    {
        write(1, "Usage: ./hangman dictionaryFile.txt [facile/moyen/difficile] <categorie>\n", 74);
        return -1;
    }
    if (argc == 1)
    {
        fd = open("dictionnaire.txt", O_RDONLY);
        if (fd == -1)
        {
            write(1, "Error: dictionnaire.txt not found\n", 34);
            return -1;
        }
        return fd;
    }
    fd = open(argv[1], O_RDONLY);
    if (my_strcmp(argv[2], "facile") != 0 && my_strcmp(argv[2], "moyen") != 0 && my_strcmp(argv[2], "difficile") != 0)
    {
        write(1, "Error: difficulty must be facile, moyen or difficile\n", 53);
        return -1;
    }
    return fd;
}

int main(int argc, char **argv)
{
    int fd = argsCheck(argc, argv);
    t_wrong_line *wrong_lines = NULL;
    if (fd == -1)
    {
        write(1, argv[1], my_strlen(argv[1]));
        write(1, " : invalid file\n", 16);
        return -1;
    }
    t_words *list = file_to_list(fd, argc >= 3 ? argv[2] : NULL, argc == 4 ? argv[3] : NULL, &wrong_lines);
    close(fd);
    if (list == NULL)
    {
        my_print_wrong_lines(wrong_lines);
        my_free_wrong_lines(wrong_lines);
        write(1, argv[1], my_strlen(argv[1]));
        write(1, " : invalid file\n", 16);
        return -1;
    }
    game_launcher(list);
    my_free_list(list);
    my_print_wrong_lines(wrong_lines);
    my_free_wrong_lines(wrong_lines);
    return 0;
}