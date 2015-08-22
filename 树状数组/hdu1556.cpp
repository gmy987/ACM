#include <cstdio>
#include<cstring>
#include <iostream>
#define MAXN 100005
using namespace std;
int n;
int c[MAXN];
int lowbit(int x)
{
    return x&(-x);
}
void update(int i,int val)
{
    while(i<=n)
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=c[i];
        i-=lowbit(i);
    }
    return sum;
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        memset( c , 0 , sizeof(c));
        int a,b;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%d%d",&a,&b);
            update(a,1);
            update(b+1,-1);
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if( i!=n )
            {
                printf("%d ",sum(i));
            }
            else printf("%d\n",sum(i));
        }
    }
    return 0;
}
