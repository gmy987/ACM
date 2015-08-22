#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Node
{
    int num, step;
};

int vis[10000],a,b;
int bfs()
{
    Node u;
    u.num = a;
    u.step = 0;
    queue<Node> q;
    q.push(u);
    vis[u.num] = 1;
    while(!q.empty())
    {
        Node v;
        u = q.front();
        q.pop();
        if( u.num == b )
            return u.step;
        for( int i = 3 ; i >= 0 ; i-- )
        {
            int n = pow(10,i);
            int temp = u.num/n%10;
            if( temp ==  1 && !vis[u.num+8*n])
            {
                vis[u.num+8*n] = 1;
                v.num = u.num + 8*n;
                v.step = u.step + 1;
                q.push(v);
            }
            if( temp == 9 && !vis[u.num - 8*n])
            {
                v.num = u.num - 8*n;
                vis[v.num] = 1;
                v.step = u.step + 1;
                q.push(v);
            }
            if( temp!=1&&!vis[u.num-n])
            {
                v.num = u.num - n;
                vis[v.num] = 1;
                v.step = u.step + 1;
                q.push(v);
            }
            if( temp != 9 && !vis[u.num + n])
            {
                v.num = u.num + n;
                v.step  = u.step + 1;
                vis[v.num] = 1;
                q.push(v);
            }
            int c[5],temp2 = u.num;
            for( int j = 3; j >= 0 ; j-- )
            {
                int k = pow(10,j);
                c[j] = temp2/k;
                temp2 %= k;
            }
            if(i!=3)
            {
                int temp3 = c[i];
                c[i] = c[i+1];
                c[i+1] = temp3;
                temp3 = 0;
                for( int j = 3 ; j >= 0 ; j-- )
                    temp3+=c[j]*pow(10,j);
                if(!vis[temp3])
                {
                    v.num = temp3;
                    v.step = u.step + 1;
                    vis[v.num] = 1;
                    q.push(v);
                }
            }
            temp2 = u.num;
            for( int j = 3; j >= 0 ; j-- )
            {
                int k = pow(10,j);
                c[j] = temp2/k;
                temp2 %= k;
            }
            if(i!=0)
            {
                int temp3 = c[i];
                c[i] = c[i-1];
                c[i-1] = temp3;
                temp3 = 0;
                for( int j = 3 ; j >= 0 ; j-- )
                    temp3+=c[j]*pow(10,j);
                if(!vis[temp3])
                {
                    v.num = temp3;
                    v.step = u.step + 1;
                    vis[v.num] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&a,&b);
        printf("%d\n",bfs());
    }
}
