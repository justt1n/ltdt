#include<stdio.h>
#include"Ma tran dinh dinh.c"
#include"stack.c"
int strong = 0;
int num[100];
int min_num[100];
int on_stack[100];
int k = 1;
Stack S;
int min(int a, int b)
{
	if(a > b)
		 return b;
	return a;
}
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
		if(S.size == G->n)
			strong = 1;
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
	freopen("sc2.txt", "r", stdin); 
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	for(int i = 1; i <= G.n; i++)
	{
		num[i] = -1;
		min_num[i] = -1;
		on_stack[i] = -1;
	}
	make_null_stack(&S);
	strong_connect(&G, 1);
	if(strong == 1)
		printf("strong connected");
	else 
		printf("unconnected");
	return 0;
}
