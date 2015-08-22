#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <string>
#define mem(a) memset(a,0,sizeof(a));

using namespace std;

int vist[110][110];
struct Node{
    int a,b,step;
    string op;
}pre[110][110];
int a,b;
bool flag;
void print(Node u,int step)
{
    if( step == 1)
    {
        printf("%s\n",u.op.c_str());
        return;
    }
    print( pre[u.a][u.b],step-1);
    printf("%s\n",u.op.c_str());

}
int gcd(int a,int b)
{
    if( b == 0 )
        return a;
    return gcd(b,a%b);
}

void bfs( int c )
{
    mem(vist);
    Node u;
    queue<Node> q;
    u.a = 0;
    u.b = 0;
    u.step = 0;
    vist[0][0] = 1;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if(u.a==c||u.b==c)
        {
            flag = true;
            printf("%d\n",u.step);
            print(u,u.step);
            return;
        }
        Node v;
        v = u;
        if( u.a != a )
        {
            v.a = a;
            if(!vist[v.a][v.b])
            {
                v.step++;
                v.op = "FILL(1)";
                pre[v.a][v.b] = u;
                q.push(v);
                vist[v.a][v.b] = 1;
            }
        }
        v = u;
        if( u.b != b )
        {
            v.b = b;
            if(!vist[v.a][v.b])
            {
                v.step++;
                v.op = "FILL(2)";
                pre[v.a][v.b] = u;
                q.push(v);
                vist[v.a][v.b] = 1;
            }
        }
        v = u;
        if( u.a )
        {
            v.a = 0;
            if(!vist[v.a][v.b])
            {
                v.step ++;
                v.op = "DROP(1)";
                pre[v.a][v.b] = u;
                q.push(v);
                vist[v.a][v.b] = 1;
            }
        }
        v = u;
        if(u.b)
        {
            v.a = u.a;
            v.b = 0;
            if(!vist[v.a][v.b])
            {
                v.step++;
                v.op = "DROP(2)";
                pre[v.a][v.b] = u;
                q.push(v);
                vist[v.a][v.b] = 1;
            }
        }
        v = u;
        if(u.a)
        {
            if(u.a>=b-u.b&&u.b!=b)
            {
                v.b = b;
                v.a = u.a - (b-u.b);
            }
            else if( u .a < b - u.b )
            {
                v.a = 0;
                v.b = u.b + u.a;
            }
            if(!vist[v.a][v.b])
            {
                v.step++;
                v.op = "POUR(1,2)";
                pre[v.a][v.b] = u;
                vist[v.a][v.b] =1;
                q.push(v);
            }
        }
        v = u;
        if(u.b)
        {
            if(u.b>=a-u.a&&u.a!=a)
            {
                v.a = a;
                v.b = u.b - (a-u.a);
            }
            else if( u.b < a - u.a )
            {
                v.b = 0;
                v.a = u.a + u.b;
            }
            if(!vist[v.a][v.b])
            {
                v.step++;
                v.op = "POUR(2,1)";
                pre[v.a][v.b] = u;
                vist[v.a][v.b] = 1;
                q.push(v);
            }
        }
    }
    return;
}

int main()
{
    int c;
    scanf("%d%d%d",&a,&b,&c);
    if( a < c && b < c )
        printf("impossible\n");
    else if(c%gcd(a,b)!=0)
        printf("impossible\n");
    else
        bfs(c);
    return 0;
}
