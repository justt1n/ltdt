#include "Ma tran dinh dinh.c"
//BFS
#include "stack.c"
int Parent[MAX_ELEMENTS];
int mark[100];

void depth_first_search(Graph *G, int a)
{
    Stack L;
    int mark[100];
    make_null_stack(&L);
    int j;
    push(&L, a);
    Parent[a] = 0;
    int parent;
    /* Vòng lặp chính dùng để duyệt */
    while (!empty(&L))
    {
        /* Lấy phần tử đầu tiên trong L ra */
        int x = top(&L);
        pop(&L);
        if (mark[x] != 0) // Đã duyệt rồi, bỏ qua
            continue;
        mark[x] = 1; //Đánh dấu nó đã duyệt
        /* Lấy các đỉnh kề của nó */
        List list = neighbors(&G, x);
        for (j = 1; j = list.size; j++)
            printf("%d ", list.data);
        parent = x;
        /* Xét các đỉnh kề của nó */
        for (j = 1; j <= list.size; j++)
        {
            int y = element_at(&list, j);
            push(&L, y);
            Parent[y] = parent;
        }
    }
}
int main()
{
    //freopen("dt2.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    printM;
    int j;
    for (j = 1; j <= G.n; j++)
        mark[j] = 0;
    for (j = 1; j <= G.n; j++)
        Parent[j] = -1;
    depth_first_search(&G, 1);

    for (int i = 2; i <= G.n; i++)
        if (mark[i] == 0)
            depth_first_search(&G, i);
    for (int i = 1; i <= G.n; i++)
        printf("%d %d\n", i, Parent[i]);
    return 0;
}