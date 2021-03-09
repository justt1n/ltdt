#include <stdio.h>
#include "queue.c"
#include "Ma tran dinh dinh.c"
void breath_first_search(Graph *G)
{
    Queue L;
    int mark[MAX_VERTEXES];
    make_null_queue(&L);
    
    int j;
    for (j = 1; j <= G->n; j++)
        mark[j] = 0;
    
    push(&L, 1);
    
    printf("Duyet 1\n");
    mark[1] = 1;
    
    while (!empty(&L))
    {
        
        int x = top(&L);
        pop(&L);
        
        List list = neighbors(G, x);
        
        for (j = 1; j <= list.size; j++)
        {
            int y = element_at(&list, j);
            if (mark[y] == 0)
            { 
                printf("Duyet %d\n", y);
                mark[y] = 1; 
                push(&L, y);
            }
        }
    }
}
