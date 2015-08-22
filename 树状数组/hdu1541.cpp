#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
int n;
int c[32005];
int lowbit(int x)
{
    return x&(-x);
}
void update( int i , int val )
{
    while( i <= 32005 )
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}
int sum( int i )
{
    int sum = 0 ; 
    while( i > 0 )
    {
        sum+=c[i];
        i-=lowbit(i);
    }
    return sum;
}

int main()
{
    int level[15006];
    while(~scanf("%d",&n))
    {
        memset( level , 0 , sizeof(level) );
        memset( c , 0 , sizeof(c) );
        int x,y;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d%d",&x,&y);
            x++;
            level[sum(x)]++;
            update(x,1);
        }
        for( int i = 0 ; i < n ; i++ )
            printf("%d\n",level[i]);
        
    }
    return 0;
}
