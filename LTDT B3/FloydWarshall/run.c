#include<stdio.h>

#include <stdio.h>
#define MAX_VERTICES 100
typedef struct
{
    int A[MAX_VERTICES][MAX_VERTICES];
    int n;
} Graph;
void init_graph(Graph *G, int n)
{
    G->n = n;
    int i, j;
    for (i = 1; i <= G->n; i++)
        for (j = 1; j <= G->n; j++)
            G->A[i][j] = 0;
}
void add_edge(Graph *G, int x, int y, int w)
{
    G->A[x][y] = w;
    //	G->A[y][x] = w;
}
int degree(Graph *G, int x)
{
    int y, deg = 0;
    for (y = 1; y <= G->n; y++)
        if (G->A[x][y] > 0)
            deg += 1;
    return deg;
}
int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y] != 0;
}

#define INFINITY 9999999

int pi[100][100];
int next[100][100];

void Floyd_Warshall(Graph *pG)
{
	int u, v, k;
	for(u = 1; u <= pG->n; u++)
		for(v = 1; v <= pG->n; v++)
		{
			pi[u][v] = INFINITY;
			next[u][v] = -1;
		}
	for(u = 1; u <= pG->n; u++)
		pi[u][u] = 0;
	for(u = 1; u <= pG->n; u++)
		for(v = 1; v <= pG->n; v++)
			if(pG->A[u][v] != 0)
			{
				pi[u][v] = pG->A[u][v];
				next[u][v] = v;
			}
	for(k = 1; k <= pG->n; k++)
		for(u = 1; u <= pG->n; u++)
			for(v = 1; v <= pG->n; v++)
				if(pi[u][k] + pi[k][v] < pi[u][v] && pi[u][k] != INFINITY && pi[k][v] != INFINITY)
				{
					pi[u][v] = pi[u][k] + pi[k][v];
					next[u][v] = next[u][k];
				}
}

int main()
{
	freopen("dt1.txt", "r", stdin); 
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++)
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	 
	Floyd_Warshall(&G);
	
	for(u = 1; u <= G.n; u++)
		for(v = 1; v <= G.n; v++)
		{
			printf("%d -> %d: ", u, v);
			if (pi[u][v] != INFINITY)
				printf("%d\n", pi[u][v]);
			else
				printf("oo\n");
		}		
	return 0;
}
