#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxm 90002 //������10000*2��
#define maxn 302 //����
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
void initg()//��ʼ�� 
{
    size = 0;//��ʾ�ߵĸ��� 
    memset(head,-1,sizeof(head));
}
void add(int u,int v,int d)//�ӱ� 
{
    edge[size].v = v, edge[size].d = d, edge[size].next = head[u];//edge[size] = Edge(v,d,head[u]);
    head[u] = size++;//head[u]�浱ǰ�ߵ��±� 
}
struct V
{
    int id;
    int val;
}hp[maxn*3];
bool cmp(const V &a,const V &b)//�ѵıȽϺ����������ʵ�ʱȽ��෴ 
{
    return a.val > b.val;
}
void Dijkstra(int s,int nn)//sԭ�㣬nnͼ�е���
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

