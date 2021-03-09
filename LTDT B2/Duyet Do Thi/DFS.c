#include <stdio.h>
#include "stack.c"
#include "Ma tran dinh dinh.c"
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
        for (j = 1; j <= list.size; j++)
            printf("%d ", element_at(&list, j));
        /* Xét các đỉnh kề của nó */
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
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    printM(&G);
    depth_first_search(&G);
    return 0;
}