#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 100005
int in[maxn];
int fa[maxn];
bool isfa[maxn];
int odd[maxn];
int ans;
void init()
{
	memset(in, 0, sizeof(in));
	memset(isfa, false, sizeof(isfa));
	memset(odd, 0, sizeof(odd));
	ans = 0;

	for (int t = 0; t < maxn; t++)
	{
		fa[t] = t;
	}
}

int findfa(int a)
{
	if (fa[a] == a)
	{
		return a;
	}

	a = findfa(fa[a]);
	return a;
}

int main()
{
	int n, m;
	int a, b;

	while (scanf("%d%d", &n, &m) != EOF)
	{
		init();

		for (int t = 0; t < m; t++)
		{
			scanf("%d%d", &a, &b);

			if (a > b)
			{
				swap(a, b);
			}

			in[a]++;
			in[b]++;
			fa[findfa(b)] = findfa(a);
		}

		for (int t = 1; t <= n; t++)
		{
			int fat = findfa(t);

			if (!isfa[fat])
			{
				isfa[fat] = 1;
			}
			if (in[t] % 2 == 1)
			{
				odd[fat]++;
			}
		}

		for (int t = 1; t <= n; t++)
		{
			if (isfa[t] && in[t])
			{
				if (odd[t] == 0)
				{
					ans++;
				}
				else
				{
					ans += odd[t] / 2;
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
