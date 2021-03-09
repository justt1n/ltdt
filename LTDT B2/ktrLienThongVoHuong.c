#define white 0
#define black 1
#define gray 2
int color[MAX_VERTICES];
int cycle;
void DFS(Graph *G, int x, int parent)
{
    color[x] = gray;
    int j;
    List list = neighbors(G, x);
    for (j = 1; j <= list.size; j++)
    {
        int y = element_at(&list, j);
        if (y == parent)
            continue;
        if (color[y] == gray)
        {
            cycle = 1;
            return;
        }
        if (color[y] == white)
            DFS(G, y, x);
    }
    color[x] = black;
}
int contain_cycle(Graph *G)
{
    int j;
    for (j = 1; j <= G->n; j++)
        color[j] = white;
    cycle = 0;
    for (j = 1; j <= G->n; j++)
    {
        if (color[j] == white)
            DFS(G, j, 0);
    }
    return cycle;
}