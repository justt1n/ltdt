#include <stdio.h>
#include "stack.c"
#include "Ma tran dinh dinh.c"
void depth_first_search(Graph *G)
{
    Stack L;
    int mark[MAX_VERTEXES];
    make_null_stack(&L);

    int j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;

    push(&L, 1);

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
}
