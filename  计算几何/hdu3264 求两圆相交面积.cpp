#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define INF 0x7fffffff 
#define MAXN 30

using namespace std;
const double eps=1e-8;
const double PI=acos(-1.0);
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x,y = _y;
    }
    Point operator - (const Point b ) const{
        return Point(x-b.x,y-b.y);
    }
    double operator * (const Point b ) const{
        return x*b.x+y*b.y;
    }
};
struct Circle{
    Point p;
    double r;
}circle[MAXN];
double dist(Point a , Point b )
{
    return sqrt((a-b)*(a-b));
}
double AreaOfOverlap(Circle a , Circle b )
{
    double d = dist(a.p,b.p);
    if( a.r + b.r < d + eps ) return 0;
    if( d < fabs(a.r-b.r) + eps )
    {
        double rr = min(a.r,b.r);
        return PI*rr*rr;
    }
    double x = (d*d+a.r*a.r-b.r*b.r)/(2*d);
    double t1 = acos(x/a.r);
    double t2 = acos((d-x)/b.r);
    return a.r*a.r*t1+b.r*b.r*t2-d*a.r*sin(t1);
}
double AreaOfCircle(Circle a)
{
    return PI*a.r*a.r;
}
int n;
bool judge( int x , double radius )
{
    Circle center;
    center.p.x = circle[x].p.x,center.p.y = circle[x].p.y;
    center.r = radius;
    for( int i = 0 ; i < n ; i++ )
    {
        if( AreaOfOverlap(center,circle[i])*2<AreaOfCircle(circle[i])-eps)
            return false;
    }
    return true;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ )
            scanf("%lf%lf%lf",&circle[i].p.x,&circle[i].p.y,&circle[i].r);
        double radius = INF;
        double left,right,mid;
        for( int i = 0 ; i < n ; i++ )
        {
            left = 0 , right =  1e6;
            while( left < right - eps )
            {
                mid = (left+right)/2.0;
                if(judge(i,mid))
                    right = mid;
                else left = mid;
            }
            radius = min(mid,radius);
        }
        printf("%.4lf\n",radius);
    }
    return 0;
}
