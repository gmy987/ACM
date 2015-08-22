#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 100005
#define MOD 1000000007
using namespace std;

int n;
int a[MAXN];
int pos[MAXN];
int l[MAXN],r[MAXN];

int main()
{
    while(~scanf("%d",&n))
    {
        for( int i = 1 ; i <= n ; i++ )
            scanf("%d",&a[i]);
        memset( pos , 0xff , sizeof(pos) );
        for( int i = 1 ; i <= n ; i++ )
            l[i] = 0 , r[i] = n+1;
        int tmp;
        for( int i =1 ; i <= n ; i++ )
        {
            for( int k = 1 ; k*k <= a[i] ; k++  )
            {
                if(a[i]%k==0)
                {
                    tmp = a[i]/k;
                    if(pos[k]!=-1)
                        l[i] = max(l[i],pos[k]);
                    if(pos[tmp]!=-1)
                        l[i] = max(l[i],pos[tmp]);
                }
            }
            pos[a[i]] = i;
        }
        memset( pos , 0xff, sizeof(pos) );
        for( int i = n ; i >= 1 ; i-- )
        {
            for( int k = 1 ; k*k <= a[i] ; k++ )
                if( a[i]%k == 0 )
                {
                    tmp = a[i]/k;
                    if( pos[k]!=-1)
                        r[i] = min(r[i],pos[k]);
                    if( pos[tmp] != -1 )
                        r[i] = min(r[i],pos[tmp]);
                }
            pos[a[i]] = i;
        }
        int ans = 0;
        for( int i = 1 ; i <= n ; i++ )
            ans = (ans%MOD+(i-l[i])*(r[i]-i)%MOD)%MOD;
        printf("%d\n",ans);
    }
    return 0;
}
