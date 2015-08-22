#include <stdio.h>
#include <math.h>

const double eps = 1e-4;
const double pi = acos(-1.0);

struct TPoint 
{
	double x, y;
}p[60], a[60];
double angle[60];

double multi(TPoint p1, TPoint p2, TPoint p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

TPoint fine_a2(TPoint a1, TPoint m, double angle1)
{
	TPoint a2;
	double r, angle2, angle3;
	r = sqrt((a1.x - m.x) * (a1.x - m.x) + (a1.y - m.y) * (a1.y - m.y));
	angle2 = acos((a1.x - m.x) / r);
	if(a1.y < m.y) {
		if(angle2 <= pi / 2) angle2 = -angle2;
		if(angle2 > pi / 2) angle2 = 3 * pi / 2 - (angle2 - pi / 2);
	}
	angle3 = angle2 - angle1;
	a2.x = m.x + r * cos(angle3);
	a2.y = m.y + r * sin(angle3);
	if(multi(m, a2, a1) < 0) return a2;
    angle3 = angle2 + angle1;
	a2.x = m.x + r * cos(angle3);
	a2.y = m.y + r * sin(angle3);
	if(multi(m, a2, a1) < 0) return a2;	
}

int main()
{
	int n, i, j;
	while(scanf("%d", &n) != EOF){
		for(i = 0;i < n;i++){
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		for(i = 0;i < n;i++){
			scanf("%lf", &angle[i]);
			angle[i] = angle[i] * pi / 180;
		}
		a[0].x = 0;
		a[0].y = 0;
		while(1){
			for(i = 1;i <= n;i++){
				a[i] = fine_a2(a[i - 1], p[i - 1], angle[i - 1]);
			}
			if(fabs(a[n].x - a[0].x) <= eps  
			  && fabs(a[n].y - a[0].y) <= eps) break;
			else {
				a[0].x = (a[0].x + a[n].x) / 2;
				a[0].y = (a[0].y + a[n].y) / 2;
			}
		}
		for(i = 0;i < n;i++){
			printf("%.0lf %.0lf\n", a[i].x, a[i].y);
		}		
	}
	return 0;
}
