#include<stdio.h>

#include<stdio.h>
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
typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;
/* Tao danh sach rong */
void make_null(List* L) {
	L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List* L, int i) {
	return L->data[i-1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
	return L->size;
}

int member(List *L, int x)
{
	for(int i = 0; i < L->size; i++)
		if(L->data[i] == x)
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

#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[100];
int cycle = 0;

void visit(Graph *pG, int u)
{
	color[u] = GRAY;
	List list = neighbors(pG, u);
	for (int i = 1; i <= list.size; i++)
	{
		if(color[i] == GRAY)
		{
			cycle = 1;
			return;
		}
		if(color[i] == WHITE)
			visit(pG, i);
	}
	color[u] = BLACK;
}

int main()
{
	freopen("ctr1.txt", "r", stdin); 
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	for(int i = 1; i <= G.n; i++)
		color[i] = WHITE;
	visit(&G, 1);
	if(cycle == 1)
		printf("YES");
	else
		printf("NO");
	return 0;
}
