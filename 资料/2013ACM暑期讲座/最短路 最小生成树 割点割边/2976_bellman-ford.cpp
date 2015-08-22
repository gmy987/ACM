#include<stdio.h>
#include<string.h>
#define INF 0x1f1f1f1f
#define MAX 102
#define MAXM 20008

int dist[MAX];

struct Edge{            //�߽ṹ�嶨�� 
	int u, v, w;//wΪ��Ȩ������֮ǰ������һ�� 
	Edge(){}
	Edge(int a, int b, int c):u(a), v(b), w(c){}
}edge[MAXM];

int bellman_ford(int n, int m, int s)  //n���㡢m���ߡ�sΪ��� 
{
	memset(dist, 0x1f, sizeof(dist));   //��ʼ������ܴ� 
	dist[s] = 0;
	int i, j, u, v, f;
	for (i = 1; i < n; ++i)        //���� n - 1 �� 
   {
		f = 0;
	   for (j = 0; j < m; ++j)
      {
			u = edge[j].u;
			v = edge[j].v;
	      if (dist[v] > dist[u] + edge[j].w) // �ɳڲ��� 
         {
					dist[v] = dist[u] + edge[j].w;
               f = 1;
			}
	   }
	   if (!f) return 1;         //�������һ�ε���û�ı䣬ֹͣ
	}
	for(j = 0; j < m; ++j)    //�ٽ���һ�ε��� 
   {
		u = edge[j].u;
		v = edge[j].v;
		if (dist[v] > dist[u] + edge[j].w)   //�������ɳ�, ����ڸ��� 
		   return -1;                   //���ڸ������� -1 
   }
   return 1;      //û�и������� 1 
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
