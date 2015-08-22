#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 10000007
using namespace std;
int m,n,ans;
int sum( int floor )
{
    return (floor+1)*(floor+1)*floor*floor/4;//计算1^3+2^3+...+floor^3三次方和的公式
}
void dfs( int floor , int r , int h , int leftv , int s )
{
    if( s + 2*leftv/r >= ans ) return;//剪枝1：当已算面积加上剩下的体积可以组成的最小面积大于之前求出的临时ans时，
                                      //不用再往下算，因为不会小于之前的临时值

    if( leftv < sum(floor) ) return;  //剪枝2：当前剩下的体积小于1～floor的立方和（即从最上一层开始取最小值，每层r,h都+1
                                      //sum(floor)得到的是当前层数可以得到的最小体积值，若当前体积比这个最小值还小，则证明此时的情况不成立。
    if(floor == 0)
    {
        if( leftv == 0 )
            ans = s;
        return;
    }
    int k = 0 , i , j;
    for( i = r - 1 ; i >= floor ;i-- )
    {
        k = i*i;
        if( floor == m )
            s = k;
        for( j = h - 1 ; j >= floor ; j-- )
            dfs( floor - 1 , i , j , leftv - k * j , s + i*2*j );
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        ans = INF;
        dfs(m,100,10000,n,0);
        //r，h最大值分别为100，10000，分别为h=1,r=1时得到
        if(ans==INF)
            printf("0\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
