#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxm 90002 //边数（10000*2）
#define maxn 302 //点数
int n,m;
int size;
int head[maxn];
int flag[maxn];
int dist[maxn];
struct Edge
{
    int v,next;
    int d;
    //Edge(){}
    //Edge(int a,int b,int c):v(a),d(b),next(c){}
}edge[maxm];
void initg()//初始化 
{
    size = 0;//表示边的个数 
    memset(head,-1,sizeof(head));
}
void add(int u,int v,int d)//加边 
{
    edge[size].v = v, edge[size].d = d, edge[size].next = head[u];//edge[size] = Edge(v,d,head[u]);
    head[u] = size++;//head[u]存当前边的下标 
}
struct V
{
    int id;
    int val;
}hp[maxn*3];
bool cmp(const V &a,const V &b)//堆的比较函数，这个与实际比较相反 
{
    return a.val > b.val;
}
void Dijkstra(int s,int nn)//s原点，nn图中点数
{
    int i,j,tt,tmp_id,v,len;
    memset(dist,-1,sizeof(dist));
    memset(flag,0,sizeof(flag));
    dist[s] = 0;
    tt = 0;
    hp[tt].id = s;
    hp[tt++].val = 0;
    push_heap(hp,hp+tt,cmp);
    for (i=0;i<nn;i++)
    {
        do
        {
            if (tt == 0)
                return;
            pop_heap(hp,hp+tt,cmp);
            tmp_id = hp[tt-1].id;
            tt--;
        }
        while (flag[tmp_id]!=0);
        flag[tmp_id] = 1;
        for (j=head[tmp_id];j!=-1;j=edge[j].next)
        {
            v = edge[j].v;
            if (flag[v]==0 && (dist[v] == -1 ||dist[v] > dist[tmp_id] + edge[j].d))
            {
                dist[v] = dist[tmp_id] + edge[j].d;
                hp[tt].id = v;
                hp[tt++].val = dist[v];
                push_heap(hp,hp+tt,cmp);
            }
        }
    }
    return;
}
int main()
{
    int u, v, d, i, j, ans, vel, T;
    scanf ("%d", &T); 
    while (T--)
    {
          initg();
          scanf ("%d%d", &n, &m);
          while (m--)
          {
                scanf ("%d%d%d", &u, &v, &d);
                add(u, v, d);
                add(v, u, d);
          }
          Dijkstra(1, n);
          ans = dist[n];
          printf ("%d\n", ans);
    }
    return 0;
}

