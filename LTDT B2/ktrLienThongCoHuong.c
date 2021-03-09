#define white 0
#define black 1
#define gray 2
int color[100];
int cycle;
void DFS(Graph *G, int x)
{
    color[x] = gray;
    int j;
    List list = neighbors(G, x);
    for (j = 1; j <= list.size; j++)
    {
        int y = element_at(&list, j);
        if (color[y] == gray)
        {
            cycle = 1; // t?n t?i chu tr?nh
            return;
        }
        if (color[y] == white)
            DFS(G, y);
    }
    color[x] = black;
}
int contains_cycle(Graph *G)
{
    int j;
    for (j = 1; j <= G->n; j++)
        color[j] = white;
    cycle = 0;
    for (j = 1; j <= G->n; j++)
        if (color[j] == white)
            DFS(G, j);
    return cycle;
}