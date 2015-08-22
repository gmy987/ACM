#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define eps 1e-8
#define pi acos(-1)

typedef struct SEG
{
	double l, r;
}SEG;

typedef struct TPoint
{
	double x, y;
}TPoint; 

typedef struct TLine
{
	double a, b, c;
}TLine;

typedef struct Circle
{
	TPoint c;
	double r;
}Circle;

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

TPoint LineInter(TLine l1, TLine l2)
{
    //求两直线得交点坐标
    TPoint tmp; 
    double a1 = l1.a;
    double b1 = l1.b;
    double c1 = l1.c;
    double a2 = l2.a;
    double b2 = l2.b;
    double c2 = l2.c;
    //注意这里b1 = 0 
    if(fabs(b1) < eps){
        tmp.x = -c1 / a1;  
        tmp.y = (-c2 - a2 * tmp.x) / b2;
    }       
    else{
        tmp.x = (c1 * b2 - b1 * c2) / (b1 * a2 - b2 * a1);
        tmp.y = (-c1 - a1 * tmp.x) / b1;
    }
	return tmp;
}

TLine lineFromSegment(TPoint p1, TPoint p2)
{
    //线段所在直线,返回直线方程的三个系统 
    TLine tmp;
    tmp.a = p2.y - p1.y;
    tmp.b = p1.x - p2.x;
    tmp.c = p2.x * p1.y - p1.x * p2.y;
    return tmp;
}

int cmp(const void *a, const void *b)
{
	SEG *c = (SEG *)a;
	SEG *d = (SEG *)b;
	if(c->l < d->l) return -1;
	else return 1;
}

int main()
{
	int n, i, j;
	TPoint b, inter;
	double lbc, lcinter, a, bangle;
	double start, end;
	TLine l1;
	Circle circle[505];
	SEG seg[505];	
	
	while(scanf("%d", &n) && n){
		scanf("%lf%lf", &b.x, &b.y);
		for(i = 0;i < n;i++){
			scanf("%lf%lf%lf", &circle[i].c.x, &circle[i].c.y, &circle[i].r);
			if(fabs(b.x - circle[i].c.x) < eps) a = pi / 2;
			else a = atan((circle[i].c.y - b.y) / (circle[i].c.x - b.x));
			if(a < 0) a += pi;
			lbc = distance(b.x, b.y, circle[i].c.x, circle[i].c.y);
			bangle = asin(circle[i].r / lbc);
			l1 = lineFromSegment(b, circle[i].c);
			inter.x = -l1.c / l1.a;
			inter.y = 0.0;
			lcinter = distance(inter.x, inter.y, b.x, b.y);
			seg[i].l = inter.x - lcinter * circle[i].r / lbc / sin(a - bangle);
			seg[i].r = inter.x + lcinter * circle[i].r / lbc / sin(pi - a - bangle);			
		}
		qsort(seg, n, sizeof(seg[0]), cmp);
		start = seg[0].l;
		end = seg[0].r;
		for(i = 1;i < n;i++){
			if(seg[i].l > end){
				printf("%.2lf %.2lf\n", start, end);
				start = seg[i].l;
			    end = seg[i].r;
			}
			else {
				if(seg[i].r > end) end = seg[i].r;
			}
		}
		printf("%.2lf %.2lf\n\n", start, end);
	}
	return 0;
}
