#include <stdio.h>
#define MAX_ELEMENTS 100
#define MAX_VERTEXES 100
typedef int ElementType;
typedef struct
{
    ElementType data[MAX_ELEMENTS];
    int size;
} List;
// cac ham lien quan toi List
void make_null(List *L)
{
    L->size = 0;
}
void push_back(List *L, ElementType x)
{
    L->data[L->size] = x;
    L->size++;
}
ElementType element_at(List *L, int i)
{
    return L->data[i - 1];
}
int count_List(List *L)
{
    return L->size;
}
typedef struct
{
    int A[MAX_VERTEXES][MAX_VERTEXES];
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
void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
    //G->A[y][x] = 1;
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
List neighbors(Graph *G, int x)
{
    int y;
    List list;
    make_null(&list);
    for (y = 1; y <= G->n; y++)
        if (adjacent(G, x, y))
            push_back(&list, y);
    return list;
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

#define white 0
#define black 1
#define gray 2
int color[MAX_VERTEXES];
int cycle;
void DFS(Graph *G, int x)
{
    color[x] = gray;
    int j;
    List list = neighbors(G, x);
    for (j = 1; j <= list.size; j++)
    {
        int y = element_at(&list, j);
        if (color[y] == gray)
        {
            cycle = 1; // t?n t?i chu tr?nh
            return;
        }
        if (color[y] == white)
            DFS(G, y);
    }
    color[x] = black;
}
int contain_cycle(Graph *G)
{
    int j;
    for (j = 1; j <= G->n; j++)
        color[j] = white;
    cycle = 0;
    DFS(G, 2);

    return cycle;
}
int main()
{
    freopen("haddock3.txt", "r", stdin);
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    if (contain_cycle(&G) == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
