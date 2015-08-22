#include <stdio.h>
#include <math.h>

/*typedef struct TPoint
{
    double x;
    double y;
}TPoint;
 
double distanc(TPoint p1, TPoint p2)
{
    //计算平面上两个点之间的距离
   return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));    
}

double triangleArea(TPoint p0, TPoint p1, TPoint p2)
{
    //已知三角形三个顶点的坐标，求三角形的面积 
    return (p0.x * p1.y + p1.x * p2.y + p2.x * p0.y
      - p1.x * p0.y - p2.x * p1.y - p0.x * p2.y) / 2;   
}

int main()
{
    TPoint center, p0, p1, p2;
    double sumx, sumy, sumarea, area, i;
    double r, angle;
    while(scanf("%lf%lf", &r, &angle) != EOF){
		p0.x = 0.0;
		p0.y = 0.0;
		p1.x = r * cos(0);
		p1.y = r * sin(0);
		sumx = 0;
		sumy = 0;
		sumarea = 0;
		for(i = 0.01;i <= angle;i += 0.01){
			p2.x = r * cos(i);
			p2.y = r * sin(i);
			center.x = p0.x + p1.x + p2.x;
			center.y = p0.y + p1.y + p2.y;
			area = triangleArea(p0, p1, p2);
			sumx += area * center.x;
			sumy += area * center.y;
			sumarea += area;
			p1 = p2;
		} 
		center.x = sumx / sumarea / 3;
		center.y = sumy / sumarea / 3;
		printf("%.6lf\n", distanc(center, p0));
    }
    return 0;
}*/
//Xc = 2*R*sinA/3/A 
//A为圆心角的一半

int main()
{
	double r, angle;
	while(scanf("%lf%lf", &r, &angle) != EOF){
		angle /= 2;
		printf("%.6lf\n", 2 * r * sin(angle) / 3 / angle);
	}
	return 0;
} 

 
