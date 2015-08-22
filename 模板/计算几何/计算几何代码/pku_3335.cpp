#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define MaxVertice 200
#define xx polygon.vertice[i].x
#define yy polygon.vertice[i].y

const double eps = 1e-6;
const double inf = 1e30;

typedef struct TPoint
{
    double x;
    double y;
}TPoint;

typedef struct TPolygon
{
    TPoint vertice[MaxVertice];
    int n;
}TPolygon;
typedef struct TLine
{
    double a, b, c;
}TLine;
int ConcavePoint[MaxVertice];
int t;
//int order;
/*
order = 1 表示逆时针方向
order = 0 表示顺时针方向 
最后改成了，若是顺时针方向，则改成逆时针 
*/
bool IsParallel(TPoint p1, TPoint p2, TPoint p3, TPoint p4)
{
    TPoint p5, p6;
    p5.x = p1.x - p2.x;
    p5.y = p1.y - p2.y;
    p6.x = p3.x - p4.x;
    p6.y = p3.y - p4.y;
    if(fabs(p5.y) < eps && fabs(p6.y) < eps) return 1;
    else if(fabs(p5.y) < eps && fabs(p6.y) > eps) return 0;
    else if(fabs(p5.y) > eps && fabs(p6.y) < eps) return 0;
    if(fabs(p5.x / p5.y - p6.x / p6.y) < eps) return 1;
}

void change(TPolygon &polygon)
{
    //将多边形的顶点集转化成逆时针方向 
    int i, n = polygon.n;
    TPoint tmp;
    for(i = 0;i < n / 2;i++){
        tmp = polygon.vertice[i];
        polygon.vertice[i] = polygon.vertice[n - 1 - i];
        polygon.vertice[n - 1 - i] = tmp;
    }
}

double multi(TPoint p1, TPoint p2, TPoint p0)
{
    //求矢量[p0, p1], [p0, p2]的叉积
    //p0是顶点 
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
    //若结果等于0，则这三点共线
    //若结果大于0，则p0p2在p0p1的逆时针方向
    //若结果小于0，则p0p2在p0p1的顺时针方向 
}
double TriangleArea(TPoint p0, TPoint p1, TPoint p2)
{
    return (p0.x * p1.y + p1.x * p2.y + p2.x * p0.y
      - p1.x * p0.y - p2.x * p1.y - p0.x * p2.y) / 2;
}

double polygonArea(TPolygon p)
{
    //已知多边形各顶点的坐标，求其面积
    double area;
    int i, n;
    n = p.n;
    area = 0;
    for(i = 1;i <= n;i++){
        area += (p.vertice[i - 1].x * p.vertice[i % n].y 
                 - p.vertice[i % n].x * p.vertice[i - 1].y);
    }  
    return area / 2;   
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

bool isIntersected(TPoint s1, TPoint e1, TPoint s2, TPoint e2)
{
    //判断线段是否相交
    //1.快速排斥试验判断以两条线段为对角线的两个矩形是否相交 
    //2.跨立试验
    //cout << s1.x << " " << s1.y << endl;
    //cout << e1.x << " " << e1.y << endl;
    //cout << s2.x << " " << s2.y << endl;
    //cout << e2.x << " " << e2.y << endl;
    if(
		(max(s1.x, e1.x) >= min(s2.x, e2.x)) &&
		(max(s2.x, e2.x) >= min(s1.x, e1.x)) &&
		(max(s1.y, e1.y) >= min(s2.y, e2.y)) &&
		(max(s2.y, e2.y) >= min(s1.y, e1.y)) &&
		(multi(s2, e1, s1) * multi(e1, e2, s1) >= 0) &&
		(multi(s1, e2, s2) * multi(e2, e1, s2) >= 0)
		)  return true;
	
    return false;    
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
    //cout << "交点坐标" << endl; 
    //cout << a1 * tmp.x + b1 * tmp.y + c1 << endl;
    //cout << a2 * tmp.x + b2 * tmp.y + c2 << endl;
	return tmp;
}

void FindConcavePoint(TPolygon p)
{
    int i, n;
    n = p.n;
    t = 0;
    for(i = 0;i < n;i++){
        if(TriangleArea(p.vertice[i], p.vertice[(i + 1) % n], 
           p.vertice[(i + 2) % n]) < 0) ConcavePoint[t++] = i;       
    }
}

int slove1(TPoint &tmp, TPolygon polygon, int p1, int p2)
{
    int i, n;
    TPoint infp1, infp2;
    TLine l1, l2;
    n = polygon.n;
    l1 = lineFromSegment(polygon.vertice[p1], polygon.vertice[p2]);
    double a = l1.a;
    double b = l1.b;
    double c = l1.c;  
    if(fabs(b) < eps) {
        infp1.x = -c / a;
        infp1.y = -inf;
        infp2.x = -c / a;
        infp2.y = inf;
    }
    else {
        infp1.x = -inf;
        infp1.y = (-c - a * infp1.x) / b;
        infp2.x = inf;
        infp2.y = (-c - a * infp2.y) / b;
    }
    
    for(i = 0;i < n;i++){
        if(IsParallel(polygon.vertice[i], polygon.vertice[(i + 1) % n],
            infp1, infp2)) continue;
        if(isIntersected(polygon.vertice[i], polygon.vertice[(i + 1) % n], infp1, infp2)){
            l2 =  lineFromSegment(polygon.vertice[i], polygon.vertice[(i + 1) % n]);
            tmp = LineInter(l1, l2);
            return 1;
        }    
    }
    return 0;
} 

int slove(TPolygon polygon)
{
    int i, n, p0, p1, p2;
    TPoint tmp;
    n = polygon.n;
    for(i = 0;i <= t - 1;i++){
        p0 = ConcavePoint[i];
        p1 = (ConcavePoint[i] + 1) % n;
        p2 = (ConcavePoint[i] + 2) % n;
        if(slove1(tmp, polygon, p0, p1)){
        }
        
        

    }
}

int main()
{
    int test, i, j;
    TPolygon polygon;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &polygon.n);
        for(i = 0;i <= polygon.n - 1;i++){
            scanf("%lf%lf", &xx, &yy);
        }
        if(polygonArea(polygon) < 0) change(polygon);
        FindConcavePoint(polygon);
        if(slove(polygon)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;  
}
