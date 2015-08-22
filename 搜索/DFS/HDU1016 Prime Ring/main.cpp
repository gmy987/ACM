#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
int vis[25],n,map[25];

bool isPrime( int n )
{
    if( n == 1 || !(n%2) ) return false;
    if( n == 2 ) return true;
    for( int i =3 ; i <= sqrt(n) ; i+=2 )
        if(!(n%i))  return false;
    return true;
}
void dfs( int step )
{
    if( step == n && isPrime(1+map[n-1]))
    {
        for( int i = 0 ; i < step ; i++ )
        {
            if( i == 0 )
                printf("%d",map[i]);
            else
                printf(" %d",map[i]);
        }
        printf("\n");
        return;
    }
    for( int i =2 ; i<=n ; i++ )
    {
        if( !vis[i] && isPrime(map[step-1]+i))
        {
            map[step] = i;
            vis[i] = 1;
            dfs( step + 1 );
            vis[i] = 0;
        }
    }
}
int main()
{
    int cnt = 0;
    while(~scanf("%d",&n))
    {
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        cnt++;
        printf("Case %d:\n",cnt);
        //vis[1] = 1;
        map[0] = 1;
        //cout<<isPrime(n)<<endl;
        dfs(1);
        printf("\n");
    }
}
