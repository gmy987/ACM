#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define pi acos(-1.0)

struct point{
    double x,y;
};
struct line{
    point a,b;
};

double xmult( point p1 , point p2 , point p0 )
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int parallel( line u , line v )
{
    return zero((u.a.x-u.b.x)*(v.a.y-v.b.y)-(v.a.x-v.b.x)*(u.a.y-u.b.y));
}
point intersection( line u , line v )
{
    point rect = u.a;
    double t = ((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    rect.x += (u.b.x-u.a.x)*t;
    rect.y += (u.b.y-u.a.y)*t;
    return rect;
}


using namespace std;

int main()
{
    line a,b;
    int n;
    while(~scanf("%d",&n))
    {
        printf("INTERSECTING LINES OUTPUT\n");
        for( int i = 0 ;  i < n ; i++)
        {
            cin >> a.a.x >> a.a.y >> a.b.x >> a.b.y >> b.a.x >> b.a.y >> b.b.x >> b.b.y;
            if( xmult( a.a , a.b , b.a ) == 0 && xmult( a.a , a.b , b.b ) == 0 )
                printf("LINE\n");
            else if( parallel(a,b) )
                printf("NONE\n");
            else{
                point temp = intersection( a , b );
                printf("POINT %.2lf %.2lf\n",temp.x,temp.y);
            }
        }
        printf("END OF OUTPUT\n");
    }
    return 0;
}














