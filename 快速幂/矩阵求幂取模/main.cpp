#include <iostream>
#include <cstring>
#define mod 10007
using namespace std;
const int N = 4;//为N×N矩阵
struct Mat{
    int mat[N][N];
    void clear()
    {
        memset(mat , 0 , sizeof(mat));
    }
};
Mat mul( Mat A , Mat B )
{
    Mat C;
    C.clear();
    int i , j , k;
    for( i = 0 ; i < N ; i++ )
        for( j = 0 ; j < N ; j++ )
            for( k = 0 ; k < N ; k++ )
                C.mat[i][j] = (C.mat[i][j] + A.mat[i][k]*B.mat[k][j])%mod;
    return C;
}

Mat fastm( Mat C , int n )
{
    if( n == 1 )
        return C;
    else if( n&1 )
        return mul(fastm( mul( C , C) , n >> 1) , C);
    else return fastm(mul(C,C) , n>>1);
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
