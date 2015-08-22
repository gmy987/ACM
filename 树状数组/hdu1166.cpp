#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int n;
int c[50005];
int lowbit( int x )
{
    return x&(-x);
}
void update( int i , int val )
{
    while( i <= n )
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}
int sum( int i )
{
    int sum = 0;
    while( i > 0 )
    {
        sum+=c[i];
        i-=lowbit(i);
    }
    return sum;
}


int main()
{
    int t;
    int cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",cas++);
        memset( c , 0 , sizeof(c) );
        scanf("%d",&n);
        int a,c;
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&a);
            update( i , a );
        }
        char b[10];
        scanf("%s",b);
        while(b[0]!='E')
        {
            scanf("%d%d",&a,&c);
            if(b[0]=='Q')
                printf("%d\n",sum(c)-sum(a-1));
            else if( b[0] == 'A' )
                update(a,c);
            else
                update(a,-c);
            scanf("%s",b);
        }
    }
    return 0;
}
