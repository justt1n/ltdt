#include <stdio.h>
#include "Ma tran dinh dinh.c"

int main()
{
    //khoi tao va doc du lieu
    freopen("hstr2.txt", "r", stdin);
    Graph G;
    int n;
    scanf("%d", &n);
    init_graph(&G, n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &G.A[i][j]);
    //printM(&G);
    int a, b;
    scanf("%d%d", &a, &b);
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (G.A[a][i] == 1 && G.A[b][i] == 1)
            count++;
    printf("%d", count);
    return 0;
}
