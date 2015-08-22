#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define MAXN 150

using namespace std;

const double eps=1e-8;
const double PI=acos(-1.0);
int sgn(double x)
{
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x , double _y )
    {
        x = _x;
        y = _y;
    }
    Point operator - (const Point &b ) const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator ^ (const Point &b ) const
    {
        return x*b.y-y*b.x;
    }
    double operator * (const Point &b ) const
    {
        return x*b.x+y*b.y;
    }
}point[MAXN];

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for( int i = 0 ; i < n ; i++ )
            scanf("%lf%lf",&point[i].x,&point[i].y);
        double ans = 0;
        for( int i = 1 ; i < n-1 ; i++ )
            ans+=(point[0]-point[i])^(point[0]-point[i+1]);
        printf("%.1f\n",fabs(ans/2));
    }
    return 0;
}
