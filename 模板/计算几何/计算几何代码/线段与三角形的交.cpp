/*usaco3_4*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define Maxn 205
#define eps 1e-6

typedef struct TPoint
{
	double x, y;
}TPoint;

typedef struct SEG
{
	TPoint p1, p2;
	int p1num, p2num;
}SEG;

typedef struct ANGLE
{
	double l, r;
}ANGLE;

typedef struct TLine
{
	double a, b, c;
}TLine;

struct ANS
{
	int left, right;
};

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

int IsSame(TPoint p1, TPoint p2)
{
	if(fabs(p1.x - p2.x) > eps) return 0;
	if(fabs(p1.y - p2.y) > eps) return 0;
	return 1;
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

int parallel(TPoint s1, TPoint e1, TPoint s2, TPoint e2)
{
	if(fabs((s1.y - e1.y) * (s2.x - e2.x) 
	   - (s2.y - e2.y) * (s1.x - e1.x)) < eps) return 1;
	else return 0;
}

int cmp(const void *a, const void *b)
{
	ANGLE *c = (ANGLE *)a;
	ANGLE *d = (ANGLE *)b;
	if(c->l < d->l) return -1;
	else return 1;
}

int cmp1(const void *a, const void *b)
{
	struct ANS *c = (struct ANS *)a;
	struct ANS *d = (struct ANS *)b;
	if(c->right < d->right) return -1;
	else if(c->right > d->right) return 1;
	else {
		if(c->left < d->left) return -1;
		else return 1;
	}
}

int isIntersected(TPoint s1, TPoint e1, TPoint s2, TPoint e2)
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
    )  return 1;
    
    return 0;    
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
	return tmp;
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

double AreaOfTriangle(TPoint p1, TPoint p2, TPoint p3)
{
	return fabs((p1.x - p3.x) * (p2.y - p3.y) 
	        - (p1.y - p3.y) * (p2.x - p3.x)) / 2;
}

int isPointInTriangle(TPoint p, TPoint p1, TPoint p2, TPoint p3)
{
	double area1 = 0, area2 = 0;
	
	area1 = AreaOfTriangle(p1, p2, p)
	      + AreaOfTriangle(p1, p3, p)
		  + AreaOfTriangle(p2, p3, p);
    area2 = AreaOfTriangle(p1, p2, p3);
    
    if(fabs(area1 - area2) < eps) return 1;
    else return 0;	
}

double get_angle(TPoint p1, TPoint p2, TPoint point)
{
    //这里可以用余弦定理做 
	TPoint p3, p4;
	double tmpa, tmpb, tmpc, tmpd;
	p3.x = p1.x - point.x;
	p3.y = p1.y - point.y;
	p4.x = p2.x - point.x;
	p4.y = p2.y - point.y;
	tmpa = p3.x * p4.x + p3.y * p4.y;
	
	tmpb = distance(p1, point);
	tmpc = distance(p2, point);	
	tmpd = tmpa / tmpb / tmpc;
	if(tmpd > 1) tmpd = 1;
	if(tmpd < -1) tmpd = -1;
	return acos(tmpd);	
}


int find_point_2(TPoint point, SEG seg1, SEG seg2, SEG &segtmp)
{
	/*找出线段seg2在point，和线段seg1组成的三角形的两个交点*/
	TLine l1, l2;
	TPoint p[3];
	int n = 0;
	if(parallel(seg2.p1, seg2.p2, point, seg1.p1)
	    || parallel(seg2.p1, seg2.p2, point, seg1.p2)){ return 0;}
	if(isPointInTriangle(seg2.p1, point, seg1.p1, seg1.p2) 
	   && isPointInTriangle(seg2.p2, point, seg1.p1, seg1.p2)){
			 segtmp.p1 = seg2.p1;
			 segtmp.p2 = seg2.p2;
		 return 1;	
	}
	if(isIntersected(point, seg1.p1, seg2.p1, seg2.p2)){
		l1 = lineFromSegment(point, seg1.p1);
		l2 = lineFromSegment(seg2.p1, seg2.p2);
		p[n] = LineInter(l1, l2);
		n++;		
	}
	if(isIntersected(point, seg1.p2, seg2.p1, seg2.p2)){
		l1 = lineFromSegment(point, seg1.p2);
		l2 = lineFromSegment(seg2.p1, seg2.p2);
		p[n] = LineInter(l1, l2);
		n++;		
	}
	if(isIntersected(seg1.p1, seg1.p2, seg2.p1, seg2.p2)){
		l1 = lineFromSegment(seg1.p1, seg1.p2);
		l2 = lineFromSegment(seg2.p1, seg2.p2);
		p[n] = LineInter(l1, l2);
		n++;
	}
    if(n == 3){
		if(!IsSame(p[0], p[1])){
			segtmp.p1 = p[0];
			segtmp.p2 = p[1];
		}
		else {
			segtmp.p1 = p[0];
			segtmp.p2 = p[2];
		}
		return 1;
	}
	else if(n == 0) return 0;
	else if(n == 2){
		if(!IsSame(p[0], p[1])){
			segtmp.p1 = p[0];
			segtmp.p2 = p[1];
			return 1;
		}
		else {
			if(isPointInTriangle(seg2.p1, point, seg1.p1, seg1.p2)){
				segtmp.p1 = p[0];
				segtmp.p2 = seg2.p1;	
				if(IsSame(segtmp.p2, segtmp.p1)) return 0;	
				return 1;		
			}
			if(isPointInTriangle(seg2.p2, point, seg1.p1, seg1.p2)){
				segtmp.p1 = p[0];
				segtmp.p2 = seg2.p2;			
				if(IsSame(segtmp.p2, segtmp.p1)) return 0;	
				return 1;					
			}
		} 
		return 0;
	}
	else if(n == 1){
		segtmp.p1 = p[0];
		if(isPointInTriangle(seg2.p1, point, seg1.p1, seg1.p2) 
		   && !IsSame(seg2.p1, segtmp.p1)){
			segtmp.p2 = seg2.p1;
			return 1;
		}
		else if(isPointInTriangle(seg2.p2, point, seg1.p1, seg1.p2) 
		     && !IsSame(seg2.p2, segtmp.p1)){
			segtmp.p2 = seg2.p2;
			return 1;
		}
		return 0;
	}
}

