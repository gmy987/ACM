/*三角形的外接圆pku_1329*/
#include <stdio.h>
#include <math.h>

const double eps = 1e-6;
const double inf = 1e20;
const double pi = acos(-1);

typedef struct TPoint 
{
	double x;
	double y;
}TPoint;

typedef struct TTriangle 
{
	TPoint t[3];
}TTriangle;

typedef struct TCircle
{
	TPoint centre;
	double r;
}TCircle;

double distance(TPoint p1, TPoint p2)
{
    //计算平面上两个点之间的距离
   return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));    
}

double triangleArea(TTriangle t)
{
    //已知三角形三个顶点的坐标，求三角形的面积 
    return fabs(t.t[0].x * t.t[1].y + t.t[1].x * t.t[2].y + t.t[2].x * t.t[0].y
      - t.t[1].x * t.t[0].y - t.t[2].x * t.t[1].y - t.t[0].x * t.t[2].y) / 2;   
}

TCircle circumcircleOfTriangle(TTriangle t)
{
    //三角形的外接圆
    TCircle tmp;
    double a, b, c, c1, c2;
    double xA, yA, xB, yB, xC, yC;
    a = distance(t.t[0], t.t[1]);
    b = distance(t.t[1], t.t[2]);
    c = distance(t.t[2], t.t[0]);
    //根据S = a * b * c / R / 4;求半径R 
    tmp.r = a * b * c / triangleArea(t) / 4;
    
    xA = t.t[0].x; yA = t.t[0].y;
    xB = t.t[1].x; yB = t.t[1].y;
    xC = t.t[2].x; yC = t.t[2].y;
    c1 = (xA * xA + yA * yA - xB * xB - yB * yB) / 2;
    c2 = (xA * xA + yA * yA - xC * xC - yC * yC) / 2;
    
    tmp.centre.x = -(c1 * (yA - yC) - c2 * (yA - yB)) / 
         ((xA - xB) * (yA - yC) - (xA - xC) * (yA - yB)); 
    tmp.centre.y = -(c1 * (xA - xC) - c2 * (xA - xB)) / 
         ((yA - yB) * (xA - xC) - (yA - yC) * (xA - xB)); 
    tmp.centre.x *= -1;
    tmp.centre.y *= -1;
         
    return tmp;     
}

int main()
{
    int n, i, test = 1;
	TTriangle t;
	TCircle circle;
	TPoint vex[55];
	TPoint tmp;
	double d, a;
	while(scanf("%d", &n) && n)
    {
        scanf("%lf%lf%lf%lf%lf%lf", &t.t[0].x, &t.t[0].y, 
	      &t.t[1].x, &t.t[1].y, &t.t[2].x, &t.t[2].y);
        circle = circumcircleOfTriangle(t);
        //printf("%lf %lf\n", circle.centre.x, circle.centre.y);
        d = 2 * pi / n;
        tmp.y = t.t[0].y - circle.centre.y;
        tmp.x = t.t[0].x - circle.centre.x;
        if(tmp.x == 0)
        {
            if(tmp.y > 0) a = pi / 2;
            else a = 3 * pi / 2;
        }
        else a = atan(tmp.y / tmp.x);
        if(tmp.x < 0) a += pi;
        double maxx = -inf, maxy = -inf;
        double minx = inf, miny = inf;
        for(i = 1;i <= n;i++)
        {
            vex[i].x = circle.centre.x + circle.r * cos(a);
            vex[i].y = circle.centre.y + circle.r * sin(a);
            if(vex[i].x > maxx) maxx = vex[i].x;
            if(vex[i].x < minx) minx = vex[i].x;
            if(vex[i].y > maxy) maxy = vex[i].y;
            if(vex[i].y < miny) miny = vex[i].y;
            a += d;
            if(a > 2 * pi) a -= 2 * pi;
        }
        printf("Polygon %d: %.3lf\n", test++, (maxx - minx) * (maxy - miny));
	}
	return 0;	
}
