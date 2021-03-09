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

void add_edge(Graph *pG, int x, int y)
{
    pG->A[x][y] = 1;
    pG->A[y][x] = 1;
}

int degree(Graph *pG, int x)
{
    int deg = 0;
    for (int i = 1; i <= pG->n; i++)
        deg += pG->A[x][i];
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

#define MAX_ELEMENTS 100
typedef struct
{
    int data[MAX_ELEMENTS];
    int front, rear;
} Queue;
void make_null_queue(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
}
void push(Queue *Q, int x)
{
    Q->rear++;
    Q->data[Q->rear] = x;
}
int top(Queue *Q)
{
    return Q->data[Q->front];
}
void pop(Queue *Q)
{
    Q->front++;
}
int empty(Queue *Q)
{
    return Q->front > Q->rear;
}
int mark[MAX_VERTEXES];
void breath_first_search(Graph *G, int x)
{
    if (mark[x] != 0)
        return;
    Queue L;
    make_null_queue(&L);
    int j;
    push(&L, x);
    while (!empty(&L))
    {
        int x = top(&L);
        pop(&L);
        if (mark[x] != 0)
            continue;
        printf("%d\n", x);
        mark[x] = 1;
        List list = neighbors(G, x);
        for (j = 1; j <= list.size; j++)
        {
            int y = element_at(&list, j);
            push(&L, y);
        }
    }
}

int main()
{
    freopen("dt2.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    for (int i = 1; i <= G.n; i++)
        mark[i] = 0;
    for (int i = 1; i <= G.n; i++)
        if (mark[i] == 0)
            breath_first_search(&G, i);
    return 0;
}