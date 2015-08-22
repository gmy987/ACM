#include <cstdio>
#include <cstring>
#include <iostream>
#define eps 1e-8

using namespace std;
int t,n,m;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int sum1 = 0 , sum2 = 0;
        int a;
        for( int i = 0 ; i < n-1 ; i++ )
        {
            scanf("%d",&a);
            sum1 += a;
        }
        for( int j = 0 ; j < m ; j++ )
        {
            scanf("%d",&a);
            sum2 += a;
        }
        int mi = sum2*(double)(m+1)/m-sum2;
        double ma = sum1*(double)n/(n-1)-sum1;
        int ans = (ma-(int)(ma) < eps ? ma-1 : (int)(ma));
        printf("%d %d\n",mi+1,ans);
    }
    return 0;
}
