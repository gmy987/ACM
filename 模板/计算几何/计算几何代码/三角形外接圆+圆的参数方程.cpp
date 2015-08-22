//pku_1266_三角形外接圆+圆的参数方程.cpp
#include <stdio.h>
#include <math.h>

const double eps = 1e-6;
const double pi = acos(-1);
const double inf = 9999999.0;

typedef struct TPoint
{
	double x, y;
}TPoint;

typedef struct TCircle
{
	TPoint c;
	double r;
}TCircle;

typedef struct TTriangle 
{
	TPoint t[3];
}TTriangle;

double max(double x, double y)
{
    if(x > y) return x;
    else return y; 
}

double min(double x, double y)
{
    if(x < y) return x;
    else return y; 
}

double distance(TPoint p1, TPoint p2)
{
   return sqrt((p1.x - p2.x) * (p1.x - p2.x) 
           + (p1.y - p2.y) * (p1.y - p2.y));    
}

double triangleArea(TTriangle t)
{
    //已知三角形三个顶点的坐标，求三角形的面积 
    return fabs(t.t[0].x * t.t[1].y + t.t[1].x * t.t[2].y 
              + t.t[2].x * t.t[0].y - t.t[1].x * t.t[0].y
              - t.t[2].x * t.t[1].y - t.t[0].x * t.t[2].y) / 2;   
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
    
    tmp.c.x = (c1 * (yA - yC) - c2 * (yA - yB)) / 
         ((xA - xB) * (yA - yC) - (xA - xC) * (yA - yB)); 
    tmp.c.y = (c1 * (xA - xC) - c2 * (xA - xB)) / 
         ((yA - yB) * (xA - xC) - (yA - yC) * (xA - xB)); 
         
    return tmp;     
}

double Get_angle(TPoint p, TCircle c)
{
    double ans;
    ans = acos((p.x - c.c.x) / c.r);
    if(p.y < c.c.y){
        if(ans >= M_PI / 2){
            ans = (M_PI - ans) + M_PI;
        }
        else {
            ans = 2 * M_PI - ans;
        } 
    }
    return ans;
}

double swap(double &a, double &b)
{
    double c;
    c = a;
    a = b;
    b = c;
}

int UP(double a)
{
    int a0;
    if(a >= 0){
        a0 = int(a);
        if(fabs(a0 - a) < eps) return a0;
        else return a0 + 1;
    }
    else {
        a0 = (int)a; 
        if(fabs(a0 - 1 - a) < eps) return a0 - 1;
        return a0;   
    }
}

int DOWN(double a)
{
    int a0;
    if(a >= 0){
        a0 = (int)a;
        if(fabs(a - (a0 + 1)) < eps) return a0 + 1;
        return a0;
    }
    else {
        a0 = (int)a;
        if(fabs(a0 - a) < eps) return a0;
        else return a0 - 1;
    }  
}

int main()
{
    TCircle c;
	TTriangle t;
	TPoint p1, p2, p3;
	double a1, a2, a3, tmp;
	int max_x, min_x, max_y, min_y;
        scanf("%lf%lf", &p1.x, &p1.y);
		scanf("%lf%lf%lf%lf", &p2.x, &p2.y, &p3.x, &p3.y);
		t.t[0] = p1;
		t.t[1] = p2;
		t.t[2] = p3;
		c = circumcircleOfTriangle(t);
		a1 = Get_angle(p1, c);
		a2 = Get_angle(p2, c);
		a3 = Get_angle(p3, c);
		if(a1 > a2) swap(a1, a2);
		//讨论
        if(a3 >= a1 && a3 <= a2){
            tmp = 0;
            if(tmp >= a1 && tmp <= a2){
                max_x = UP(c.c.x + c.r);
            }
            else max_x = UP(max(p1.x, p2.x));
            tmp = pi / 2;
            if(tmp >= a1 && tmp <= a2){
                max_y = UP(c.c.y + c.r);
            }
            else max_y = UP(max(p1.y, p2.y));
            tmp = pi;
            if(tmp >= a1 && tmp <= a2){
                min_x = DOWN(c.c.x - c.r);
            }
            else min_x = DOWN(min(p1.x, p2.x));
            tmp = pi * 3 / 2;
            if(tmp >= a1 && tmp <= a2){
                min_y = DOWN(c.c.y - c.r);
            }
            else min_y = DOWN(min(p1.y, p2.y)); 
        }
        else {
            tmp = 0;
            if(tmp <= a1 || tmp >= a2){
                max_x = UP(c.c.x + c.r);
            }
            else max_x = UP(max(p1.x, p2.x));
            tmp = pi / 2;
            if(tmp <= a1 || tmp >= a2){
                max_y = UP(c.c.y + c.r);
            }
            else max_y = UP(max(p1.y, p2.y));
            tmp = pi;
            if(tmp <= a1 || tmp >= a2){
                min_x = DOWN(c.c.x - c.r);
            }
            else min_x = DOWN(min(p1.x, p2.x));
            tmp = pi * 3 / 2;
            if(tmp <= a1 || tmp >= a2){
                min_y = DOWN(c.c.y - c.r);
            }
            else min_y = DOWN(min(p1.y, p2.y)); 
        }
        printf("%d\n", (max_x - min_x) * (max_y - min_y));
	return 0;
}


