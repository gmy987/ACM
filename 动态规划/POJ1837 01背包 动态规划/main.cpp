/*每向天平中方一个重物，天平的状态就会改变，而这个状态可以由若干前一状态获得。
首先定义一个平衡度j的概念
当平衡度j=0时，说明天枰达到平衡，j>0，说明天枰倾向右边（x轴右半轴），j<0则相反
那么此时可以把平衡度j看做为衡量当前天枰状态的一个值
因此可以定义一个 状态数组dp[i][j]，意为在挂满前i个钩码时，平衡度为j的挂法的数量。
由于距离c[i]的范围是-15~15，钩码重量的范围是1~25，钩码数量最大是20
因此最极端的平衡度是所有物体都挂在最远端，因此平衡度最大值为j=15*20*25=7500。原则上就应该有dp[ 1~20 ][-7500 ~ 7500 ]。
因此为了不让下标出现负数，做一个处理，使使得数组开为 dp[1~20][0~15000]，则当j=7500时天枰为平衡状态
那么每次挂上一个钩码后，对平衡状态的影响因素就是每个钩码的 力臂
力臂=重量 *臂长 = w[i]*c[k]
那么若在挂上第i个砝码之前，天枰的平衡度为j
   (换言之把前i-1个钩码全部挂上天枰后，天枰的平衡度为j)
则挂上第i个钩码后，即把前i个钩码全部挂上天枰后，天枰的平衡度 j=j+ w[i]*c[k]
   其中c[k]为天枰上钩子的位置，代表第i个钩码挂在不同位置会产生不同的平衡度
不难想到，假设 dp[i-1][j] 的值已知，设dp[i-1][j]=num
               （即已知把前i-1个钩码全部挂上天枰后得到状态j的方法有num次）
   那么dp[i][ j+ w[i]*c[k] ] = dp[i-1][j] = num
(即以此为前提，在第k个钩子挂上第i个钩码后，得到状态j+ w[i]*c[k]的方法也为num次)
想到这里，利用递归思想，不难得出 状态方程dp[i][ j+ w[i]*c[k] ]= ∑（dp[i-1][j]）
有些前辈推导方式稍微有点不同，得到的 状态方程为dp[i][j] =∑(dp[i - 1][j - c[i] * w[i]])
其实两条方程是等价的，这个可以简单验证出来，而且若首先推导到第二条方程，也必须转化为第一条方程，这是为了避免下标出现负数
结论：
最终转化为01背包问题
状态方程dp[i][ j+ w[i]*c[k] ]= ∑（dp[i-1][j]）
初始化：dp[0][7500] = 1;   //不挂任何重物时天枰平衡，此为一个方法
复杂度O(C*G*15000)  完全可以接受*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int c,g,w[20],v[20],dp[21][15001];
	while( scanf("%d%d",&c,&g)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		for( int i = 1 ; i <= c ; i++ )
            scanf("%d",&v[i]);
        for( int i = 1 ; i <= g ; i++ )
            scanf("%d",&w[i]);
        dp[0][7500] = 1;
        for( int i = 1 ; i <= g ; i++ )
            for( int j = 0 ; j <= 15000 ; j++ )
                if(dp[i-1][j])
                    for( int k = 1 ; k <= c ; k++ )
                        dp[i][j+w[i]*v[k]]+=dp[i-1][j];

        printf("%d\n",dp[g][7500]);
	}
	return 0;
}



























