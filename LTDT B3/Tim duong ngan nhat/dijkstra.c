#include "Ma tran dinh dinh.c"

int mark[100]; //mang danh dau
int pi[100];   //chieu dai tu dinh xuat phat den u
int p[100];    //dinh truoc u

void dijkstra(Graph *pG, int s)
{
    for (int i = 1; i <= pG->n; i++)
    {
        pi[i] = 999;
        mark[i] = 0;
    }
    pi[s] = 0;
    p[s] = -1;
    int k;
    for (int i = 1; i < pG->n; i++) //lap n - 1 lan
    {
        int min_pi = 999;
        for (int j = 1; j <= pG->n; i++)
        {
            if (!mark[j] && pi[j] < min_pi)
            {
                min_pi = pi[j];
                k = j;
            }
        }
        mark[k] = 1;
        for (int j = 1; j <= pG->n; j++)
            if (pG->A[k][j] != 0 && !mark[j])
                if (pi[k] + pG->A[k][j] < pi[j])
                {
                    pi[j] = pi[k] + pG->A[k][j];
                    p[j] = k;
                }
    }
}