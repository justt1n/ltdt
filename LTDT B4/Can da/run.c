#include <stdio.h>

typedef struct
{
    int data[100];
    int size;
} List;
void make_null(List *L)
{
    L->size = 0;
}
void push_back(List *L, int x)
{
    L->data[L->size] = x;
    L->size += 1;
}
int element_at(List *L, int i)
{
    return L->data[i - 1];
}
int count_list(List *L)
{
    return L->size;
}

void copy_list(List *S1, List *S2)
{
    make_null(S1);
    int i;
    for (i = 1; i <= S2->size; i++)
    {
        int u = element_at(S2, i);
        push_back(S1, u);
    }
}

typedef struct
{
    int n;
    int A[100][100];
} Graph;

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pG->A[i][j] = 0;
}

void add_edge(Graph *pG, int x, int y)
{
    pG->A[x][y] = 1;
}

int rank[100];
void ranking(Graph *G)
{
    int d[100];
    int x, u;
    for (u = 1; u <= G->n; u++)
        d[u] = 0;
    for (x = 1; x <= G->n; x++)
    {
        for (u = 1; u <= G->n; u++)
            if (G->A[x][u] != 0)
                d[u]++;
    }
    List S1, S2;
    make_null(&S1);
    for (u = 1; u <= G->n; u++)
        if (!d[u])
            push_back(&S1, u);
    int k = 0, i; 
    while (S1.size != 0)
    {
        make_null(&S2);
        for (i = 1; i <= S1.size; i++)
        {
            u = element_at(&S1, i);
            rank[u] = k;
            int v;
            for (v = 1; v <= G->n; v++)
                if (G->A[u][v] != 0)
                {
                    d[v]--;
                    if (!d[v])
                        push_back(&S2, v);
                }
        }
        copy_list(&S1, &S2);
        k++;
    }
}

int main()
{
    freopen("dt2.txt", "r", stdin);
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    ranking(&G);
    int max_rank = -1;
    for(int i = 1; i <= G.n; i++)
    	if(rank[i] > max_rank)
    		max_rank = rank[i];
    int j = 0;
	while(j <= max_rank)
	{
		for(int i = 1; i <= G.n; i++)
		{
			if(rank[i] == j)
			{
				printf("%d ", i);
				break;
			}
		}
		j++;
	}
    return 0;
}
