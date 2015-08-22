#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int vist[10005];
int m,a,b;
struct Number
{
    int num,step;
};

bool isPrime( int x )
{
    if(x==1||!(x%2)) return false;
    if(x==2) return true;
    for( int i = 3 ; i <= sqrt(x) ; i+=2 )
        if(!(x%i))
            return false;
    return true;
}

int bfs( int a , int b )
{
    memset(vist,0,sizeof(vist));
    Number n;
    n.num = a,n.step = 0;
    queue<Number> q;
    q.push(n);
    vist[n.num] = 1;
    while(!q.empty())
    {
        Number v;
        n = q.front();
        q.pop();
        if( n.num == b )
            return n.step;
        for( int i = 3 ; i >= 0 ; i-- )
        {
            int p = pow(10,i);
            int x = (n.num/p)%10;
            for( int j = 0 ; j < 10 ; j++ )
            {
                if( i == 3 && j == 0 )
                    continue;
                int y = n.num + (j-x)*p;
                if(!vist[y]&&isPrime(y) )
                {
                    v.num = y;
                    v.step = n.step + 1;
                    vist[y] = 1;
                    q.push(v);
                }
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        int step = bfs( a , b );
        if( step == -1)
            printf("Impossible\n");
        else
            printf("%d\n",step);
    }
}
