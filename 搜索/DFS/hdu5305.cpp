#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int board[10][10];
int n,m,u,v;
int flag1[10],flag2[10];
int ans;
vector<int> vect[10];
void dfs( int x , int y )
{
    if( flag1[x]>vect[x].size()/2||flag2[x]>vect[x].size()/2) return;
    if( x > n && flag1[x] == flag2[x] )
        ans++;
    else if( y > n )
    {
        if( flag1[x] != flag2[x] )
            return;
        else dfs(x+1,x+2);
    }
    else if( board[x][y] )
    {
        flag1[x]++,flag1[y]++;
        dfs(x,y+1);
        flag1[x]--,flag1[y]--;
        flag2[x]++,flag2[y]++;
        dfs(x,y+1);
        flag2[x]--,flag2[y]--;
    }
    else dfs(x,y+1);

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(board,0,sizeof(board));
        memset(flag1,0,sizeof(flag1));
        memset(flag2,0,sizeof(flag2));
        ans = 0;
        for( int i = 0 ; i < 10 ; i++ )
            vect[i].clear();
        for( int i = 0 ; i < m ; i++ )
        {
            scanf("%d%d",&u,&v);
            board[u][v] = board[v][u] = 1;
            vect[u].push_back(v);
            vect[v].push_back(u);
        }
        bool f = true;
        for( int i = 1 ; i<=n ; i++ )
            if(vect[i].size()&1)
            {
                printf("0\n");
                f = false;
                break;
            }
        if(!f)
            continue;
        dfs(1,2);
        printf("%d\n",ans);
    }
    return 0;
}
