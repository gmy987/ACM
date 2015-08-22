#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 1005
int map[maxn][maxn];
int in[maxn];
int q[maxn];
int ans[maxn];
bool cmp(const int a, const int b)
{
	return a > b;
}
int main()
{
	int n, m, d1, d2;

	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(map, 0, sizeof(map));
		memset(in, 0, sizeof(in));
		memset(q, 0, sizeof(q));

		for (int t = 0; t < m; t++)
		{
			scanf("%d%d", &d1, &d2);

			if (map[d1][d2] == 0)
			{
				in[d2]++;
				map[d1][d2] = 1;
			}

		}

		int ip = 0;

		for (int t = 1; t <= n; t++)
		{
			if (in[t] == 0)
			{
				q[ip++] = t;
			}
		}

		int mov = 0;
		make_heap(q, q + ip, cmp);

		while (mov != n)
		{
			ans[mov] = q[0];
			pop_heap(q, q + ip, cmp);
			ip--;

			//printf("mov %d ans %d\n",mov,ans[mov]);
			for (int t = 1; t <= n; t++)
			{
				if (map[ans[mov]][t] != 0)
				{
					in[t]--;

					if (in[t] == 0)
					{
						q[ip++] = t;
						push_heap(q, q + ip, cmp);
					}
				}
			}

			mov++;
		}

		for (int t = 0; t < n - 1; t++)
		{
			printf("%d ", ans[t]);
		}

		printf("%d\n", ans[n - 1]);

	}

	return 0;
}
