#include <stdio.h>

#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct
{
    ElementType data[MAX_ELEMENTS];
    int size;
} List;
/* Tao danh sach rong */
void make_null(List *L)
{
    L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List *L, ElementType x)
{
    L->data[L->size] = x;
    L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List *L, int i)
{
    return L->data[i - 1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List *L)
{
    return L->size;
}

int member(List *L, int x)
{
    for (int i = 0; i < L->size; i++)
        if (L->data[i] == x)
            return 1;
    return 0;
}

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

int mark[100]; //mang danh dau
int pi[100];   //chieu dai tu dinh xuat phat den u
int p[100];    //dinh truoc u

void dijkstra(Graph *pG, int s)
{
    int i, j, k;
    for (i = 1; i <= pG->n; i++)
    {
        pi[i] = 99999;
        mark[i] = 0;
    }
    pi[s] = 0;
    p[s] = -1;

    for (k = 1; k <= pG->n; k++)
    {
        int min_pi = 99999;
        for (j = 1; j <= pG->n; j++)
        {
            if (mark[j] == 0 && pi[j] < min_pi)
            {
                min_pi = pi[j];
                i = j;
            }
        }
        mark[i] = 1;
        for (int j = 1; j <= pG->n; j++)
            if (pG->A[i][j] != 0 && mark[j] == 0)
                if (pi[i] + pG->A[i][j] < pi[j])
                {
                    pi[j] = pi[i] + pG->A[i][j];
                    p[j] = i;
                }
    }
}

int main()
{
    freopen("dt3.txt", "r", stdin);
    Graph G;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    dijkstra(&G, 1);
    printf("%d", mark[n] ? pi[n] : -1);
    return 0;
}