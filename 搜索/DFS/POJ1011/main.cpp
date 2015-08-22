#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int sticks[70],n,sum,flag,vis[70],num,i;
bool cmp ( int a , int b )
{
    return a > b;
}
//cur为当前试取的棍子序号,left为要拼成一根完整的棍子还需要的长度,t初值为所有棍子总长度
bool dfs( int cur , int left , int t )
{
    if( left == 0 )
    {
        t-=i;
        if(t==0) return true;
        for(cur = 0 ; vis[cur] ; cur++ )
        vis[cur] = 1;
        if(dfs(cur+1,i-sticks[cur],t))
            return true;
        vis[cur] = 0;
        t+=i;
    }
    else
    {
        for( int j = cur ; j < n ; j++ )
        {
            if( j > 0 && sticks[j] == sticks[j-1] && !vis[j-1])
                continue;
            if( !vis[j] && left >= sticks[j] )
            {
                left-=sticks[j];
                vis[j] = 1;
                if( dfs( j , left , t ))
                    return true;
                left+=sticks[j];
                vis[j] = 0;
                if(sticks[j]==left)
                    break;
            }
        }
    }
    return false;
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        flag = false;
        memset(vis,0,sizeof(vis));
        memset(sticks,0,sizeof(sticks));
        for( int i = 0 ; i < n  ; i++ )
        {
            scanf("%d",&sticks[i]);
            sum+=sticks[i];
        }
        for( int i = 0 ; i < n ; i++ )
            cout<<sticks[i]<<" ";
        cout<<endl;
        sort( sticks , sticks + n);
        for( int i = 0 ; i < n ; i++ )
            cout<<sticks[i]<<" ";
        cout<<endl;
/*        for( i = sticks[0] ; i <= sum/2 ; i++ )
        {
            if(sum%i==0)
            {
                if(dfs(0,i-sticks[0],sum))
                {
                    flag = true;
                    printf("%d\n",i);
                    break;
                }
            }
        }
        if(!flag)
            printf("%d\n",sum);*/
    }
}
