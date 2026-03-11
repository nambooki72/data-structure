#include "ex2.h"

void write_record(const char* fname)
{
    FILE* ofp;
    int i;

    ofp = fopen(fname, "w");
    if (ofp == NULL) {
        printf("Cannot open file for writing: %s\n", fname);
        return;
    }

    for (i = 0; i < num_record; i++) {
        fprintf(ofp, "%s %d %s\n", r[i].name, r[i].id, r[i].grade);
    }

    fclose(ofp);

    printf("All records have been written to %s\n", fname);
}