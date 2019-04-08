/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

static char **malloc_map(int line)
{
    char **tab = malloc(sizeof(char *) * (line + 1));

    if (tab == NULL)
        return NULL;

    return tab;
}

int get_number_line(const char *path)
{
    size_t size = 0;
    char *line = NULL;
    int counter = 0;

    FILE *file = fopen(path, "r");

    while ((getline(&line, &size, file)) > 0)
        counter++;

    return counter + 1;
}

char **get_map(solver_t *solver, const char *path)
{
    FILE *file = NULL;
    size_t size = 0;
    int i = 0;

    file = fopen(path, "r");
    if (file == NULL)
        return NULL;

    solver->map = malloc_map(get_number_line(path));

    while ((getline(&solver->map[i], &size, file)) > 0)
        i++;

    solver->map[i] = NULL;
    fclose(file);
    return solver->map;
}



int main(int ac, char **av)
{
    solver_t *solver = malloc(sizeof(solver_t));

        solver->map = get_map(solver, av[1]);

        int i = 0;

        while (solver->map[i] != NULL) {
            printf("%s", solver->map[i]);
            i++;
        }
}