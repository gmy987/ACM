#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXN 1800
#define eps 1e-8

using namespace std;
const double PI = acos(-1.0);
struct Point
{
    double x,y;
}point[MAXN];
double angle[MAXN];

long long c( int n , int m )
{
    long long ans = 1;
    for(long long i = n , j = 1 ; j <= m ; i--,j++ )
        ans*=i;
    long long div = 1;
    for( long long i = m ; i >= 1 ; i-- )
        div*=i;
    return ans/div;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ )
            scanf("%lf%lf",&point[i].x,&point[i].y);
        long long ans = c(n,4)-c(n-1,3)*n;
        int cnt;
        for( int i = 0 ; i < n ; i++ )
        {
            cnt = 0;
            for( int j = 0 ; j < n ; j++ )
            {
                if(i==j) continue;
                angle[cnt++] = atan2(point[j].y-point[i].y,point[j].x-point[i].x);
                if(angle[cnt-1] < -eps )
                    angle[cnt-1] += 2*PI;
            }
            sort( angle , angle + cnt );
            for( int k = cnt ; k < 2*cnt ; k++ )
                angle[k] = angle[k-cnt]+2*PI;
            int pos = 1;
            for( int k = 0 ; k < cnt && pos < 2*cnt ; k++ )
            {
                while(fabs(angle[pos]-angle[k])<PI&&pos<2*cnt)
                    pos++;
                if( pos-k-1 >= 2 )
                    ans+=c(pos-k-1,2);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
