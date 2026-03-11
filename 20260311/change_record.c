#include "ex2.h"

void change_record(void)
{
    char target[10];
    char new_grade[4];
    int i;
    int found = 0;

    printf("Input name to change: ");
    scanf("%9s", target);

    printf("Input new grade: ");
    scanf("%3s", new_grade);

    while (getchar() != '\n');

    for (i = 0; i < num_record; i++) {
        if (strcmp(r[i].name, target) == 0) {
            strcpy(r[i].grade, new_grade);

            printf("\nRecord changed:\n");
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