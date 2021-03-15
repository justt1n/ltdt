int mark[100]; // ??nh u ?? ???c ??nh d?u hay ch?a
int pi[100];   // chi?u d?i ???ng ?i ng?n nh?t t? ??nh xu?t ph?t ??n u
int p[100];    // ??nh tr??c ??nh u
void Dijkstra(Graph *G, int s)
{ // s l? ??nh xu?t ph?t
    int i, j, it;
    for (i = 1; i <= G->n; i++)
    {
        pi[i] = 999;
        mark[i] = 0;
    }
    pi[s] = 0;
    p[s] = -1; // ??nh li?n tr??c ??nh xu?t ph?t l? ??nh -1
    for (it = 1; it < G->n; it++)
    { // l?p n - 1 l?n
        int min_pi = 999;
        for (j = 1; j <= G->n; j++)
        {
            // t?m ??nh ch?a ???c duy?t v? c? pi nh? nh?t
            if (!mark[j] && pi[j] < min_pi)
            {
                min_pi = pi[j];
                i = j; // c?p nh?t ??nh ?? l? ??nh i
            }
        }
        mark[i] = 1;                // ??nh d?u i ?? ???c duy?t
        for (j = 1; j <= G->n; j++) // h? h?ng c?a i v? ch?a ?c duy?t
            if (G->A[i][j] != 0 && !mark[j])
            {
                if (pi[i] + G->A[i][j] < pi[j])
                {
                    pi[j] = pi[i] + G->A[i][j];
                    p[j] = i;
                }
            }
    }
}