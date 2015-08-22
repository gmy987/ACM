/*
ID:chenhai2
PROG:fence4
LANG: C++
*/
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
//	printf("ksdfja;l\n");
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

/*
------- test 1 -------
13
5 5
0 0
7 0
5 2
7 5
5 7
3 5
4 9
1 8
2 5
0 9
-2 7
0 3
-3 1
------- test 2 -------
4
1 1
0 0
2 0
2 2
0 2
------- test 3 -------
4
1 -10
0 0
2 0
2 2
0 2
------- test 4 -------
12
1 -10
0 0
1 0
2 0
3 0
3 1
3 2
3 3
2 3
1 3
0 3
0 2
0 1
------- test 5 -------
4
100 100
0 0
2 0
2 2
0 2
------- test 6 -------
199
10 10
0 0
1 0
2 0
3 0
4 0
5 0
6 0
7 0
8 0
9 0
10 0
11 0
12 0
13 0
14 0
15 0
16 0
17 0
18 0
19 0
20 0
21 0
22 0
23 0
24 0
25 0
26 0
27 0
28 0
29 0
30 0
31 0
32 0
33 0
34 0
35 0
36 0
37 0
38 0
39 0
40 0
41 0
42 0
43 0
44 0
45 0
46 0
47 0
48 0
49 0
50 0
50 1
50 2
50 3
50 4
50 5
50 6
50 7
50 8
50 9
50 10
50 11
50 12
50 13
50 14
50 15
50 16
50 17
50 18
50 19
50 20
50 21
50 22
50 23
50 24
50 25
50 26
50 27
50 28
50 29
50 30
50 31
50 32
50 33
50 34
50 35
50 36
50 37
50 38
50 39
50 40
50 41
50 42
50 43
50 44
50 45
50 46
50 47
50 48
50 49
50 50
49 50
48 50
47 50
46 50
45 50
44 50
43 50
42 50
41 50
40 50
39 50
38 50
37 50
36 50
35 50
34 50
33 50
32 50
31 50
30 50
29 50
28 50
27 50
26 50
25 50
24 50
23 50
22 50
21 50
20 50
19 50
18 50
17 50
16 50
15 50
14 50
13 50
12 50
11 50
10 50
9 50
8 50
7 50
6 50
5 50
4 50
3 50
2 50
1 50
0 50
0 49
0 48
0 47
0 46
0 45
0 44
0 43
0 42
0 41
0 40
0 39
0 38
0 37
0 36
0 35
0 34
0 33
0 32
0 31
0 30
0 29
0 28
0 27
0 26
0 25
0 24
0 23
0 22
0 21
0 20
0 19
0 18
0 17
0 16
0 15
0 14
0 13
0 12
0 11
0 10
0 9
0 8
0 7
0 6
0 5
0 4
0 3
0 2
------- test 7 -------
199
-10 10
0 0
1 0
2 0
3 0
4 0
5 0
6 0
7 0
8 0
9 0
10 0
11 0
12 0
13 0
14 0
15 0
16 0
17 0
18 0
19 0
20 0
21 0
22 0
23 0
24 0
25 0
26 0
27 0
28 0
29 0
30 0
31 0
32 0
33 0
34 0
35 0
36 0
37 0
38 0
39 0
40 0
41 0
42 0
43 0
44 0
45 0
46 0
47 0
48 0
49 0
50 0
50 1
50 2
50 3
50 4
50 5
50 6
50 7
50 8
50 9
50 10
50 11
50 12
50 13
50 14
50 15
50 16
50 17
50 18
50 19
50 20
50 21
50 22
50 23
50 24
50 25
50 26
50 27
50 28
50 29
50 30
50 31
50 32
50 33
50 34
50 35
50 36
50 37
50 38
50 39
50 40
50 41
50 42
50 43
50 44
50 45
50 46
50 47
50 48
50 49
50 50
49 50
48 50
47 50
46 50
45 50
44 50
43 50
42 50
41 50
40 50
39 50
38 50
37 50
36 50
35 50
34 50
33 50
32 50
31 50
30 50
29 50
28 50
27 50
26 50
25 50
24 50
23 50
22 50
21 50
20 50
19 50
18 50
17 50
16 50
15 50
14 50
13 50
12 50
11 50
10 50
9 50
8 50
7 50
6 50
5 50
4 50
3 50
2 50
1 50
0 50
0 49
0 48
0 47
0 46
0 45
0 44
0 43
0 42
0 41
0 40
0 39
0 38
0 37
0 36
0 35
0 34
0 33
0 32
0 31
0 30
0 29
0 28
0 27
0 26
0 25
0 24
0 23
0 22
0 21
0 20
0 19
0 18
0 17
0 16
0 15
0 14
0 13
0 12
0 11
0 10
0 9
0 8
0 7
0 6
0 5
0 4
0 3
0 2
------- test 8 -------
199
-2 -10
0 0
1 1
0 1
1 2
0 2
1 3
0 3
1 4
0 4
1 5
0 5
1 6
0 6
1 7
0 7
1 8
0 8
1 9
0 9
1 10
0 10
1 11
0 11
1 12
0 12
1 13
0 13
1 14
0 14
1 15
0 15
1 16
0 16
1 17
0 17
1 18
0 18
1 19
0 19
1 20
0 20
1 21
0 21
1 22
0 22
1 23
0 23
1 24
0 24
1 25
0 25
1 26
0 26
1 27
0 27
1 28
0 28
1 29
0 29
1 30
0 30
1 31
0 31
1 32
0 32
1 33
0 33
1 34
0 34
1 35
0 35
1 36
0 36
1 37
0 37
1 38
0 38
1 39
0 39
1 40
0 40
1 41
0 41
1 42
0 42
1 43
0 43
1 44
0 44
1 45
0 45
1 46
0 46
1 47
0 47
1 48
0 48
1 49
0 49
1 50
0 50
1 51
0 51
1 52
0 52
1 53
0 53
1 54
0 54
1 55
0 55
1 56
0 56
1 57
0 57
1 58
0 58
1 59
0 59
1 60
0 60
1 61
0 61
1 62
0 62
1 63
0 63
1 64
0 64
1 65
0 65
1 66
0 66
1 67
0 67
1 68
0 68
1 69
0 69
1 70
0 70
1 71
0 71
1 72
0 72
1 73
0 73
1 74
0 74
1 75
0 75
1 76
0 76
1 77
0 77
1 78
0 78
1 79
0 79
1 80
0 80
1 81
0 81
1 82
0 82
1 83
0 83
1 84
0 84
1 85
0 85
1 86
0 86
1 87
0 87
1 88
0 88
1 89
0 89
1 90
0 90
1 91
0 91
1 92
0 92
1 93
0 93
1 94
0 94
1 95
0 95
1 96
0 96
1 97
0 97
1 98
0 98
-1 1
-1 0
------- test 9 -------
199
-1 10
0 0
2 1
0 1
2 2
0 2
2 3
0 3
2 4
0 4
2 5
0 5
2 6
0 6
2 7
0 7
2 8
0 8
2 9
0 9
2 10
0 10
2 11
0 11
2 12
0 12
2 13
0 13
2 14
0 14
2 15
0 15
2 16
0 16
2 17
0 17
2 18
0 18
2 19
0 19
2 20
0 20
2 21
0 21
2 22
0 22
2 23
0 23
2 24
0 24
2 25
0 25
2 26
0 26
2 27
0 27
2 28
0 28
2 29
0 29
2 30
0 30
2 31
0 31
2 32
0 32
2 33
0 33
2 34
0 34
2 35
0 35
2 36
0 36
2 37
0 37
2 38
0 38
2 39
0 39
2 40
0 40
2 41
0 41
2 42
0 42
2 43
0 43
2 44
0 44
2 45
0 45
2 46
0 46
2 47
0 47
2 48
0 48
2 49
0 49
2 50
0 50
2 51
0 51
2 52
0 52
2 53
0 53
2 54
0 54
2 55
0 55
2 56
0 56
2 57
0 57
2 58
0 58
2 59
0 59
2 60
0 60
2 61
0 61
2 62
0 62
2 63
0 63
2 64
0 64
2 65
0 65
2 66
0 66
2 67
0 67
2 68
0 68
2 69
0 69
2 70
0 70
2 71
0 71
2 72
0 72
2 73
0 73
2 74
0 74
2 75
0 75
2 76
0 76
2 77
0 77
2 78
0 78
2 79
0 79
2 80
0 80
2 81
0 81
2 82
0 82
2 83
0 83
2 84
0 84
2 85
0 85
2 86
0 86
2 87
0 87
2 88
0 88
2 89
0 89
2 90
0 90
2 91
0 91
2 92
0 92
2 93
0 93
2 94
0 94
2 95
0 95
2 96
0 96
2 97
0 97
2 98
0 98
-2 1
-2 0
------- test 10 -------
199
10 10
0 0
1 1
0 1
1 2
0 2
1 3
0 3
1 4
0 4
1 5
0 5
1 6
0 6
1 7
0 7
1 8
0 8
1 9
0 9
1 10
0 10
1 11
0 11
1 12
0 12
1 13
0 13
1 14
0 14
1 15
0 15
1 16
0 16
1 17
0 17
1 18
0 18
1 19
0 19
1 20
0 20
1 21
0 21
1 22
0 22
1 23
0 23
1 24
0 24
1 25
0 25
1 26
0 26
1 27
0 27
1 28
0 28
1 29
0 29
1 30
0 30
1 31
0 31
1 32
0 32
1 33
0 33
1 34
0 34
1 35
0 35
1 36
0 36
1 37
0 37
1 38
0 38
1 39
0 39
1 40
0 40
1 41
0 41
1 42
0 42
1 43
0 43
1 44
0 44
1 45
0 45
1 46
0 46
1 47
0 47
1 48
0 48
1 49
0 49
1 50
0 50
1 51
0 51
1 52
0 52
1 53
0 53
1 54
0 54
1 55
0 55
1 56
0 56
1 57
0 57
1 58
0 58
1 59
0 59
1 60
0 60
1 61
0 61
1 62
0 62
1 63
0 63
1 64
0 64
1 65
0 65
1 66
0 66
1 67
0 67
1 68
0 68
1 69
0 69
1 70
0 70
1 71
0 71
1 72
0 72
1 73
0 73
1 74
0 74
1 75
0 75
1 76
0 76
1 77
0 77
1 78
0 78
1 79
0 79
1 80
0 80
1 81
0 81
1 82
0 82
1 83
0 83
1 84
0 84
1 85
0 85
1 86
0 86
1 87
0 87
1 88
0 88
1 89
0 89
1 90
0 90
1 91
0 91
1 92
0 92
1 93
0 93
1 94
0 94
1 95
0 95
1 96
0 96
1 97
0 97
1 98
0 98
-1 1
-1 0
------- test 11 -------
7
1 3
1 1
-2 1
1 -4
3 2
1 2
2 0
0 0
----------------------

*/
