#include<stdio.h>
#include<string.h>
#define INF 0x1f1f1f1f
#define MAX 102
#define MAXM 20008

int dist[MAX];

struct Edge{            //边结构体定义 
	int u, v, w;//w为边权，这与之前的链表不一样 
	Edge(){}
	Edge(int a, int b, int c):u(a), v(b), w(c){}
}edge[MAXM];

int bellman_ford(int n, int m, int s)  //n个点、m条边、s为起点 
{
	memset(dist, 0x1f, sizeof(dist));   //初始化距离很大 
	dist[s] = 0;
	int i, j, u, v, f;
	for (i = 1; i < n; ++i)        //迭代 n - 1 次 
   {
		f = 0;
	   for (j = 0; j < m; ++j)
      {
			u = edge[j].u;
			v = edge[j].v;
	      if (dist[v] > dist[u] + edge[j].w) // 松弛操作 
         {
					dist[v] = dist[u] + edge[j].w;
               f = 1;
			}
	   }
	   if (!f) return 1;         //如果其中一次迭代没改变，停止
	}
	for(j = 0; j < m; ++j)    //再进行一次迭代 
   {
		u = edge[j].u;
		v = edge[j].v;
		if (dist[v] > dist[u] + edge[j].w)   //若还能松弛, 则存在负环 
		   return -1;                   //存在负环返回 -1 
   }
   return 1;      //没有负环返回 1 
}

int main()
{
	int i, j, a, b, c, n, m;
	while (scanf("%d%d", &n, &m) && n != 0)
   {
      j = 0;
      for (i = 0; i < m; ++i)
      {
         scanf("%d%d%d", &a, &b, &c);
         edge[j++] = Edge(a, b, c);
         edge[j++] = Edge(b, a, c);
      }
	   if (bellman_ford(n, j, 1) == 1)
	     printf("%d\n", dist[n]);
	}
	return 0;
}
