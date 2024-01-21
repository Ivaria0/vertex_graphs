#include "stdio.h"
#include "locale.h"
#include "stdlib.h"

void graph(int A[][10])
{
	int o = 1, k = 1;
	printf("Введите, откуда и куда направлено ребро: ");
	scanf_s("%i%i", &o, &k);
	printf("\n");
	while ((o != -1) && (k != -1)) {
		A[o][k] = 1;
		printf("Введите, откуда и куда направлено ребро: ");
		scanf_s("%i%i", &o, &k);
		printf("\n");
	}
}

void wayexist(int B[][10], int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			k = 0;
			while ((B[i][j] == 0) && (k < n)) {
				if ((B[i][k] != 0) && (B[k][j] != 0))
					B[i][j] = 1;
				k++;
			}
		}
}

void mult(int B[][10], int n)
{
	for (int t = 0; t < n; t++)
		wayexist(B, n);
}

void main()
{
	setlocale(LC_ALL, "RUS");
	int A[10][10], B[10][10], C[10][10], n, i, j, x, p, q;
	int y;
	y = 0;
	printf("Введите количество вершин графа: ");
	scanf_s("%i", &n);
	printf("\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			A[i][j] = 0;
	graph(A);
	printf("Первая выделенная вершина: ");
	scanf_s("%i", &p);
	printf("\n");
	printf("Вторая выделенная вершина: ");
	scanf_s("%i", &q);
	printf("\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			B[i][j] = A[i][j];
	mult(B, n);
	if (B[p][q] == 0)
		printf("Между данными вершинами нет пути\n");
	else {
		for (x = 0; x < n; x++) {
			if ((B[p][x] != 0) && (B[x][q] != 0)) {
				for (i = 0; i < n; i++)
					for (j = 0; j < n; j++)
						if ((i == x) || (j == x))
							C[i][j] = 0;
						else C[i][j] = A[i][j];
				mult(C, n);
				if (C[p][q] == 0) {
					printf("Вершина %i принадлежит каждому пути между выделенными вершинами\n", x);
					y = 1;
				}
			}
		}
		if (y == 0)
			printf("Нет такой вешины, которая принадлежит каждому пути между выделенными вершинами");
	}
}