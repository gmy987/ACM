#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
bool cmp( int a,int b)
{
    return abs(a)<abs(b);
}

int main()
{
    int time,n;
    while(scanf("%d%d",&time,&n)!=EOF)
    {
        int *a = new int[n];
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        int use = 0,ans = 0;
        if( a[0] <= time )
        {
            use = a[0];
            ans = 1;
            for( int i = 1 ; i < n ; i++ )
            {
                if( abs(a[i] - a[i-1])<=time - use)
                {
                    ans++;
                    use+=abs(a[i] - a[i-1]);
                }
                else
                    break;
            }
            printf("%d\n",ans);
        }
        else
            printf("%d\n",0);
    }
}
