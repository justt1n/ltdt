#include "Ma tran dinh dinh.c"

int mark[100]; //mang danh dau
int pi[100];   //chieu dai tu dinh xuat phat den u
int p[100];    //dinh truoc u

void dijkstra(Graph *pG, int s)
{
    int i, j, k;
    for (i = 1; i <= pG->n; i++)
    {
        pi[i] = 99999;
        mark[i] = 0;
    }
    pi[s] = 0;
    p[s] = -1;

    for (k = 1; k <= pG->n; k++)
    {
        int min_pi = 99999;
        for (j = 1; j <= pG->n; j++)
        {
            if (mark[j] == 0 && pi[j] < min_pi)
            {
                min_pi = pi[j];
                i = j;
            }
        }
        mark[i] = 1;
        for (int j = 1; j <= pG->n; j++)
            if (pG->A[i][j] != 0 && mark[j] == 0)
                if (pi[i] + pG->A[i][j] < pi[j])
                {
                    pi[j] = pi[i] + pG->A[i][j];
                    p[j] = i;
                }
    }
}