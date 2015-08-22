#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 1000

using namespace std;
double p;
struct Mat{
    int row,col;
    double a[2][2];
    Mat(){
        row = 2 , col = 2;
        a[0][0] = p;
        a[0][1] = 1-p; 
        a[1][0] = 1;
        a[1][1] = 0;
    }
};
Mat init( Mat x , double c )
{
    for( int i = 0 ; i < 2 ; i++ )
        for( int j = 0 ; j < 2 ; j++ )
            x.a[i][j] = c;
    return x;
}
Mat mult( Mat x , Mat s )
{
    Mat ans;
    ans.row = x.row , ans.col = s.col;
    ans = init(ans,0);
    for( int i = 0 ; i < x.row ; i++ )
        for( int j = 0 ; j < x.col ; j++ )
            for( int k = 0 ; k < s.col ; k++ )
                ans.a[i][j] += x.a[i][k]*s.a[k][j];
    return ans;
}

Mat fast_mult(int n )
{
    Mat ans;
    memset( ans.a , 0 , sizeof(ans.a) );
    for( int i = 0 ; i < 2 ; i++ )
        ans.a[i][i] = 1;
    Mat temp;
    while(n)
    {
        if(n&1) ans=mult(ans,temp);
        temp = mult(temp,temp);
        n>>=1;
    }
    return ans;
}

int mine[MAXN];
int n;

int main()
{
    while(~scanf("%d%lf",&n,&p))
    {
        for( int i = 0 ; i < n ; i++ )
            scanf("%d",&mine[i]);
        sort( mine , mine + n );
        double aa = 1.0 , bb = 0;
        bool flag = true;
        for( int i = 0 ; i < n ; i++ )
        {
            Mat ans;
            if( mine[i] == 1 )
            {
                flag = false;
                break;
            }
            if( i != 0 )
                ans = fast_mult(ans,mine[i]-1-mine[i-1]);
            else ans = fast_mult(ans,mine[i]-1);
            aa *= ans.a[1][0];
            aa *= (1-p);
        }
        if(flag)
        printf("%.7f\n",aa);
        else printf("%.7f\n",bb);
    }
    return 0;
}
