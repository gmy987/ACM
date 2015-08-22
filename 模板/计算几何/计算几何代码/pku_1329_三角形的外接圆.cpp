//2608204 chenhaifeng 1329 Accepted 188K 15MS G++ 2701B 2007-09-02 11:30:32 
#include <stdio.h>
#include <math.h>

const double eps = 1e-6;

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
         
    return tmp;     
}

int main()
{
	TTriangle t;
	TCircle circle;
	double c, d, e;
	while(scanf("%lf%lf%lf%lf%lf%lf", &t.t[0].x, &t.t[0].y, 
	      &t.t[1].x, &t.t[1].y, &t.t[2].x, &t.t[2].y) != EOF){
	 circle = circumcircleOfTriangle(t);
	// printf("%lf %lf %lf\n", circle.centre.x, circle.centre.y, circle.r);
	 
	 if(fabs(circle.centre.x) < eps) printf("x^2");
	 else if(circle.centre.x < 0) printf("(x - %.3lf)^2 + ", -circle.centre.x);
	 else printf("(x + %.3lf)^2 + ", circle.centre.x);
	 if(fabs(circle.centre.y) < eps) printf("y^2 = ");
	 else if(circle.centre.y < 0) printf("(y - %.3lf)^2 = ", -circle.centre.y);
	 else printf("(y + %.3lf)^2 = ", circle.centre.y);
	 printf("%.3lf^2\n", circle.r);
	 c = 2 * circle.centre.x;
	 d = 2 * circle.centre.y;
	 e = circle.centre.x * circle.centre.x + 
	     circle.centre.y * circle.centre.y - circle.r * circle.r;
	 printf("x^2 + y^2 ");
	 //if(fabs(c) < eps) 
	 if(c < 0) printf("- %.3lfx ", -c);
	 else printf("+ %.3lfx ", c);
	 if(d < 0) printf("- %.3lfy ", -d);
	 else printf("+ %.3lfy ", d);
	 if(e < 0) printf("- %.3lf = 0\n", -e);
	 else printf("+ %.3lf = 0\n", e);
	 printf("\n");
	}
	return 0;	
}


