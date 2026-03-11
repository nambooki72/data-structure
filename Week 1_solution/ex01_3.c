// array max 구하기
#include <stdio.h> 

void main() {
    int i, max_index;
	int score[10] = {55, 20, 33, 85, 13, 22, 45, 98, 67, 77}; 

	// 배열 출력 
	printf("10명의 성적입니다: \n\n");	
	for (i = 0; i < 10; i++) {
		printf("%d 번: %d 점 \n", i, score[i]);
	}
	printf("\n");

	//가장 높은 성적 구하기
	max_index = 0;
	for (i=1; i<10; i++) {
		if (score[max_index] < score[i]) max_index = i;
	};

	printf("1등은 %d 번, 성적은 %d 입니다. \n\n", max_index, score[max_index]);	
}
