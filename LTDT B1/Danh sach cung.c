//
// Created by t1n on 1/14/21.
//
#include <stdio.h>
#define MAX_M 500
typedef struct
{
	int u, v;
} Edge;

typedef struct
{
	Edge edges[MAX_M];
	int n, m;
} Graph;

void ini_graph(Graph *pG, int n)
{
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG, int x, int y)
{
	pG->edges[pG->m].u = x;
	pG->edges[pG->m].v = y;
	pG->m++;
}

int degree(Graph *pG, int x)
{
	int count = 0;
	for (int i = 0; i <= pG->m; i++)
	{
		if (pG->edges[i].u == x && pG->edges[i].v != x)
			count++;
		if (pG->edges[i].u != x && pG->edges[i].v == x)
			count++;
	}
	return count;
}

int adjacent(Graph *pG, int x, int y)
{
	for (int i = 0; i < pG->m; i++)
	{
		if (pG->edges[i].u == x && pG->edges[i].v == y)
			return 1;
		if (pG->edges[i].u == y && pG->edges[i].v == x)
			return 1;
	}
	return 0;
}

void neighbors(Graph *pG, int x)
{
	for (int i = 1; i <= pG->n; i++)
		if (adjacent(pG, i, x) == 1 && x != i)
			printf("%d ", i);
}
