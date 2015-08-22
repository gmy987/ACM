//此题为多重背包的变形，与普通多重背包相比多了对于每个物品的最大值限制，为了得到最优解，要对这个最大
//值进行从小到大排序，然后用二进制优化，再转化为01背包即可。并且由于背包最大容量并不是固定的，所以，最后的结果要对于
//DP搜索一遍，得到其中保存的最大值即为最终结果。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int dp[16000000];
struct Node{
    int height,restrict;
}node[4000];

bool cmp( Node a,Node b)
{
    return a.restrict<b.restrict;
}

int main()
{
    int k;
    while( scanf("%d",&k)!=EOF)
    {
        int h,c,a;
        int cnt = 0,sum = 0;
        for( int i = 1 ; i<=k ; i++ )
        {
            scanf("%d%d%d",&h,&a,&c);
            for( int j = 1 ; j <= c ; j*=2 )
            {
                node[++cnt].restrict = a;
                node[cnt].height = j*h;
                c-=j;
            }
            if( c>0){
                node[++cnt].restrict = a;
                node[cnt].height = c*h;
            }
        }
        sort( node+1 , node+cnt+1 , cmp);

        memset(dp,0,sizeof(dp));
        for( int i = 1 ; i <= cnt ; i++ )
            for( int j = node[i].restrict ; j>=node[i].height ; j-- )
                dp[j] = max(dp[j],dp[j-node[i].height]+node[i].height);
        int ans = 0;
        for( int i = 1 ; i <= node[cnt].restrict ; i++ )
        {
            ans = max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
}
