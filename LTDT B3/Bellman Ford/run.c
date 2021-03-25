//
// Created by t1n on 1/14/21.
//
#include <stdio.h>
#define MAX_M 500
typedef struct
{
    int u, v, w;
} Edge;

typedef struct
{
    Edge edges[MAX_M];
    int n, m;
} Graph;

void init_graph(Graph *pG, int n)
{
    pG->n = n;
    pG->m = 1;
}

void add_edge(Graph *pG, int x, int y, int w)
{
    pG->edges[pG->m].u = x;
    pG->edges[pG->m].v = y;
    pG->edges[pG->m].w = w;
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

#define INFINITY 9999999
#define MAXN 100

int pi[MAXN];
int p[MAXN];
// int flag = 0; // Co chu trinh am hay khong
int BellmanFord(Graph *pG, int s)
{
    int u, v, w;
    for (int i = 1; i <= pG->n; i++)
        pi[i] = INFINITY;
    pi[s] = 0;
    p[s] = -1;
    for (int i = 1; i <= pG->n; i++)
    {
        for (int k = 1; k <= pG->m; k++)
        {
            u = pG->edges[k].u;
            v = pG->edges[k].v;
            w = pG->edges[k].w;
            if (pi[u] + w < pi[v])
            {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }
    for (int k = 1; k <= pG->m; k++)
    {
        u = pG->edges[k].u;
        v = pG->edges[k].v;
        w = pG->edges[k].w;
        if (pi[u] + w < pi[v])
            return 1;
    }
    return 0;
}

int main()
{
    freopen("run3.txt", "r", stdin);
    int m, n, u, v, w, e;
    Graph G;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    int s;
    scanf("%d", &s);
    printf("%s", BellmanFord(&G, s) ? "YES" : "NO");
    return 0;
}