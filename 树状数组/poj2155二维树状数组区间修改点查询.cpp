#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 1005

using namespace std;
int n,m;
int c[MAXN][MAXN];
int lowbit(int x)
{
    return x&(-x);
}
void update( int x , int y , int val )
{
    int i = y;
    while(x<=n)
    {
        y = i;
        while(y<=n)
        {
            c[x][y]+=val;
            y+=lowbit(y);
        }
        x+=lowbit(x);
    }
}
int sum( int x , int y )
{
    int s = 0 , i = y;
    while( x > 0 )
    {
        y = i;
        while(y>0)
        {
            s+=c[x][y];
            y-=lowbit(y);
        }
        x-=lowbit(x);
    }
    return s;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(c,0,sizeof(c));
        int x1,x2,y1,y2;
        scanf("%d%d",&n,&m);
        char str[3];
        while(m--)
        {
            scanf("%s",str);
            if( str[0] == 'C')
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                update(x1,y1,1);
                update(x2+1,y2+1,1);
                update(x1,y2+1,-1);
                update(x2+1,y1,-1);
            }
            else{
                scanf("%d%d",&x1,&y1);
                int ans = sum(x1,y1);
                printf("%d\n",ans%2);
            }
        }
        printf("\n");
    }
    return 0;
}
