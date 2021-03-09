#include<stdio.h>
#include"Ma tran dinh dinh.c""

int main()
{
	freopen("bln2.txt", "r", stdin);
	Graph G;
	int n, m;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(&G, x, y);
	}
	printM(&G);
}
