#include <stdio.h>
#include "list.c"
#define MAX_VERTEXES 100
typedef struct
{
	int A[100][100];
	int n;
} Graph;

void init_graph(Graph *pG, int n)
{
	pG->n = n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			pG->A[i][j] = 0;
}

void add_edge(Graph *pG, int x, int y, int w)
{
	pG->A[x][y] = w;
}

int degree(Graph *pG, int x)
{
	int deg = 0;
	for (int i = 1; i <= pG->n; i++)
		if (pG->A[x][i] > 0)
			deg += 1;
	return deg;
}

int adjacent(Graph *pG, int x, int y)
{
	return pG->A[x][y];
}

List neighbors(Graph *pG, int x)
{
	List L;
	make_null(&L);
	for (int i = 1; i <= pG->n; i++)
		if (adjacent(pG, x, i) == 1 && x != i)
			push_back(&L, i);
	return L;
}

void printM(Graph *pG)
{
	for (int i = 1; i <= pG->n; i++)
	{
		for (int j = 1; j <= pG->n; j++)
			printf("%d ", pG->A[i][j]);
		printf("\n");
	}
}

//int main()
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	Graph G;
//	init_graph(&G, n);
//	for(int i = 1; i <= m; i++)
//	{
//		int x, y;
//		scanf("%d%d", &x, &y);
//		add_edge(&G, x, y);
//	}
//	neighbors(&G, 2);
//	return 0;
//}
