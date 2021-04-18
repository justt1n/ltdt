#include <stdio.h>
#define MAX_ELEMENTS 100
typedef struct
{
    int u, v;
    int w;
} Edge;
typedef struct
{
    int n, m;
    Edge edges[100];
} Tree;
void init_Tree(Tree *G, int n)
{
    G->n = n;
    G->m = 0;
}
void add_edge_Tree(Tree *G, int u, int v, int w)
{
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].w = w;
    G->m++;
}
typedef struct
{
    int n, m;
    int L[100][100];
} Graph;
typedef struct
{
    int data[MAX_ELEMENTS];
    int size;
} List;
void makenull_List(List *L)
{
    L->size = 0;
}
void push_back(List *L, int x)
{
    L->data[L->size] = x;
    L->size += 1;
}
int count_list(List *L)
{
    return L->size;
}
int element_at(List *L, int i)
{
    return L->data[i - 1];
}
void init_Graph(Graph *G, int n)
{
    G->n = n;
    G->m = 0;
    int i, j;
    for (i = 1; i <= G->n; i++)
        for (j = 1; j <= G->n; j++)
            G->L[i][j] = 0;
}
void add_edge(Graph *G, int u, int v, int w)
{
    G->m++;
    G->L[u][v] = w;
    G->L[v][u] = w;
}
int adjacent(Graph *G, int u, int v)
{
    return G->L[u][v] != 0;
}
List neighbors(Graph *G, int u)
{
    List nb;
    makenull_List(&nb);
    int v;
    for (v = 1; v <= G->n; v++)
        if (adjacent(G, u, v))
            push_back(&nb, v);
    return nb;
}
int mark[100]; // danh dau dinh u da duoc xet hay chua
int pi[100];   // khoang cach gan nhat tu u den 1 trong cac dinh da xet
int p[100];    // dinh da xet gan voi u nhat
int Prim(Graph *G, Tree *T)
{
    int u, i, v, it, j;
    for (u = 1; u <= G->n; u++)
    {
        mark[u] = 0;
        pi[u] = 999;
    }
    mark[1] = 1;
    pi[1] = 0;
    List list = neighbors(G, 1);
    for (i = 1; i <= list.size; i++)
    {
        v = element_at(&list, i);
        pi[v] = G->L[1][v];
        p[v] = 1;
    }
    init_Tree(T, G->n);
    int sum_w = 0;
    for (it = 1; it < G->n; it++)
    {
        int min_pi = 999;
        for (j = 1; j <= G->n; j++)
        {
            if (mark[j] == 0 && pi[j] < min_pi)
            {
                u = j;
                min_pi = pi[j];
            }
        }
        mark[u] = 1;
        sum_w += min_pi;
        add_edge_Tree(T, p[u], u, min_pi);
        List l = neighbors(G, u);
        for (i = 1; i <= l.size; i++)
        {
            v = element_at(&l, i);
            if (mark[v] == 0 && G->L[u][v] < pi[v])
            {
                pi[v] = G->L[u][v];
                p[v] = u;
            }
        }
    }
    return sum_w;
}
int main()
{
    Graph G;
    Tree T;
    int n, m, e, u, v, w;
    scanf("%d%d", &n, &m);
    init_Graph(&G, n);
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    printf("%d\n", Prim(&G, &T));
    for (e = 0; e < T.m; e++)
        if (T.edges[e].u > T.edges[e].v)
            printf("%d %d %d\n", T.edges[e].v, T.edges[e].u, T.edges[e].w);
        else
            printf("%d %d %d\n", T.edges[e].u, T.edges[e].v, T.edges[e].w);
    return 0;
}