/*
计算几何相关知识及基本算法 
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MaxNode 100

//自定义常量，类型及通用函数
const double eps = 1e-6;

typedef struct TPoint
{
    //平面点 
    double x;
    double y;
}TPoint; 

typedef struct TSegment
{
    
    TPoint p1;
    TPoint p2;
}TSegment;

typedef struct TTriangle
{
    TPoint t[2];
}TTriangle;

typedef struct TPolygon
{
    //多边形 
    TPoint p[MaxNode];
}TPolygon;

typedef struct TLine
{
    //直线方程的系数 
    double a, b, c;
}TLine;

typedef struct TCircle 
{
    //圆 
    double r;
    TPoint centre;
}TCircle;

bool same(double x, double y)
{
    //判断两个实数是否相等
    if(fabs(x - y) < eps) return true;
    return false;
} 

double max(double x, double y)
{
    //比较两个数的大小，返回大的数
    if(x > y) return x;
    else return y; 
}

double min(double x, double y)
{
    //比较两个数的大小，返回小的数
    if(x < y) return x;
    else return y; 
}

double distance(TPoint p1, TPoint p2)
{
    //计算平面上两个点之间的距离
   return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));    
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

/*
折线的拐向的判断（从p0向p1看过去的左边） 
若 (p2 - p1) 叉乘 (p1 - p0) < 0 ,则p0p1在p1点拐向左侧后得到p1p2
若 (p2 - p1) 叉乘 (p1 - p0) = 0 ,则 p0, p1, p2三点共线
若 (p2 - p1) 叉乘 (p1 - p0) > 0 ,则p0p1在p1点拐向右侧后得到p1p2 
*/


TLine lineFromSegment(TPoint p1, TPoint p2)
{
    //线段所在直线,返回直线方程的三个系统 
    TLine tmp;
    tmp.a = p2.y - p1.y;
    tmp.b = p1.x - p2.x;
    tmp.c = p2.x * p1.y - p1.x * p2.y;
    return tmp;
}

//角形面积的计算 
//  S = ah / 2
//  S = absinC / 2
//  S = sqrt(p * (p - a) * (p - b) * (p - c)), p = (a + b + c) / 2
//  S = abc / R / 4

double triangleArea(TTriangle t)
{
    //已知三角形三个顶点的坐标，求三角形的面积 
    return fabs(t.t[0].x * t.t[1].y + t.t[1].x * t.t[2].y + t.t[2].x * t.t[0].y
      - t.t[1].x * t.t[0].y - t.t[2].x * t.t[1].y - t.t[0].x * t.t[2].y) / 2;   
}

double polygonArea(TPolygon p, int n)
{
    //已知多边形各顶点的坐标，求其面积
    double area;
    int i;
    area = 0;
    for(i = 1;i <= n;i++){
        area += (p.p[i - 1].x * p.p[i % n].y - p.p[i % n].x * p.p[i - 1].y);
    }  
    return fabs(area) / 2;   
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
    
    tmp.centre.x = (c1 * (yA - yC) - c2 * (yA - yB)) / 
         (xA - xB) * (yA - yC) - (xA - xC) * (yA - yB); 
    tmp.centre.y = (c1 * (xA - xC) - c2 * (xA - xB)) / 
         (yA - yB) * (xA - xC) - (yA - yC) * (xA - xB); 
         
    return tmp;     
}

TCircle incircleOfTriangle(TTriangle t)
{
    //三角形的内接圆
    TCircle tmp;
    double a, b, c, angleA, angleB, angleC, p, p2, p3, f1, f2;
    double xA, yA, xB, yB, xC, yC;
    a = distance(t.t[0], t.t[1]);
    b = distance(t.t[1], t.t[2]);
    c = distance(t.t[2], t.t[0]);
    /*
    S = p * r
    p = (a + b + c) / 2;
    r = S / P = 2 * S / (a + b + c)
    */
    tmp.r = 2 * triangleArea(t) / (a + b +c);
    angleA = acos((b * b + c * c - a * a) / (2 * b * c));
    angleB = acos((a * a + c * c - b * b) / (2 * a * c));
    angleC = acos((a * a + b * b - c * c) / (2 * a * b));
    p = sin(angleA / 2);
    p2 = sin(angleB / 2);
    p3 = sin(angleC / 2);
    
    xA = t.t[0].x; yA = t.t[0].y;
    xB = t.t[1].x; yB = t.t[1].y;
    xC = t.t[2].x; yC = t.t[2].y;
    
    f1 = ((tmp.r / p2) * (tmp.r / p2) - (tmp.r / p) * (tmp.r / p) + 
         xA * xA - xB * xB + yA * yA - yB * yB) / 2;
    f2 = ((tmp.r / p3) * (tmp.r / p3) - (tmp.r / p) * (tmp.r / p) + 
         xA * xA - xC * xC + yA * yA - yC * yC) / 2;
    tmp.centre.x = (f1 * (yA - yC) - f2 * (yA - yB)) / 
                   ((xA - xB) * (yA - yC) - (xA - xC) * (yA - yB));
    tmp.centre.y = (f1 * (xA - xC) - f2 * (xA - xB)) / 
                   ((yA - yB) * (xA - xC) - (yA - yC) * (xA - xB));
    return tmp;   
}

bool isPointOnSegment(TPoint p, TPoint p1, TPoint p2)
{
    // 判断p点是否在线段p1p2上
    //1.p是否在直线p1p2上 
    //2.p是否在以p1p2为对角线的矩形中
    if(multi(p1, p2, p) != 0) return false ;
    if((p.x > p1.x && p.x > p2.x) || (p.x < p1.x && p.x < p2.x)) return false;
    if((p.y > p1.y && p.y > p2.y) || (p.y < p1.y && p.y < p2.y)) return false;
    return true;   
}

