#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define eps 1e-9

struct TPoint
{ 
    double x, y;
};

struct TLine
{
    double a, b, c;
};
struct SEG
{
	double x1, x2;
};

double min(double x1, double x2, double x3, double x4)
{
	x1 <?= x2;
	x1 <?= x3;
	x1 <?= x4;
	return x1;
}

double max(double x1, double x2, double x3, double x4)
{
	x1 >?= x2;
	x1 >?= x3;
	x1 >?= x4;
	return x1;
}

double max(double a, double b)
{
	if(a > b) return a;
	return b;
}

double min(double a, double b)
{
	if(a < b) return a;
	return b;
}

double LineInter(TLine l1, TLine l2)
{
    TPoint tmp; 
    double a1 = l1.a;
    double b1 = l1.b;
    double c1 = l1.c;
    double a2 = l2.a;
    double b2 = l2.b;
    double c2 = l2.c;
    if(fabs(b1) < eps){
        tmp.x = -c1 / a1;  
        tmp.y = (-c2 - a2 * tmp.x) / b2;
    }       
    else{
        tmp.x = (c1 * b2 - b1 * c2) / (b1 * a2 - b2 * a1);
        tmp.y = (-c1 - a1 * tmp.x) / b1;
    }
	return tmp.x;
}

TLine lineFromSegment(TPoint p1, TPoint p2)
{
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
	if(c->x1 > d->x1) return 1;
	return -1;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n,segl;
	SEG seg[1000];
	TLine l1, l2, pro;
	double hx1, hx2, hy;
	double px1, px2, py;
	double obsx1, obsx2, obsy;
	double x1, x2, x3, x4, minx, maxx;
	TPoint hp1, hp2, p1, p2, tmp1, tmp2;
	while(scanf("%lf%lf%lf", &hx1, &hx2, &hy) != EOF)
	{
		if(hx1 == 0.0 && hx2 == 0.0 && hy == 0.0) break;
		scanf("%lf%lf%lf", &px1, &px2, &py);
		hp1.x = hx1;
		hp1.y = hy;
		hp2.x = hx2;
		hp2.y = hy;
		p1.x = px1;
		p1.y = py;
		p2.x = px2;
		p2.y = py;
		pro = lineFromSegment(p1, p2);
		scanf("%d", &n);
		segl = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%lf%lf%lf", &obsx1, &obsx2, &obsy);
			if(obsy - hy >= 0 || obsy - py <= 0) continue;
			tmp1.x = obsx1;
			tmp1.y = obsy;
			tmp2.x = obsx2;
			tmp2.y = obsy;
			l1 = lineFromSegment(hp1, tmp1);
			x1 = LineInter(pro, l1);
			l1 = lineFromSegment(hp2, tmp1);
			x2 = LineInter(pro, l1);
			l1 = lineFromSegment(hp2, tmp2);
			x3 =  LineInter(pro, l1);
			l1 = lineFromSegment(hp1, tmp2);	
			x4 =  LineInter(pro, l1);
		    minx = min(x1, x2, x3, x4);
			maxx = max(x1, x2, x3, x4);
			if(maxx <= px1 || minx >= px2) continue;
			else 
			{
				seg[segl].x1 = max(minx, px1);
				seg[segl++].x2 = min(maxx, px2);
			}
		}
		qsort(seg, segl, sizeof(seg[0]), cmp);	
		if(segl == 0)
		{
			printf("%.2lf\n", px2 - px1);
			continue;
		}
		double ans = seg[0].x1 - px1;
		double end = seg[0].x2;
		for(int i = 1;i < segl;i++)
		{
			if(seg[i].x2 <= end) continue;
			else if(seg[i].x1 <= end) end = seg[i].x2;
			else 
			{
				ans >?= seg[i].x1 - end;
				end = seg[i].x2;
			}
		}
		if(end < px2) ans >?= (px2 - end);
		if(ans < eps) printf("No View\n");
		else printf("%.2lf\n", ans);
	}
	return 0;	
}
