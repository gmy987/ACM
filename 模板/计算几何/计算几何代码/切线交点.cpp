/*zju_1199_切线交点.cpp*/
#include <stdio.h>
#include <math.h>

#define eps 1e-6
#define pi acos(-1.0)

struct TPoint 
{
    double x, y;
};

struct TLine
{
    double a, b, c;
};

struct TCircle
{
    TPoint c;
    double r;
};

double distanc(TPoint p1, TPoint p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void swap(TCircle &c1, TCircle &c2)
{
    TCircle c;
    c = c1;
    c1 = c2;
    c2 = c;
}

int IsOnSegment(TPoint p, TPoint p1, TPoint p2)
{
    double d1 = distanc(p1, p);
    double d2 = distanc(p, p2);
    double d3 = distanc(p1, p2);
    if(fabs(d1 + d2 - d3) < eps) return 1;
    else return 0;
}

int main()
{
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int test;
    TLine l1;
    TPoint p1;
    TCircle c1, c2;
    double k, a;
    scanf("%d", &test);
    while(test--){
        scanf("%lf%lf%lf", &c1.c.x, &c1.c.y, &c1.r);
        scanf("%lf%lf%lf", &c2.c.x, &c2.c.y, &c2.r);
        if(fabs(c1.r - c2.r) < eps){
            printf("Impossible.\n");
            continue;
        }
        double d = distanc(c1.c, c2.c);
        //if(fabs(c2.r- c1.r) - d > 0) 这样就wa 
        if(fabs(c2.r- c1.r) - d > -eps){
            printf("Impossible.\n");
            continue;
        }
        if(c2.r < c1.r) swap(c1, c2);
        double x = c1.r *d / (c2.r - c1.r);
        if(fabs(c2.c.x - c1.c.x) < eps){
            a = pi / 2;
        }
        k = (c2.c.y - c1.c.y) / (c2.c.x - c1.c.x);
        a = atan(k);
        p1.x = c1.c.x + x * cos(a);
        p1.y = c1.c.y + x * sin(a);
        if(!IsOnSegment(p1, c1.c, c2.c)){
            printf("%.2lf %.2lf\n", p1.x, p1.y);
        }
        else {
            a += pi;
            p1.x = c1.c.x + x * cos(a);
            p1.y = c1.c.y + x * sin(a);
            if(!IsOnSegment(p1, c1.c, c2.c)){
                printf("%.2lf %.2lf\n", p1.x, p1.y);
            }
        }   
    }
    return 0;
}
