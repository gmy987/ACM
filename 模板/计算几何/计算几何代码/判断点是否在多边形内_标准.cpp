#include <stdio.h>
#include <math.h>

#define Maxn 1000
#define eps 1e-6
#define pi acos(-1)
#define inf 9999999

struct TPoint
{
    double x, y;
};

double dispoint(TPoint p1, TPoint p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int pall(TPoint p1, TPoint p2, TPoint p3, TPoint p4)
{
    if(fabs((p1.y - p2.y) * (p3.x - p4.y) 
       - (p1.x - p2.x) * (p3.y - p4.y)))
       return 1;
    else return 0;
}

int IsOnSegment(TPoint p, TPoint p1, TPoint p2)
{
    double d1 = dispoint(p1, p);
    double d2 = dispoint(p, p2);
    double d3 = dispoint(p1, p2);
    if(fabs(d1 + d2 - d3) < eps) return 1;
    else return 0;
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

double multi(TPoint p1, TPoint p2, TPoint p0)
{
    //求矢量[p0, p1], [p0, p2]的叉积
    //p0是顶点 
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
    //若结果等于0，则这三点共线
    //若结果大于0，则p0p2在p0p1的逆时针方向
    //若结果小于0，则p0p2在p0p1的顺时针方向 
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

int IsInPolygon(TPoint p0, TPoint p[], int n)
{
    double a, k;
    TPoint p2;
    int i, j, tag;
    for(a = 1.0;a < pi / 2; a += 1.0){
        k = tan(a);
        p2.x = inf;
        p2.y = p0.y + k * (p2.x - p0.x);
        tag = 0;
        for(i = 0;i < n;i++){
            if(IsOnSegment(p[i], p0, p2)){
                tag = 1;
                break;
            }  
        }
        if(tag == 1) continue;
        for(i = 0;i < n;i++){
            if(pall(p0, p2, p[i], p[i + 1])){
                tag = 1;
                break;
            }
        }
        if(tag == 0) break;
    }
    int num = 0;
    for(i = 0;i < n;i++){
        if(isIntersected(p0, p2, p[i], p[i + 1])){
            num++;
        }
    }
    if(num % 2 == 0) return 0;
    else return 1; 
}

int main()
{
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    TPoint p[Maxn], p0;
    int n, m, i, j, tag, test = 1;
    while(scanf("%d", &n) && n){
        if(test != 1) printf("\n");
        printf("Problem %d:\n", test++);
        scanf("%d", &m);
        for(i = 0;i < n;i++){
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        p[n] = p[0];
        for(i = 1;i <= m;i++){
            scanf("%lf%lf", &p0.x, &p0.y);
            tag = 0;
            for(j = 0;j < n;j++){
                if(IsOnSegment(p0, p[j], p[j + 1])){
                    printf("Within\n");
                    tag = 1;
                    break;
                }
            }
            if(tag == 1) continue;
            if(IsInPolygon(p0, p, n)) printf("Within\n");
            else printf("Outside\n");
        }
    }
    return 0;
}
