#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN n

using namespace std;
int c[MAXN];
int c[MAXN][MAXN];
int lowbit(int x)
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

int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}
//二维
void update( int x , int y , int val ) 
{
    int i = y;
    while( x <= n )
    {
        y=i;
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
    int s=0;
    int i=y;
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
//二维求区间和
//sum(x2,y2)+sum(x1-1,y1-1)-sum(x2,y1-1)-sum(x1-1,y2)
int main()
{

}

