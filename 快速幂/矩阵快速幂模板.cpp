#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
struct Mat{
    int m[MAXN][MAXN];
    int row,col;
}

Mat init( Mat a , int c )
{
    for( int i = 0 ; i < MAXN ; i++ )
        for( int j = 0 ; j < MAXN ; j++ )
            a.m[i][j] = c;
    return a;
}
Mat mul( Mat a , Mat b )
{
    Mat c;
    c.row = a.row , c.col = b.col;
    c = init( c , 0 );
    for( int i = 0 ; i < a.row ; i++ )
        for( int j = 0 ; j < b.col ; j++ )
            for( int k = 0 ; k < b.row ; k++ )
                c.m[i][j] = (c.m[i][j]%MOD+(a.m[i][k]*b.m[k][j])%MOD)%MOD;
    return c;
}
Mat fast_mul( int n )
{
    Mat ans;
    ans = int(ans,0);
    for( int i = 0 ; i < MAXN ; i++ )
        ans.m[i][i] = 1;
    //ans初始化为单位矩阵
    Mat tmp; //tmp中保存要求幂的矩阵
    while(n)
    {
        if(n&1) ans = mul(ans,tmp);
        tmp = mul(tmp,tmp);
        n>>=1;
    }
    return ans;
}

int main()
{
    return 0;
}
