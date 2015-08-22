#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,b;
    while(scanf("%d%d",&n,&b)!=EOF)
    {
        int *a = new int[n];
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        int cnt = 0,sum = 0;
        for( int i = 0 ; i < n ; i++ )
        {
            if( sum+a[i]< b)
            {
                sum+=a[i];
                cnt++;
            }
            else
                break;
        }
        printf("%d\n",cnt+1);
    }
    return 0;
}
