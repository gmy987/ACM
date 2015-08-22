#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAXN 150

using namespace std;
int cnt[MAXN];
int a,b;
int n,k;
vector<int> edge[MAXN];
int dfs( int x)
{
    for( int i = 0 ; i < edge[x].size() ; i++ )
    {
        cnt[x] += dfs(edge[x][i])+1;
    }
    return cnt[x];
}


int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        memset( cnt , 0 , sizeof(cnt) );
        for( int i = 0 ; i < n-1 ; i++ )
        {
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
        }
        dfs(1);
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
            if(cnt[i]==k) ans++;
        printf("%d\n",ans);
        for( int i = 0 ; i <= n+1 ; i++ )
            edge[i].clear();
    }
    return 0;
}
