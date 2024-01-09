#include "hangman.h" 

int argsCheck(int argc, char **argv)
{
    int fd;

    if (argc != 3 && argc != 4)
    {
        write(1, "Usage: ./hangman dictionaryFile.txt [facile/moyen/difficile] <categorie>\n", 74);
        return -1;
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        write(1, "Error: cannot open dictionary file\n", 35);
        return -1;
    }
    if (my_strcmp(argv[2], "facile") != 0 && my_strcmp(argv[2], "moyen") != 0 && my_strcmp(argv[2], "difficile") != 0)
    {
        write(1, "Error: difficulty must be facile, moyen or difficile\n", 53);
        return -1;
    }
    return fd;
}

int main(int argc, char **argv)
{
    printf("Ncurses version: %d;\n", NCURSES_VERSION_MAJOR);
    int fd = argsCheck(argc, argv);
    if (fd == -1)
        return -1;
    t_words *list = file_to_list(fd, argv[2], argc == 4 ? argv[3] : NULL);
    close(fd);
    if (list == NULL)
    {
        write(1, argv[1], my_strlen(argv[1]));
        write(1, " : invalid file\n", 16);
        return -1;
    }
    game_launcher(list, argv[2], argc == 4 ? argv[3] : NULL);
    my_free_list(list);
    return 0;
}