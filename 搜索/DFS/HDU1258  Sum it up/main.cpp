#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int mem[1000],a[100],t,n,flag;
bool cmp( int a , int b )
{
    return a>b;
}
void dfs( int number , int sum , int result )
{
    if(sum>t) return;
    if(sum==t)
    {
        flag = true;
        for( int i = 0; i < result ; i++ )
        {
            if(!i) printf("%d",mem[i]);
            else
                printf("+%d",mem[i]);
        }
        printf("\n");
        return;
    }
    //cout<<t<<endl;
    //cout<<sum<<endl;
    for( int i = number ; i < n ; i++ )
    {
        mem[result] = a[i];
        //cout<<sum<<endl;
        dfs( i + 1 , sum + a[i] , result + 1 );
        while( i+1 < n && a[i] == a[i+1])
            i++;
    }
}
int main()
{
    while(~scanf("%d%d",&t,&n))
    {
        if(!t&&!n) break;
        memset(mem,0,sizeof(mem));
        memset(a,0,sizeof( a ));
        //cout<<t<<endl;
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&a[i]);
        sort( a , a + n , cmp );
        flag = false;
        printf("Sums of %d:\n",t);
        dfs(0,0,0);
        if( !flag )
            printf("NONE\n");

    }
    return 0;
}
