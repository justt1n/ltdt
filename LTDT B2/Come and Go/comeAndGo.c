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

//Ma tran dinh dinh
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

void add_edge1(Graph *pG, int x, int y)
{
    pG->A[x][y] = 1;
    //pG->A[y][x] = 1;
}

void add_edge2(Graph *pG, int x, int y)
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

//Stack
#define MAX_ELEMENTS 100
typedef struct
{
    int data[MAX_ELEMENTS];
    int size;
} Stack;
void make_null_stack(Stack *S)
{
    S->size = 0;
}
void push(Stack *S, int x)
{
    S->data[S->size] = x;
    S->size++;
}
int top(Stack *S)
{
    return S->data[S->size - 1];
}
void pop(Stack *S)
{
    S->size--;
}
int empty(Stack *S)
{
    return S->size == 0;
}

//Tarjan
int num[100];
int min_num[100];
int on_stack[100];
int k = 1;
int count = 0;
Stack S;
int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}
void strong_connect(Graph *G, int x)
{
    num[x] = min_num[x] = k;
    k++;
    push(&S, x);
    on_stack[x] = 1;

    List list = neighbors(G, x);
    for (int i = 1; i <= list.size; i++)
    {
        int y = element_at(&list, i);
        if (num[y] < 0)
        {
            strong_connect(G, y);
            min_num[x] = min(min_num[x], min_num[y]);
        }
        else if (on_stack[y])
            min_num[x] = min(min_num[x], num[y]);
    }
    if (num[x] == min_num[x])
    {
        count++;
        int w;
        do
        {
            w = top(&S);
            pop(&S);
            on_stack[w] = 0;
        } while (w != x);
    }
}

int main()
{
    freopen("cng4.txt", "r", stdin);
    Graph G;
    int m, n, a, b, c;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        if (c == 1)
            add_edge1(&G, a, b);
        else if (c == 2)
            add_edge2(&G, a, b);
    }
    for (int i = 1; i <= G.n; i++)
    {
        num[i] = -1;
        min_num[i] = -1;
        on_stack[i] = -1;
    }
    make_null_stack(&S);
    for (int i = 1; i <= G.n; i++)
        if (num[i] < 0)
            strong_connect(&G, i);
    printf("%d\n", count);
    printf("%s", count == 1 ? "OKIE" : "NO");
    return 0;
}