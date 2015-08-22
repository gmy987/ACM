/*
判断点q是否在多边形内的一种方法，过q作水平射线L，
如果L与多边形P的边界不相交，则q在P的外部。否则，
L和P的边界相交，具体地说，交点个数为奇（偶）数
时，点q在P的内（外）部。 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MaxNode 50
#define INF  999999999
typedef struct TPoint
{
    double x;
    double y;    
}TPoiont;

typedef struct TSegment
{
    
    TPoint p1;
    TPoint p2;
}TSegment;

typedef struct TPolygon
{
    TPoint point[MaxNode];
    int n;
}TPolygon;

double multi(TPoint p1, TPoint p2, TPoint p0)
{
    //求矢量[p0, p1], [p0, p2]的叉积
    //p0是顶点 
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
    //若结果等于0，则这三点共线
    //若结果大于0，则p0p2在p0p1的逆时针方向
    //若结果小于0，则p0p2在p0p1的顺时针方向 
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

bool Intersect(TSegment L1, TSegment L2)
{
    //线段l1与l2相交而且不在端点上时，返回true    
    //判断线段是否相交
    //1.快速排斥试验判断以两条线段为对角线的两个矩形是否相交 
    TPoint s1 = L1.p1;
    TPoint e1 = L1.p2;
    TPoint s2 = L2.p1;
    TPoint e2 = L2.p2;
    //2.跨立试验
    if(
    (max(s1.x, e1.x) > min(s2.x, e2.x)) &&
    (max(s2.x, e2.x) > min(s1.x, e1.x)) &&
    (max(s1.y, e1.y) > min(s2.y, e2.y)) &&
    (max(s2.y, e2.y) > min(s1.y, e1.y)) &&
    (multi(s2, e1, s1) * multi(e1, e2, s1) > 0) &&
    (multi(s1, e2, s2) * multi(e2, e1, s2) > 0)
    )  return true;
    
    return false;    
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

bool same1(TSegment L, TPoint p1, TPoint p2)
{
    //判断p1, p2是否在L的同侧 
    if(multi(p1, L.p2, L.p1) * multi(L.p2, p2, L.p1)< 0) return true;
    return false;
    
}

bool Inside(TPoint q, TPolygon polygon)
{
    int c, i;
    TSegment L1, L2;
    c = 0;
    L1.p1 = q;
    L1.p2 = q;
    L1.p2.x = INF; 
    /*
    （1）相交 
    1.p[i]和p[i+1]在L的两侧 
    2.p[i]和p[i+2]在L的同侧
    3.p[u]和p[i+3]在L的同侧或异侧 
    */
    for(i = 0;i <= polygon.n - 1;i++){
        L2.p1 = polygon.point[i];
        L2.p2 = polygon.point[(i + 1) % polygon.n];
        if(Intersect(L1, L2)){
            c++; 
            continue;
        }
        if(!Online(L1, polygon.point[(i + 1) % polygon.n])) continue; 
        if(!Online(L1, polygon.point[(i + 2) % polygon.n]) && 
            !same1(L1, polygon.point[i], polygon.point[(i + 2) % polygon.n])){
                c++;
                continue;
         }
         if(Online(L1, polygon.point[(i + 2) % polygon.n]) && 
            !same1(L1, polygon.point[i], polygon.point[(i + 3) % polygon.n]))
           c++;
    }  
    if(c % 2 == 0) return false;
    else return true;
}

int main()
{
    int i, test;
    TPoint p;
    p.x = 0;
    p.y = 0;
    test = 1;
    TPolygon polygon;
    while(scanf("%d", &polygon.n) != EOF && polygon.n){
        printf("Pilot %d\n", test++);
        for(i = 0;i <= polygon.n - 1;i++){
            scanf("%lf%lf", &polygon.point[i].x, &polygon.point[i].y);
        }
        if(Inside(p, polygon)) 
            printf("The point is in Polygon!\n");
        else printf("The pilot is not in Polygon.\n");
    }
    return 0;
}
 
