#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;

class Mat
{
    public:
    int mat[10][10];
    void clear()
    {
        memset( mat , 0 , sizeof(mat));
    }
};
int a[1005][7] , b[7][1005] , D[1005][7] , E[1005][1005];
Mat multi( Mat A , Mat B )
{
    Mat C;
    C.clear();
    for( int i = 1 ; i <= k ; i++ )
        for( int j = 1 ; j <= k ; j++ )
            for( int m = 1 ; m <= k ; m++ )
                C.mat[i][j] = ( C.mat[i][j] + A.mat[i][m]*B.mat[m][j])%6;
    return C;
}

Mat fastm( Mat C , int m )
{
    if( m == 1 )
        return C ;
    else if( m&1 )
        return multi( fastm( multi( C , C ) , m >> 1 ) , C );
    else
        return fastm( multi( C , C ) ,  m >> 1 );
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(~scanf("%d%d",&n,&k)&&(n+k))
    {
        int sum = 0;
        memset( D , 0 , sizeof(D));
        memset( E , 0 ,sizeof(E));
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= k ; j++ )
                scanf("%d",&a[i][j]);
        for( int i = 1 ; i <= k ; i++ )
            for( int j = 1 ; j <= n ; j++ )
                scanf("%d",&b[i][j]);
        Mat C ;
        C.clear();
        for( int i = 1 ; i <= k ; i++ )
            for( int j = 1 ; j <= k ; j++ )
                for( int m = 1 ; m <= n ; m++ )
                    C.mat[i][j] = ( C.mat[i][j] + b[i][m]*a[m][j])%6;
        C = fastm( C , n*n-1);
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= k ; j++ )
                for( int m = 1 ; m <= k ; m++ )
                    D[i][j] = ( D[i][j] + a[i][m]*C.mat[m][j])%6;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= n ; j++ )
                for( int m = 1 ; m <= k ; m++ )
                    E[i][j] = ( E[i][j] + D[i][m]*b[m][j])%6;
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 1 ; j <= n ; j++ )
                sum += E[i][j];
        printf("%d\n",sum);
    }
    return 0;
}
