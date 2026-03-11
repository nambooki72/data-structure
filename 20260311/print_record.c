#include "ex2.h"

void print_record(void)
{
    int i;

    printf("=====================================\n");
    printf("%-10s %-10s %-5s\n", "Name", "ID", "Grade");
    printf("=====================================\n");

    for (i = 0; i < num_record; i++) {
        printf("%-10s %-10d %-5s\n", r[i].name, r[i].id, r[i].grade);
    }

    printf("=====================================\n");
}