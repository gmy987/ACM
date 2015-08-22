#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int vis[70],s[70],n,sum,len;
bool flag;
bool cmp( int a , int b )
{
    return a > b;
}

bool dfs( int index , int left , int remainNum )
{
    if( left == 0 )
    {
        remainNum--;
        if( remainNum == 0 ){
            flag = true;
            return true;
        }
        int i;
        for( i = 1 ; vis[i] ; i++ );
        vis[i] = 1;
        if(dfs(i,len-s[i],remainNum))
            return true;
        vis[i] = 0;
        remainNum++;
    }
    else
    {
        for( int i = index ; i < n ; i++ )
        {
            if(vis[i]) continue;
            if( i > 0 && ( !vis[i-1]&&s[i]==s[i-1]))
                continue;
            if(left>=s[i])
            {
                vis[i] = 1;
                if(dfs(i,left-s[i],remainNum))
                    return true;
                vis[i] = 0;
                if(left==s[i])
                    break;
            }
        }
    }
    return flag;
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        memset( vis , 0 , sizeof(vis));
        memset( s , 0 , sizeof(s));
        sum = 0;
        flag = false;
        for( int i = 0 ; i < n  ; i++ )
        {
            scanf("%d",&s[i]);
            sum += s[i];
        }
        sort( s , s + n , cmp );
        for( len = s[0] ; len <= sum/2 ; len++ )
        {
            memset( vis , 0 , sizeof(vis));
            vis[0] = 1;
            if( sum % len == 0 )
            {
                if(dfs( 0 , len - s[0] , sum/len ))
                {
                    printf("%d\n",len);
                    break;
                }
            }
        }
        if(!flag)
            printf("%d\n",sum);
    }
}
