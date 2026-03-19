#include<stdio.h>
#include "matrix.h"

void main()
{
	int a[ROW][COL] = { {1,0,0},{1,0,0},{1,0,0} };
	int b[ROW][COL] = { {1,1,1},{0,0,0},{0,0,0} };
	int c[ROW][COL] = { {0,0,0},{0,0,0},{0,0,0} };

    printf("a = \n");
	matrix_print(a);
    printf("b = \n");
	matrix_print(b);

    matrix_add(a, b, c);
    printf("a+b =\n");
	matrix_print(c);

	matrix_init(c);
    printf("a*b =\n");
	matrix_mult(a, b, c);
	matrix_print(c);

	matrix_init(c);
    printf("a transpose = \n");
	matrix_trans(a, c);
	matrix_print(c);
}


void matrix_init(int a[ROW][COL])
{
    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            a[i][j] = 0;
        }
    }
}

void matrix_add(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL])
{
    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrix_mult(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL])
{
    int i, j, k;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < COL; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void matrix_trans(int a[ROW][COL], int b[ROW][COL])
{
    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            b[j][i] = a[i][j];
        }
    }
}

void matrix_print(int a[ROW][COL])
{
    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}