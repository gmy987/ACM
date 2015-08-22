#include<cstdio>
#include<iostream>
#include<cstring>
#define MAXN 1200

using namespace std;
int n;
int c[MAXN+1][MAXN+1];
bool vis[MAXN+1][MAXN+1];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int y,int val)
{
    int i = y;
    while( x <= MAXN )
    {
        y = i;
        while( y <= MAXN )
        {
            c[x][y]+=val;
            y+=lowbit(y);
        }
        x+=lowbit(x);
    }
}
int sum( int x , int y )
{
    int sum = 0;
    int i = y;
    while( x > 0 )
    {
        y = i;
        while( y > 0 )
        {
            sum+=c[x][y];
            y-=lowbit(y);
        }
        x-=lowbit(x);
    }
    return sum;
}



int main()
{
    while(~scanf("%d",&n))
    {
        memset( c , 0 , sizeof(c) );
        memset( vis , 0 , sizeof(vis) );
        while(n--)
        {

            char b[2];
            scanf("%s",b);
            int x1,x2,y1,y2;
            if( b[0] == 'B' )
            {
                scanf("%d%d",&x1,&y1);
                x1++;
                y1++;
                if(!vis[x1][y1])
                {
                    vis[x1][y1] = 1;
                    update(x1,y1,1);
                }
            }
            else if( b[0] == 'D' )
            {
                scanf("%d%d",&x1,&y1);
                x1++;
                y1++;
                if(vis[x1][y1])
                {
                    vis[x1][y1] = 0;
                    update(x1,y1,-1);
                }
            }
            else{
                scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
                x1++;
                x2++;
                y1++;
                y2++;
                if( x1>x2 )
                {
                    int temp = x1;
                    x1=x2;
                    x2=temp;
                }
                if( y1 > y2 )
                {
                    int temp = y1;
                    y1 = y2;
                    y2 = temp;
                }
                printf("%d\n",sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1));
            }
        }
    }
    return 0;
}
