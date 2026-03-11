#include "ex2.h"

void read_record(const char* fname)
{
    FILE* ifp;
    int i = 0;

    ifp = fopen(fname, "r");
    if (ifp == NULL) {
        printf("Cannot open file: %s\n", fname);
        exit(1);
    }

    while (i < MAX && fscanf(ifp, "%9s %d %3s", r[i].name, &r[i].id, r[i].grade) == 3) {
        i++;
    }

    num_record = i;
    fclose(ifp);
}