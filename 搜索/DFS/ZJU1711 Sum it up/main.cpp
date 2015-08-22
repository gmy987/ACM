#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int t,n,num[15],mem[15];
bool flag;
bool cmp ( int a , int b )
{
    return a > b;
}
void dfs( int sum , int cnt , int number )
{
    if( sum > t )
        return;
    if( sum == t )
    {
        flag = true;
        for ( int i = 0 ; i < cnt ; i++ )
        {
            if(!i) printf("%d",mem[i]);
            else
                printf("+%d",mem[i]);
        }
        printf("\n");
        return;
    }
    for( int i = number ; i < n ; i++ )
    {
        mem[cnt] = num[i];
        dfs( sum + num[i] , cnt + 1 , i+1 );
        while( i < n-1 && num[i] == num[i+1])
            i++;
    }
}

int main()
{
    while(~scanf("%d%d",&t,&n))
    {
        memset( num , 0 , sizeof( num ));
        memset( mem , 0 , sizeof( mem ));
        if(!t&&!n) break;
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&num[i]);
        sort ( num , num + n , cmp );
        flag = false;
        printf("Sums of %d:\n",t);
        dfs( 0 , 0 , 0 );
        if(!flag )
            printf("NONE\n");
    }
}
