//基本策略是贪心
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1005],b[1005],n,ans;

bool cmp(int a , int b )
{
    return a > b;
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&a[i]);
        for( int j = 0 ; j < n ; j++ )
            scanf("%d",&b[j]);
        //将齐王和田忌的马分别从大到小排序
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        ans = 0;
        int t1 = 0 , t2 = 0 , r1 = n - 1 , r2 = n - 1 , cnt = 0;
        while( t1 <= r1 )
        {
            //若田忌最快的马速度大于齐王速度最快的马，则此二马比较，田忌胜
            if( a[t1] > b[t2] )
            {
                t1++,t2++;
                ans++;
            }
            //若田忌速度最快的马慢于齐王速度最快的马，由于没有马可赢此马，于是用田忌速度最小的马来比，减小损失。
            else if( a[t1] < b[t2] )
            {
                r1--,t2++;
                ans--;
            }
            //若二者速度最大的马相同，则比较速度最慢的马
            else if( a[t1] == b[t2] )
            {
                //田忌速度最慢的大于齐王速度最慢的，则田忌胜，因为若要胜，每匹马应选择速度跟他最相近且可以胜过的马比较
                if( a[r1] > b[r2] )
                {
                    r1--,r2--;
                    ans++;
                }
                else
                {
                    //若田忌最慢的马慢于齐王最快的马，则二者相比，田忌输。
                    if( a[r1] < b[t2] ) ans--;
                    r1--,t2++;
                }
            }
        }
        printf("%d\n",ans*200);
    }
    return 0;
}
