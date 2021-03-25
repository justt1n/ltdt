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

int mark[MAX_VERTICES];
int pi[MAX_VERTICES];
int p[MAX_VERTICES];

void Dijkstra(Graph *pG, int s)
{
    for (int i = 1; i <= pG->n; i++)
    {
        mark[i] = 0;
        pi[i] = 9999999;
    }
    pi[s] = 0;
    p[s] = -1;
    for (int i = 1; i <= pG->n; i++)
    {
        int min_pi = 9999999;
        int k; //danh dau dinh
        for (int j = 1; j <= pG->n; j++)
            if (mark[j] == 0 && pi[j] < min_pi)
            {
                min_pi = pi[j];
                k = j;
            }
        mark[k] = 1;
        for (int j = 1; j <= pG->n; j++)
        {
            if (adjacent(pG, k, j) && mark[j] == 0)
                if (pi[k] + pG->A[k][j] < pi[j])
                {
                    pi[j] = pi[k] + pG->A[k][j];
                    p[j] = k;
                }
        }
    }
}

int main()
{
    freopen("maze3.txt", "r", stdin);
    Graph G;
    int m, n, w[MAX_VERTICES][MAX_VERTICES];
    scanf("%d%d", &m, &n);
    init_graph(&G, m * n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            w[i][j] = tmp;
        }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            int u = (i * n + j) + 1;
            if (i - 1 >= 0)
            {
                int v = ((i - 1) * n + j) + 1;
                add_edge(&G, u, v, w[i - 1][j]);
            }
            if (i + 1 < m)
            {
                int v = ((i + 1) * n + j) + 1;
                add_edge(&G, u, v, w[i + 1][j]);
            }
            if (j - 1 >= 0)
            {
                int v = (i * n + (j - 1)) + 1;
                add_edge(&G, u, v, w[i][j - 1]);
            }
            if (j + 1 < n)
            {
                int v = (i * n + (j + 1)) + 1;
                add_edge(&G, u, v, w[i][j + 1]);
            }
        }
    Dijkstra(&G, 1);
    printf("%d", pi[m * n] + w[0][0]);
}