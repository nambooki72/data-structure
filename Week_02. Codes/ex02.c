#include "ex02.h"

// Command processor
int main(void) {
	char c;

	read_record(fname);

	printf("********** 명령어 ********** \n");
	printf("P: Print all records \n");
	printf("S: Search record \n");
	printf("C: Change record \n");
	printf("W: Write record \n");
	printf("T: Sort the record \n");
	printf("Q: Save and quit \n");
	printf("**************************** \n");

	while (1) {
		printf("\nCommand> ");

		c = getchar();
		c = toupper(c);

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
			// optional - 선택 정렬
			sort_record();
			break;
		case 'Q':
			printf("\n");
			exit(1);
			break;
		default:
			printf("Unknown command ! \n");
			break;
		}
		while (getchar() != '\n');
	}
	return 0;
}

// Read from "grade.txt"
void read_record(const char* fname)
{
	int i = 0;
	FILE* ifp;

	ifp = fopen(fname, "r");
	while (fscanf(ifp, "%s %d %s", r[i].name, &r[i].id, r[i].grade) == 3)
		++i;

	num_record = i;
	fclose(ifp);
}

// Print all records
void print_record() {
	int i;

	printf("\n----------------------------------- \n");
	for (i = 0; i < num_record; i++) {
		printf("%10s %10d %10s \n", r[i].name, r[i].id, r[i].grade);
	}
	printf("----------------------------------- \n");
}

// Search record by student name
void search_record() {
	int i;
	char name[10];

	printf("\n Search name: ");
	scanf("%s", name);

	for (i = 0; i < num_record; i++) {
		if (!strcmp(r[i].name, name)) {
			printf("   Name:  %s \n", r[i].name);
			printf("   ID:    %d \n", r[i].id);
			printf("   Grade: %s \n", r[i].grade);
			return;
		}
	}
	printf("No such name ! \n");
}

// Change grade of a student
void change_record() {
	int i;
	char name[10], grade[4];

	printf("\n Name: ");
	scanf("%s", name);
	printf(" Grade: ");
	scanf("%s", grade);

	for (i = 0; i < num_record; i++) {
		if (!strcmp(r[i].name, name)) {
			strcpy(r[i].grade, grade);
			printf("\n Record changed ! \n");
			return;
		}
	}
	printf("No such name ! \n");
}

// Write record into "grade.txt"
void write_record(const char* fname) {
	int i = 0;
	FILE* ofp;

	if ((ofp = fopen(fname, "w")) == NULL) {
		printf("No such file ! \n");
		exit(1);
	}

	for (i = 0; i < num_record; i++) {
		fprintf(ofp, "%s %d %s \n", r[i].name, r[i].id, r[i].grade);
	}

	printf("\n %d records have written to %s. \n", num_record, fname);
	fclose(ofp);
}



// Optional - 선택 정렬
void sort_record() {
	int i, j, min_idx;
	StudentRecord temp;

	for (i = 0; i < num_record - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < num_record; j++) {
			if (r[j].id < r[min_idx].id) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			temp = r[i];
			r[i] = r[min_idx];
			r[min_idx] = temp;
		}
	}
	printf("\n Records sorted by student ID in ascending order.\n");
}
