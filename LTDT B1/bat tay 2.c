#include "Ma tran dinh cung.c"

int main()
{
    freopen("bt.txt", "r", stdin);
    Graph G;
    int n, m;
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (int e = 1; e <= m; e++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add_edge(&G, e, x, y);
    }
    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = degree(&G, i);
        if (x > max)
            max = x;
    }
    printf("%d", max);
    return 0;
}