bool Online(TSegment L, TPoint p)
{
    //p在L上(不在端点)时返回true
    //1.在L所在的直线上 
    //2.在L为对角线的矩形中
    double dx, dy, dx1, dy1;
    dx = L.p2.x - L.p1.x;
    dy = L.p2.y - L.p1.y;
    dx1 = p.x - L.p1.x;
    dy1 = p.y - L.p1.y;
    if(dx * dy1 - dy * dx1 != 0) return false; //叉积
    if(dx1 * (dx1 - dx) < 0 || dy1 * (dy1 - dy) < 0) return true;
    return false; 
}

bool isIntersected(TPoint s1, TPoint e1, TPoint s2, TPoint e2)
{
    //判断线段是否相交
    //1.快速排斥试验判断以两条线段为对角线的两个矩形是否相交 
    //2.跨立试验
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

//判断线段是否和直线相交。比如要判断线段[s1, e1]和直线 L 是否相交，
//只要判断线段[s1, e1]是否跨立 L 即可。

//判断点是否在三角形内
//1.面积判断 
//2.线段的拐向判断

//判断点是否在多边形内，如果多边形为凸多边形，
//下面的两个方法还是适用的，只需要做少量的修改
// 若需要判断的点在凹多边形内，就需采用完全不同
//的方法 
 
bool isPointInTriangle1(TPoint p, TTriangle t)
{
    //判断点是否在三角形内,面积判断 
    TTriangle tmp;
    double area;
    int i, j;
    area = 0;
    for(i = 0;i <= 2;i++){
        for(j = 0;j <= 2;j++){
            if(i == j) tmp.t[j] = p;
            else tmp.t[j] = t.t[j];
        }
        area += triangleArea(tmp);
    }
    return same(area, triangleArea(t));
}

bool isPointInTriangle2(TPoint p, TTriangle t)
{
    //判断点是否在三角形内,线段的拐向判断 
    //APB, BPC, CPA 的拐向都是相同的 
    double k1, k2, k3;
    k1 = multi(t.t[0], t.t[1], p);
    k2 = multi(t.t[1], t.t[2], p);
    k3 = multi(t.t[2], t.t[0], p);
    if(k1 * k2 * k3 != 0){
        if(k1 * k2 < 0) return false;
        if(k1 * k3 < 0) return false;
    }
    return true;
}

TPoint symmetricalPoint(TPoint p1, TPoint p2)
{
    //求p1关于p2的对称点
    TPoint p3;
    p3.x = 2 * p2.x - p1.x;
    p3.y = 2 * p2.y - p1.y;
    
    return p3;
}

TPoint symmetricalPointofLine(TPoint p, TLine L)
{
    //p点关于直线L的对称点 
    TPoint p2;
    double d;
    d = L.a * L.a + L.b * L.b;
    p2.x = (L.b * L.b * p.x - L.a * L.a * p.x - 
            2 * L.a * L.b * p.y - 2 * L.a * L.c) / d;
    p2.y = (L.a * L.a * p.y - L.b * L.b * p.y - 
            2 * L.a * L.b * p.x - 2 * L.b * L.c) / d;
    return p2;
}

//点关于线段的对称点
//首先可以根据线段的两个端点求出线段所在的直线L，然后再来求指定
//点关于直线L的对称点

/*
凸包( Convex Hull )
凸包是对平面是上的某个点集而言的，凸包是一个最小凸多边形，满足点集
中的所有点都在该凸多边形内（或在该多边形的边上）。
通常，我们采用Graham扫描法来求点集的凸包。首先，排序选出点集中最左下
角点（先取y坐标最小的点，若有多个再在其中取x坐标最小的点），设该点为p0；
然后，将其余的按以p0为中心的极角坐标逆时针排序，多于相同极角的点只保留
距离p0最远的一个，这样就可以得到一个点的序列p1,p2, p2.....,pn;接下来，
将p0, p1, p2压入栈，一次处理pi（i >= 2 && i <= n），不断让栈顶的元素出
栈，直到栈顶的下一个元素，栈顶元素，以及pi构成的折线不拐向左侧，将pi压
入栈中；最后栈中的元素即为所求的凸包的顶点序列  
*/ 

void swap(TPoint p[], int i, int j)
{
    TPoint tmp;
    tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
}
int stack[MaxNode];
int top;

int cmp(const void *a, const void *b)
{
    TPoint *c = (TPoint *)a;
    TPoint *d = (TPoint *)b;
    double k = multi(*c, *d, point[0]);
    if(k< 0) return 1;
    else if(k == 0 && distance(*c, point[0]) < distance(*d, point[0])) return 1;
    else return -1;   
}

void grahamScan(TPoint p[], int n)
{ 
    //Graham扫描求凸包
    int i; 
    
    //将最左下的点调整到p[0]的位置
    for(i = 1;i <= n - 1;i++){
        if((p[i].y < p[0].y) || (p[i].y == p[0].y && p[i].x  < p[0].x))
        swap(p, 0, i);
    } 
    
    //将平p[1]到p[n - 1]按按极角排序，可采用快速排序
    qsort(p + 1, , n - 1, sizeof(p[0], cmp));
    
    for(i = 0;i <= 2;i++) stack[i] = i;
    top = 2;
    for(i = 3;i <= n - 1;i++){
        while(multi(p[i], p[stack[top]], p[stack[top - 1]]) > 0)  top--;
    } 
    top++;
    stack[top] = i;  
}

int main()
{
    
}


