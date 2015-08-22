#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;
char a[1000][1000];
int vis[1000];
bool flag;
void dfs( int j , int len )
{
    if( a[j][strlen(a[j])-1] == 'm')
    {
        //cout<<a[j]<<endl;
        //cout<<a[j][strlen(a[j]) - 1]<<endl;
        flag = true;
        return;
    }
    if(flag)  return;
    for ( int i = 0 ; i < len ; i++ )
    {
        int b = strlen(a[j])-1;
        if( a[i][0] == a[j][b] && !vis[i] )
        {
            vis[i] = 1;
            dfs( i , len );
            if(flag) return;
            vis[i] = 0;
        }
    }
}
int main()
{
    while(~scanf("%s",a[0]))
    {
        if(a[0][0]=='0')
        {
            printf("No.\n");
            continue;
        }
        memset(vis,0,sizeof(vis));
        //memset(a,0,sizeof(a));
        //cout<<a[0]<<endl;
        int i = 1;
        while(~scanf("%s",a[i++]))
            if(a[i-1][0]=='0')
                break;
        i--;
        flag = false;
        for( int j = 0 ; j < i ; j++ )
        {
            if(a[j][0]=='b'){
                //cout<<a[j]<<endl;
                vis[j] = 1;
                dfs(j,i);
                if(flag)
                    break;
            }
        }
        if(flag)
            printf("Yes.\n");
        else
            printf("No.\n");
    }
    return 0;
}
