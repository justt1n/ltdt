#include<stdio.h>
#include<Ma tran dinh dinh.c>
#include<queue.c>

void strong_connect(Graph *G, int x)
{
	num[x] = min_num [x] = k;
	k++;
	push(&S, x);
	on_stack[x] = 1;
	
	List list = neighbors(G, x);
	for(int i = 1;  i <= list.size; i++)
	{
		int y = element_at(&list, i);
		if(num[y] < 0)
		{
			strong_connect(G, y);
			min_num[x] = min(min_num[x], min_num[y]);
		}else if(on_stack[y])
			min_num[x] = min(min_num[x], num[y]);
	}
	if(num[x] == min_num[x])
	{
		chuTrinh = 1;
		int w;
		do{
			w = top(&S);
			pop(&S);
			on_stack[w] = 0;
		}while(w != x);
	}
}

int main()
{
	freopen("dt.txt", "r", stdin); 
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	strong_connect(&G, 1);
	return 0;
}
