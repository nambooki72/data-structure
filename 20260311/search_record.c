#include "ex2.h"

void search_record(void)
{
    char target[10];
    int i;
    int found = 0;

    printf("Input name to search: ");
    scanf("%9s", target);

    while (getchar() != '\n');

    for (i = 0; i < num_record; i++) {
        if (strcmp(r[i].name, target) == 0) {
            printf("\nRecord found:\n");
            printf("Name  : %s\n", r[i].name);
            printf("ID    : %d\n", r[i].id);
            printf("Grade : %s\n", r[i].grade);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("No such student.\n");
    }
}