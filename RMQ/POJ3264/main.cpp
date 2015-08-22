#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const int MAX = 50005;
int maxsum[MAX][17];
int minsum[MAX][17];
int n,q,x,y;

void RMQ()
{
    for( int j = 1 ; j <= 16 ; j++ )
        for( int i = 1 ; i <= n ; i++ )
            if( i + (1<<j) - 1 <= n)
            {
                maxsum[i][j] = max(maxsum[i][j-1],maxsum[i+(1<<(j-1))][j-1]);
                minsum[i][j] = min(minsum[i][j-1],minsum[i+(1<<(j-1))][j-1]);
            }
}

int main()
{
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        memset(maxsum,0,sizeof(maxsum));
        memset(minsum,0,sizeof(minsum));
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&maxsum[i][0]);
            minsum[i][0] = maxsum[i][0];
        }
        RMQ();
        for( int i = 0 ; i < q ; i++ )
        {
            scanf("%d%d",&x,&y);
            int k = log((double)(y-x+1))/log(2.0);
            printf("%d\n",max(maxsum[x][k],maxsum[y-(1<<k)+1][k])-min(minsum[x][k],minsum[y-(1<<k)+1][k]));
        }
    }
}
