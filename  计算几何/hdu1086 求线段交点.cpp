#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 150

using namespace std;
const double eps=1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    else return 1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y)
    {
        this->x = x;
        this->y = y;
    }
    Point operator - (const Point &b ) const{
        return Point(x-b.x,y-b.y);
    }
    double operator ^(const Point &b ) const{
        return x*b.y-y*b.x;
    }
    double operator *(const Point &b ) const{
        return x*b.x+y*b.y;
    }
};
struct Line{
    Point s,e;
    Line(){}
    Line(Point _s , Point _e )
    {
        s = _s,e = _e; 
    }
}line[MAXN];
bool inter(Line l1 , Line l2 )
{
    return max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
           max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
           max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
           max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
           sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
           sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}
int n;


int main()
{
    while(~scanf("%d",&n)&&n)
    {
        int cnt = 0;
        for( int i = 0 ; i < n ; i++ )
            scanf("%lf%lf%lf%lf",&line[i].s.x,&line[i].s.y,&line[i].e.x,&line[i].e.y);
        for( int i = 0 ; i < n-1 ; i++ )
            for( int k = i+1 ; k < n ; k++ )
                if(inter(line[i],line[k]))
                    cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
