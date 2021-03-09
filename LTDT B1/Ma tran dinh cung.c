#include <stdio.h>
#include "list.c"
#define MAX_N 100
#define MAX_M 500
typedef struct
{
	int A[MAX_N][MAX_M];
	int n, m;
} Graph;

void init_graph(Graph *pG, int n, int m)
{
	pG->m = m;
	pG->n = n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			pG->A[i][j] = 0;
}

void add_edge(Graph *pG, int e, int x, int y)
{
	pG->A[x][e] = 1;
	pG->A[y][e] = 1;
}

int degree(Graph *pG, int x)
{
	int deg = 0;
	for (int i = 1; i <= pG->m; i++)
		deg += pG->A[x][i];
	return deg;
}

int adjacent(Graph *pG, int x, int y)
{
	for (int i = 1; i <= pG->m; i++)
		if (pG->A[x][i] == 1 && pG->A[y][i] == 1)
			return 1;
	return 0;
}

List neighbors(Graph *pG, int x)
{
	List L;
	make_null(&L);
	for (int y = 1; y <= pG->n; y++)
		if (adjacent(pG, y, x) && x != y)
			push_back(&L, y);
	return L;
}
