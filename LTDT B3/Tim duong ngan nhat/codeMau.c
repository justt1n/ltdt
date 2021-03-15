#include <stdio.h>
#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct
{
    ElementType data[MAX_ELEMENTS];
    int size;
} List;
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
    return G->A[x][y];
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
// int mark[MAX_VERTICES]; // kiem tra dinh da duoc duyet chua
// int pi[MAX_VERTICES];   // chieu dai duong di ngan nhat tu s den dinh i
// int p[MAX_VERTICES];    // dinh lien truoc duong i tren duong di ngan nhat
// void Dijkstra(Graph *G, int s)
// {
//     int i, j, it;
//     for (i = 1; i <= G->n; i++)
//     {
//         mark[i] = 0;
//         pi[i] = 999999;
//     }
//     pi[s] = 0;
//     p[s] = -1;
//     for (it = 1; it <= G->n; it++)
//     {
//         int min_pi = 999999;
//         for (j = 1; j <= G->n; j++)
//         {
//             if (mark[j] == 0 && pi[j] < min_pi)
//             {
//                 min_pi = pi[j];
//                 i = j;
//             }
//         }
//         mark[i] = 1;
//         for (j = 1; j <= G->n; j++)
//         {
//             if (adjacent(G, i, j) && mark[j] == 0)
//             {
//                 if (pi[i] + G->A[i][j] < pi[j])
//                 {
//                     pi[j] = pi[i] + G->A[i][j];
//                     p[j] = i;
//                 }
//             }
//         }
//     }
// }

int mark[100]; //mang danh dau
int pi[100];   //chieu dai tu dinh xuat phat den u
int p[100];    //dinh truoc u

void Dijkstra(Graph *pG, int s)
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
    Dijkstra(&G, 1);
    printf("%d", mark[n] ? pi[n] : -1);
    return 0;
}