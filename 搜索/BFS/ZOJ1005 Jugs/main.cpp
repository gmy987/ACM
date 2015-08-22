#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Node
{
    int a, b , step,op;
}pre[1005][1005];

int ca,cb,n,vis[1005][1005];

void print( Node u , int step )
{
    if(step == 0)
    {
        return;
    }
    else
        print(pre[u.a][u.b],step-1);
    switch(u.op)
    {
        case 1 : printf("fill A\n"); break;
        case 2 : printf("fill B\n"); break;
        case 3 : printf("empty A\n"); break;
        case 4 : printf("empty B\n"); break;
        case 5 : printf("pour A B\n"); break;
        case 6 : printf("pour B A\n"); break;
    }
}
void bfs()
{
    memset(vis,0,sizeof(vis));
    Node u;
    queue<Node> q;
    u.a = 0;
    u.b = 0;
    u.step = 0;
    u.op = 0;
    q.push(u);
    while(!q.empty())
    {
        Node v;
        u = q.front();
        q.pop();
        if( u.b == n )
        {
            print(u,u.step);
            return;
        }
        //满A
        if(u.a==0&&!vis[ca][u.b])
        {
            v.a = ca;
            v.b = u.b;
            v.op = 1;
            v.step = u.step+1;
            vis[v.a][v.b] = 1;
            pre[v.a][v.b] = u;
            q.push(v);
        }
        //满B
        if(u.b==0&&!vis[u.a][cb])
        {
            v.b = cb;
            v.a = u.a;
            v.step = u.step+1;
            v.op = 2;
            vis[v.a][v.b] = 1;
            pre[v.a][v.b] = u;
            q.push(v);
        }
        //空A
        if(u.a&&!vis[0][u.b])
        {
            v.b = u.b;
            v.a = 0;
            v.step = u.step+1;
            v.op = 3;
            vis[v.a][v.b] = 1;
            pre[v.a][v.b] = u;
            q.push(v);
        }
        //空B
        if(u.b&&!vis[u.a][0])
        {
            v.a = u.a;
            v.b = 0;
            v.step = u.step+1;
            v.op = 4;
            vis[v.a][v.b] = 1;
            pre[v.a][v.b] = u;
            q.push(v);
        }
        //A倒B
        if(u.a&&u.b!=cb)
        {
            if(u.a>=cb-u.b)
            {
                v.a = u.a-(cb-u.b);
                v.b = cb;
                if(!vis[v.a][v.b])
                {
                    v.step = u.step+1;
                    v.op = 5;
                    vis[v.a][v.b] = 1;
                    pre[v.a][v.b] = u;
                    q.push(v);
                }
            }
            else if( u.a < cb - u.b )
            {
                v.a = 0;
                v.b = u.b + u.a;
                if(!vis[v.a][v.b])
                {
                    v.step = u.step+1;
                    v.op = 5;
                    vis[v.a][v.b] = 1;
                    pre[v.a][v.b] = u;
                    q.push(v);
                }
            }
        }
        if(u.b&&u.a!=ca)
        {
            if(u.b>=ca-u.a)
            {
                v.b = u.b-(ca-u.a);
                v.a = ca;
                if(!vis[v.a][v.b])
                {
                    v.step = u.step+1;
                    v.op = 6;
                    vis[v.a][v.b] = 1;
                    pre[v.a][v.b] = u;
                    q.push(v);
                }
            }
            else if( u.b < ca - u.a )
            {
                v.b = 0;
                v.a = u.a + u.b;
                if(!vis[v.a][v.b])
                {
                    v.step = u.step+1;
                    v.op = 6;
                    vis[v.a][v.b] = 1;
                    pre[v.a][v.b] = u;
                    q.push(v);
                }
            }
        }
    }
    return;
}

int main()
{
    while(~scanf("%d%d%d",&ca,&cb,&n))
    {
        bfs();
        printf("success\n");
    }
}
