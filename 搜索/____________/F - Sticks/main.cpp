#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int num[65],n,sum,len,vis[65];
bool cmp ( int a , int b )
{
    return a > b;
}
bool dfs ( int index , int leftLen , int leftNum )
{
    if( leftLen == 0 )
    {
        leftNum--;
        if( leftNum == 0 )
            return true;
        int i;
        for( i = 1 ; vis[i] ; i++ );
        vis[i] = 1;
        if(dfs(i,len - num[i] , leftNum ))
            return true;
        vis[i] = 0;
        leftNum++;
    }
    else
    {
        for( int i = index ; i < n ; i++ )
        {
            if(vis[i])
                continue;
            if( i > 0 && (num[i]==num[i-1]&&!vis[i-1]))
                continue;
            if( leftLen >= num[i])
            {
                vis[i] = 1;
                if( dfs(i,leftLen - num[i] , leftNum ))
                    return true;
                vis[i] = 0;
                if( leftLen == num[i])
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
        sum = 0;
        memset(num,0,sizeof(num));
        for( int i = 0 ; i < n ; i ++ ){
            scanf("%d",&num[i]);
            sum += num[i];
        }
        sort( num , num + n , cmp );
        bool flag = false;
        for( len = num[0] ; len <= sum/2 ; len++ )
        {
            memset(vis,0,sizeof(vis));
            vis[0] = 1;
            if( sum % len == 0 )
            {
                if( dfs ( 0 , len - num[0] , sum/len ))
                {
                    flag = true;
                    printf("%d\n",len);
                    break;
                }
            }
        }
        if(!flag)
            printf("%d\n",sum);
    }
}
