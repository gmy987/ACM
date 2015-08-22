/*
如果两点的连线不和墙相交，那么在图中为这两点连一条边，权值为这两点的距离
然后做 Dijkstra
*/
#include <stdio.h>
#include <math.h>

const double inf = 99999999.0;

typedef struct TPoint 
{
	double x, y;
}TPoint;

typedef struct SEG
{
	TPoint down;
	TPoint up;
}SEG;
SEG seg[200];

double map[200][200];

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

bool isIntersected(TPoint s1, TPoint e1, TPoint s2, TPoint e2)
{
    //判断线段是否相交
    //1.快速排斥试验判断以两条线段为对角线的两个矩形是否相交 
    //2.跨立试验
    if(
		(max(s1.x, e1.x) > min(s2.x, e2.x)) &&
		(max(s2.x, e2.x) > min(s1.x, e1.x)) &&
		(max(s1.y, e1.y) > min(s2.y, e2.y)) &&
		(max(s2.y, e2.y) > min(s1.y, e1.y)) &&
		(multi(s2, e1, s1) * multi(e1, e2, s1) >= 0) &&
		(multi(s1, e2, s2) * multi(e2, e1, s2) >= 0)
		)  return true;
    
    return false;    
}

int check(TPoint p1, TPoint p2, int tsegn)
{
	int j;
	for(j = 0;j <= tsegn - 1;j++){
		if(isIntersected(p1, p2, seg[j].down, seg[j].up)) return 0;		
	}
	return 1;	
}

int main()
{
	double dijkstra(int pn);
	int n, i, j, k, tpn, tsegn, pn, segn;
	double x, y1, y2, y3, y4;
	TPoint p[100];
	while(scanf("%d", &n) && n != -1){
		for(i = 0;i < 4 * n + 2;i++){
			map[i][i] = 0.0;
			for(j = i + 1;j < 4 * n + 2;j++){
				map[i][j] = inf;
				map[j][i] = inf;
			}
		}
		p[0].x = 0;
		p[0].y = 5;
		pn = 1;
		segn = 0;
		for(i = 1;i <= n;i++){
			scanf("%lf%lf%lf%lf%lf", &x, &y1, &y2, &y3, &y4);
			tpn = pn;
			tsegn = segn;  
			p[pn].x = x;
			p[pn++].y = y1;
			p[pn].x = x;
			p[pn++].y = y2;
			p[pn].x = x;
			p[pn++].y = y3;
			p[pn].x = x;
			p[pn++].y = y4;	
			seg[segn].down.x = x;
			seg[segn].down.y = 0;
			seg[segn].up.x = x;
			seg[segn++].up.y = y1;
			seg[segn].down.x = x;
			seg[segn].down.y = y2;
			seg[segn].up.x = x;
			seg[segn++].up.y = y3;
			seg[segn].down.x = x;
			seg[segn].down.y = y4;
			seg[segn].up.x = x;
			seg[segn].up.y = 10;
			for(k = pn - 1;k >= pn - 4;k--){
				for(j = 0;j <= tpn - 1;j++){
					if(check(p[k], p[j], tsegn)){
						map[k][j] = distance(p[k], p[j]);
						map[j][k] = map[k][j];
					}
				}
			}
		} 
		tpn = pn;
		p[pn].x = 10;
		p[pn++].y = 5;
		for(j = 0;j <= tpn - 1;j++){
			if(check(p[pn - 1], p[j], segn)){
				map[pn - 1][j] = distance(p[pn - 1], p[j]);
				map[j][pn - 1] = map[pn - 1][j];
			}
		}
		printf("%.2lf\n", dijkstra(pn));
	}
	return 0;	
}

double dijkstra(int pn)
{
	int s[100], i, j, u;
	double dis[100], mindis;
	for(i = 0;i <= pn - 1;i++){
		s[i] = 0;
		dis[i] = map[0][i];
	}
	s[0] = 1;
	for(i = 0;i <= pn - 1;i++){
		mindis = inf;
		for(j = 0;j <= pn - 1;j++){
			if(s[j] == 0 && dis[j] < mindis){
				u = j;
				mindis = dis[j];
			}
		}
		s[u] = 1;
		if(u == pn - 1) return dis[pn - 1];
		for(j = 0;j <= pn - 1;j++){
			if(s[j] == 0 && dis[u] + map[u][j] < dis[j]){				
				dis[j] = dis[u] + map[u][j];				
			}
		}
	}
	return dis[pn - 1];
}
