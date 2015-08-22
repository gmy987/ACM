//注意剪枝以及各种操作应满足的条件
//常规BFS，利用队列。
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

bool vist[10000005];
struct Node{
    int x,minute;
};
int bfs( int n, int k)
{
    memset(vist,0,sizeof(vist));
    queue<Node> q;
    Node u;
    u.x = n,u.minute = 0;
    q.push(u);
    vist[n] = true;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if( u.x == k )
            return u.minute;
        Node v;
        if( !vist[u.x - 1 ] && u.x > 0)
        {
            v.x = u.x - 1;
            vist[v.x] = true;
            v.minute = u.minute + 1;
            q.push(v);
        }
        if( !vist[ u.x + 1 ] && u.x < 100000 )
        {
            v.x = u.x + 1;
            v.minute = u.minute + 1;
            q.push(v);
            vist[v.x] = true;
        }
        if( !vist[2*u.x] && u.x<=50000 )
        {
            v.x = 2*u.x;
            vist[v.x] = true;
            q.push(v);
            v.minute = u.minute + 1;
        }
    }
    return 0;
}
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        printf("%d\n",bfs(n,k));
    }
    return 0;

}
