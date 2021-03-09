//
// Created by t1n on 2/18/21.
//
#include <stdio.h>
#define MAX_M 500

typedef struct
{
    int G[MAX_M][MAX_M];
    int a;
} Graph;

void initMGBM(Graph *pG)
{
    for (int i = 1; i <= pG->a; i++)
        for (int j = 1; j <= pG->a; j++)
            pG->G[i][j] = 0;
}

void addEdgebyM(Graph *pG)
{
    for (int i = 1; i <= pG->a; i++)
        for (int j = 1; j <= pG->a; j++)
            scanf("%d", &pG->G[i][j]);
}

int countMailRe(Graph *pG, int e)
{
    int cM = 0;
    for (int i = 1; i <= pG->a; i++)
        cM += pG->G[i][e];
    return cM;
}

int countMailSe(Graph *pG, int e)
{
    int cM = 0;
    for (int i = 1; i <= pG->a; i++)
        cM += pG->G[e][i];
    return cM;
}

void addEdge(Graph *pG, int send, int re)
{
    pG->G[send][re]++;
}

int main()
{
    //freopen("mail.txt", "r", stdin);
    Graph G;
    int m;
    scanf("%d%d", &G.a, &m);
    initMGBM(&G);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(&G, a, b);
    }
    //addEdgebyM(&G);
    int maxN = 0, maxMail = 0;
    for (int i = 1; i <= G.a; i++)
    {
        int tmp = countMailSe(&G, i);
        //printf("%d\n", tmp);
        if (tmp > maxMail)
        {
            maxMail = tmp;
            maxN = i;
        }
    }
    // for (int i = 1; i <= G.a; i++)
    // {
    //     for (int j = 1; j <= G.a; j++)
    //     {
    //         printf("%d ", G.G[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d has sent %d email(s).", maxN, maxMail);
    return 0;
}
