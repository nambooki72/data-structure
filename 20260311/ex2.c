#include "ex2.h"

/* 전역변수 실제 정의는 여기만 */
StudentRecord r[MAX];
int num_record = 0;
const char* fname = "grade.txt";

int main(void)
{
    char c;

    printf("Reading record from %s\n", fname);
    read_record(fname);
    printf("%d records have been read.\n", num_record);

    printf("\n********** Command **********\n");
    printf("P : Print all records\n");
    printf("S : Search record by name\n");
    printf("C : Change student's grade\n");
    printf("W : Write records to file\n");
    printf("T : Sort records by ID\n");
    printf("Q : Quit program\n");
    printf("*****************************\n");

    while (1) {
        printf("\nCommand > ");

        c = getchar();
        c = (char)toupper(c);

        while (getchar() != '\n');

        printf("\n");

        switch (c) {
        case 'P':
            print_record();
            break;
        case 'S':
            search_record();
            break;
        case 'C':
            change_record();
            break;
        case 'W':
            write_record(fname);
            break;
        case 'T':
            sort_record();
            printf("Records have been sorted by ID.\n");
            break;
        case 'Q':
            printf("Program finished.\n");
            return 0;
        default:
            printf("Unknown command!\n");
            break;
        }
    }
}