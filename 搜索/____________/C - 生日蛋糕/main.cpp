#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n,m,s,ans;
bool flag;
void dfs( int leftv , int level , int s ,int r , int h )
{
    if( s + 2*leftv/r >= ans ) return;
    if( leftv < (level+1)*(level+1)*level*level/4) return;
    if( level == 0 )
    {
        if( leftv == 0 )
            ans = s;
        return;
    }
    for( int i = r - 1 ; i >= level ; i -- )
    {
        if( level == m )
            s = i*i;
        for( int j = h - 1 ; j >= level ; j -- )
            dfs ( leftv - i * i * j , level - 1 , s + 2*i*j , i , j );
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    ans = 100000000;
    dfs( n , m , 0 , 100 , 10000 );
    if( ans == 100000000 )
        printf("0\n");
    else
        printf("%d\n",ans);
}
