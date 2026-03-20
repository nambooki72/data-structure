#pragma warning(disable : 4996)
#include<stdio.h>
#include "matrix.h"


void main() {
	int a[ROW][COL] = { {1,0,0},{1,0,0},{1,0,0} };
	int b[ROW][COL] = { {1,1,1},{0,0,0},{0,0,0} };
	int c[ROW][COL] = { {1,0,0},{1,0,0},{1,0,0} };

	printf(" a = \n");
	matrix_print(a);
	printf("\n\n b = \n");
	matrix_print(b);

	matrix_add(a, b, c);
	printf("\n\n a + b = \n");
	matrix_print(c);

	matrix_init(c);
	printf("\n\n a * b = \n");
	matrix_mult(a, b, c);
	matrix_print(c);

	matrix_init(c);
	printf("\n\n a transpose = \n");
	matrix_trans(a, c);
	matrix_print(c);

}

void matrix_init(int a[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			a[i][j] = 0;
		}
	}
}

void matrix_add(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}
void matrix_mult(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			for (int k = 0; k < ROW; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

}
void matrix_trans(int a[ROW][COL], int c[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			c[j][i] = a[i][j];
		}
	}
}
void matrix_print(int a[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		printf("\n");
		for (int j = 0; j < COL; j++) {
			printf("%5d", a[i][j]);
		}
	}
}