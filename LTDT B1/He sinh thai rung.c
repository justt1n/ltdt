#include <stdio.h>
#include "Ma tran dinh dinh.c"

int main()
{
	//khoi tao va doc du lieu
	freopen("hstr.txt", "r", stdin);
	Graph G;
	int n, m;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(&G, x, y);
	}
	int a, b;
	scanf("%d%d", &a, &b);
	List L1, L2;
	make_null(&L1);
	make_null(&L2);
	L1 = neighbors(&G, a);
	L2 = neighbors(&G, b);

	//xu ly
	List L;
	make_null(&L);
	for (int i = 0; i < L1.size; i++)
		if (member(&L2, L1.data[i]))
			push_back(&L, L1.data[i]);
	for (int i = 0; i < L.size; i++)
		printf("%d ", L.data[i]);
	if (L.size == 0)
		printf("KHONG CHUNG DOI THU");
}
