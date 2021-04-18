#include <stdio.h>
#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
typedef struct
{
	int u, v;
	int w;
} Edge;
typedef struct
{
	int n, m;
	Edge edges[MAX_VERTICES];
} Graph;
void init_graph(Graph *G, int n)
{
	G->n = n;
	G->m = 0;
}
void add_edge(Graph *G, int u, int v, int w)
{
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->m++;
}
int parent[MAX_VERTICES];
int findRoot(int u)
{
	if (parent[u] == u)
		return u;
	return findRoot(parent[u]);
}
int Krusal(Graph *G, Graph *T)
{
	int e, f, u;
	for (e = 0; e < G->m - 1; e++)
		for (f = e + 1; f < G->m; f++)
			if (G->edges[e].w > G->edges[f].w)
			{
				Edge tmp = G->edges[e];
				G->edges[e] = G->edges[f];
				G->edges[f] = tmp;
			}
	for (u = 1; u <= G->n; u++)
		parent[u] = u;
	int sum_w = 0, count_edges = 0;
	init_graph(T, G->n);
	for (e = 0; e < G->m; e++)
	{
		if (count_edges == G->n)
			break;
		count_edges++;
		int u = G->edges[e].u;
		int v = G->edges[e].v;
		int w = G->edges[e].w;
		int root_u = findRoot(u);
		int root_v = findRoot(v);
		if (root_u != root_v)
		{
			add_edge(T, u, v, w);
			parent[root_v] = root_u;
			sum_w += w;
		}
	}
	return sum_w;
}
int main()
{
	Graph G, T;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 1; e <= m; e++)
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	int kq = Krusal(&G, &T);
	printf("%d\n", kq);
	for (e = 0; e < T.m; e++)
		if (T.edges[e].u > T.edges[e].v)
			printf("%d %d %d\n", T.edges[e].v, T.edges[e].u, T.edges[e].w);
		else
			printf("%d %d %d\n", T.edges[e].u, T.edges[e].v, T.edges[e].w);
	return 0;
}
