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
int mark[MAX_VERTICES]; // kiem tra dinh da duoc duyet chua
int pi[MAX_VERTICES];   // chieu dai duong di ngan nhat tu s den dinh i
int p[MAX_VERTICES];    // dinh lien truoc duong i tren duong di ngan nhat
void Dijkstra(Graph *G, int s)
{
    int i, j, it;
    for (i = 1; i <= G->n; i++)
    {
        mark[i] = 0;
        pi[i] = 999999;
    }
    pi[s] = 0;
    p[s] = -1;
    for (it = 1; it <= G->n; it++)
    {
        int min_pi = 999999;
        for (j = 1; j <= G->n; j++)
        {
            if (mark[j] == 0 && pi[j] < min_pi)
            {
                min_pi = pi[j];
                i = j;
            }
        }
        mark[i] = 1;
        for (j = 1; j <= G->n; j++)
        {
            if (adjacent(G, i, j) && mark[j] == 0)
            {
                if (pi[i] + G->A[i][j] < pi[j])
                {
                    pi[j] = pi[i] + G->A[i][j];
                    p[j] = i;
                }
            }
        }
    }
}
int main()
{
    Graph G;
    int M, N, x, i, j, u, v, w[MAX_VERTICES][MAX_VERTICES];
    scanf("%d%d", &M, &N);
    init_graph(&G, M * N);
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
        {
            scanf("%d", &x);
            w[i][j] = x;
        }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            u = (i * N + j) + 1;
            if (j - 1 >= 0)
            {
                v = (i * N + j - 1) + 1;
                add_edge(&G, u, v, w[i][j - 1]);
            }
            if (j + 1 < N)
            {
                v = (i * N + (j + 1)) + 1;
                add_edge(&G, u, v, w[i][j + 1]);
            }
            if (i - 1 >= 0)
            {
                v = ((i - 1) * N + j) + 1;
                add_edge(&G, u, v, w[i - 1][j]);
            }
            if (i + 1 < M)
            {
                v = ((i + 1) * N + j) + 1;
                add_edge(&G, u, v, w[i + 1][j]);
            }
        }
    }
    Dijkstra(&G, 1);
    printf("%d", pi[N * M] + w[0][0]);
}