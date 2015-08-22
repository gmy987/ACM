#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,m,x,y;
    while(~scanf("%d%d%d%d",&n,&m,&x,&y))
    {
        if(n>m)
        {
            n^=m,m^=n,n^=m;
            x^=y,y^=x,x^=y;
        }
        int ans = (n+1)/2;
        if( n&1 && x == ans )
            ans = min(ans,max(y-1,max(x-1,max(m-y,n-x))));
        else if( n&1 || x!=ans)
        {
            if(min(y,m-y+1)>ans)
            {
                ans = min(max(x-1,n-x),min(y,m-y+1));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
