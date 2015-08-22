#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 250

using namespace std;
int n,m;
bool board[MAXN][MAXN];
bool vis[MAXN];
int match[MAXN];
bool flag;
void dfsMap(int x,int val)
{
    match[x] = val;
    for( int i = 1 ; i <= n ; i++ )
    {
        if(board[x][i])
        {
            if(!match[i])
            {
                dfsMap(i,-val);
                if(!flag)
                    return;
            }
            else if( match[i] == val )
            {
                flag = false;
                return;
            }
        }
    }
}
bool dfs( int k )
{
    int t;
    for( int i = 1 ; i <= n ; i++ )
    {
        if(!vis[i] && board[k][i] )
        {
            vis[i] = 1;
            t = match[i];
            match[i] = k;
            if( t == -1 || dfs(t) )
                return true;
            match[i] = t;
        }
    }
    return false;
}


int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset( board , 0 , sizeof(board) );
        memset( match , 0 , sizeof(match) );
        int a,b;
        flag = true;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            board[a][b] = board[b][a] = 1;
        }
        for( int i = 1 ; i <=n ; i++ )
        {
            if(!match[i])
                dfsMap(i,1);
        }
        if(!flag)
        {
            printf("No\n");
        }
        else{
            memset( match , -1 , sizeof(match) );
            int ans = 0;
            for( int i = 1 ; i <= n ; i++ )
            {
                memset(vis,0,sizeof(vis));
                if(dfs(i))
                    ans++;
            }
            printf("%d\n",ans/2);
        }
    }
    return 0;
}