int main()
{
	freopen("fence4.in", "r", stdin);
	freopen("fence4.out", "w", stdout);
	int i, j, pn, segn, anglen, ansn;
	int flag1, flag2, flag3, tag;
	double max_angle, angle1, angle2, end;
	ANGLE angle[Maxn];
	TPoint p[Maxn];
	ANS ans[Maxn];
	TPoint point, mid;
	SEG seg[Maxn], segtmp;
	scanf("%d", &pn);
	segn = 0;
	scanf("%lf%lf", &point.x, &point.y);
	scanf("%lf%lf", &p[0].x, &p[0].y);
	for(i = 1;i < pn;i++){
		scanf("%lf%lf", &p[i].x, &p[i].y);	
		seg[segn].p1 = p[i - 1];
		seg[segn].p2 = p[i];
		seg[segn].p1num = i - 1;
		seg[segn++].p2num = i;	
	}
	seg[segn].p1 = p[pn - 1];
	seg[segn].p2 = p[0];
	seg[segn].p1num = pn - 1;
	seg[segn++].p2num = 0;
	ansn = 0;
	for(i = 0;i <= segn - 1;i++){
		max_angle = get_angle(seg[i].p1, seg[i].p2, point);
		if(fabs(max_angle) < eps) continue;
		anglen = 0;
		for(j = 0;j <= segn - 1;j++){
			if(i == j) continue;
			if(find_point_2(point, seg[i], seg[j], segtmp)){
				if(IsSame(segtmp.p1, segtmp.p2))continue; 
				angle1 = get_angle(segtmp.p1, seg[i].p2, point);
				angle2 = get_angle(segtmp.p2, seg[i].p2, point);
				if(angle1 < angle2){
					angle[anglen].l = angle1;	
					angle[anglen++].r = angle2;
				}
				else {
					angle[anglen].l = angle2;	
					angle[anglen++].r = angle1;
				}				
			}
		}
		qsort(angle, anglen, sizeof(angle[0]), cmp);
		tag = 0;
		if(anglen == 0 || angle[0].l > eps) tag = 1;
		else {
			end = angle[0].r;
			for(j = 1;j < anglen;j++){
				if(angle[j].l - end > eps){
					tag = 1;
					break;
				}
				else if(angle[j].r - end > eps) end = angle[j].r;	
			}
			if(max_angle- end > eps) tag = 1;
		}
		if(tag == 1){
			if(seg[i].p1num < seg[i].p2num) {
				ans[ansn].left = seg[i].p1num;
				ans[ansn++].right = seg[i].p2num;
			}
			else {
				ans[ansn].left = seg[i].p2num;
				ans[ansn++].right = seg[i].p1num;
			}
		}
	}
	if(ansn == 0){
		printf("NOFENCE\n");
		return 0;
	}
	qsort(ans, ansn, sizeof(ans[0]), cmp1);	
	printf("%d\n", ansn);
	for(i = 0;i < ansn;i++){
		printf("%.0lf %.0lf %.0lf %.0lf\n", p[ans[i].left].x, 
		   p[ans[i].left].y, p[ans[i].right].x, p[ans[i].right].y);
	}
	return 0;
}
