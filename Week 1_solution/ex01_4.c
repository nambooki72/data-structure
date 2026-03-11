
#include <stdio.h> 

int find_max(int a[], int size) {
    int i, max_i;

	max_i = 0;
	for (i=1; i<size; i++) {
		if (a[max_i] < a[i]) max_i = i;
	}
	return max_i;
}

void main() {
    int i, max_index;
	int score[10] = {55, 20, 33, 85, 13, 22, 45, 98, 67, 77}; 

	printf("10명의 성적입니다: \n\n");	
	for (i = 0; i < 10; i++) {
		printf("%d 번: %d 점 \n", i, score[i]);
	}
	printf("\n");

	max_index = find_max(score, 10);
	printf("1등은 %d 번, 성적은 %d 입니다. \n\n", max_index, score[max_index]);	
}


