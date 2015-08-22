#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 200005

using namespace std;
int t;
int n,q,w;
int c[MAXN];
int now;
int cd[MAXN];
int protect[MAXN];
struct Node{
    int l,r;
}attack[MAXN];

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
int sum( int x )
{
    int sum = 0;
    while( x > 0 )
    {
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}

int main()
{
    scanf("%d",&t);
    int cas = 1;
    while(t--)
    {
        scanf("%d%d%d",&n,&q,&w);
        printf("Case %d:\n",cas++);
        memset( c , 0 , sizeof(c) );
        memset( cd , 0 , sizeof(cd) );
        memset( protect , 0 , sizeof(protect) );
        now = 0;
        int a;
        while( q-- )
        {
            char str[10];
            scanf("%s",str);
            if(str[0]=='A')
            {
                scanf("%d%d",&attack[now].l,&attack[now].r);
                update(attack[now].l,1);
                update(attack[now++].r+1,-1);
            }
            else{
                scanf("%d",&a);
                for( int i = cd[a] ; i < now ; i++ )
                {
                    if( attack[i].l <= a && a <= attack[i].r )
                    {
                        protect[a]++;
                        cd[a] = i+w;
                        i+=w;
                        i--;
                    }
                }
                printf("%d\n",sum(a)-protect[a]);
            }
        }
    }
    return 0;
}
