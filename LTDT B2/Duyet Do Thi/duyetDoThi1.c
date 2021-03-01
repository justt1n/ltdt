#include <stdio.h>

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

// #define MAX_ELEMENTS 100
// typedef struct
// {
//     int data[MAX_ELEMENTS];
//     int front, rear;
// } Queue;
// void make_null_queue(Queue *Q)
// {
//     Q->front = 0;
//     Q->rear = -1;
// }
// void push(Queue *Q, int x)
// {
//     Q->rear++;
//     Q->data[Q->rear] = x;
// }
// int top(Queue *Q)
// {
//     return Q->data[Q->front];
// }
// void pop(Queue *Q)
// {
//     Q->front++;
// }
// int empty(Queue *Q)
// {
//     return Q->front > Q->rear;
// }

// void breath_first_search(Graph *G)
// {
//     Queue L;
//     int mark[MAX_VERTEXES];
//     make_null_queue(&L);
//     /* Khởi tạo mark, chưa đỉnh nào được xét */
//     int j;
//     for (j = 1; j <= G->n; j++)
//         mark[j] = 0;
//     push(&L, 1);
//     printf("1\n");
//     mark[1] = 1;
//     /* Vòng lặp chính dùng để duyệt */
//     while (!empty(&L))
//     {
//         /* Lấy phần tử đầu tiên trong L ra */
//         int x = top(&L);
//         pop(&L);
//         /* Lấy các đỉnh kề của nó */
//         List list = neighbors(G, x);
//         /* Xét các đỉnh kề của nó */
//         for (j = 1; j <= list.size; j++)
//         {
//             int y = element_at(&list, j);
//             if (mark[y] == 0)
//             { // y chưa duyệt, duyệt nó
//                 printf("%d\n", y);
//                 mark[y] = 1; //Đánh dấu y đã duyệt
//                 push(&L, y);
//             }
//         }
//     }
//     int isDone = 0;
//     int min = 9999;
//     for (int i = 1; i <= G->n; i++)
//         isDone += mark[i];
//     while (isDone < G->n)
//     {
//         for (int i = 1; i <= G->n; i++)
//             if (mark[i] == 0)
//                 if (i < min)
//                     min = i;
//         printf("%d\n", min);
//         mark[min] = 1;
//         push(&L, min);
//         while (!empty(&L))
//         {
//             /* Lấy phần tử đầu tiên trong L ra */
//             int x = top(&L);
//             pop(&L);
//             /* Lấy các đỉnh kề của nó */
//             List list = neighbors(G, x);
//             /* Xét các đỉnh kề của nó */
//             for (j = 1; j <= list.size; j++)
//             {
//                 int y = element_at(&list, j);
//                 if (mark[y] == 0)
//                 { // y chưa duyệt, duyệt nó
//                     printf("%d\n", y);
//                     mark[y] = 1; //Đánh dấu y đã duyệt
//                     push(&L, y);
//                 }
//             }
//         }
//         for (int i = 1; i <= G->n; i++)
//             isDone += mark[i];
//     }
// }

void depth_first_search(Graph *G)
{
    Stack L;
    int mark[MAX_VERTEXES];
    make_null_stack(&L);
    /* Khởi tạo mark, chưa đỉnh nào được duyệt */
    int j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    /* Đưa 1 vào L, bắt đầu duyệt từ đỉnh 1 */
    push(&L, 1);
    /* Vòng lặp chính dùng để duyệt */
    while (!empty(&L))
    {
        /* Lấy phần tử đầu tiên trong L ra */
        int x = top(&L);
        pop(&L);
        if (mark[x] != 0) // Đã duyệt rồi, bỏ qua
            continue;
        printf("Duyet %d\n", x);
        mark[x] = 1; //Đánh dấu nó đã duyệt
        /* Lấy các đỉnh kề của nó */
        List list = neighbors(G, x);
        /* Xét các đỉnh kề của nó */
        for (j = 1; j <= list.size; j++)
        {
            int y = element_at(&list, j);
            push(&L, y);
        }
        int isDone = 0;
        int min = 9999;
        for (j = 1; j <= list.size; j++)
            isDone += mark[j];
        while (isDone < G->n)
        {
            for (int i = 1; i <= G->n; i++)
                if (mark[i] == 0)
                    if (i < min)
                        min = i;
            push(&L, min);
            while (!empty(&L))
            {
                /* Lấy phần tử đầu tiên trong L ra */
                int x = top(&L);
                pop(&L);
                if (mark[x] != 0) // Đã duyệt rồi, bỏ qua
                    continue;
                printf("Duyet %d\n", x);
                mark[x] = 1; //Đánh dấu nó đã duyệt
                /* Lấy các đỉnh kề của nó */
                List list = neighbors(G, x);
                /* Xét các đỉnh kề của nó */
                for (j = 1; j <= list.size; j++)
                {
                    int y = element_at(&list, j);
                    push(&L, y);
                }
            }
            for (int i = 1; i <= G->n; i++)
                isDone += mark[i];
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
    depth_first_search(&G);
    return 0;
}