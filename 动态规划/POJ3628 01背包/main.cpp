#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
ll a[1000050];
ll cow[30];

int main()
{
    int n,b;
    while(scanf("%d%d",&n,&b)!=EOF)
    {
        ll sum = 0;
        for( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d",&cow[i]);
            sum+=cow[i];
        }
        memset(a,0,sizeof(a));
        for(int i = 1 ; i <= n ; i++ )
            for( int j = sum ; j>=cow[i] ; j--)
                a[j] = max(a[j],a[j-cow[i]]+cow[i]);
        for( int i = b ; i <= sum ; i++ )
        {
            if( a[i] >= b){
                printf("%d\n",a[i]-b);
                break;
            }
        }
    }
    return 0;
}
