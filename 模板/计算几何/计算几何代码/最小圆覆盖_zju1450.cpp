/*
 
包含点集所有点的最小圆的算法
最小圆覆盖 

 http://acm.zju.edu.cn/show_problem.php?pid=1450
 
 相关题目最小球包含  http://acm.pku.edu.cn/JudgeOnline/problem?id=2069 

平面上有n个点，给定n个点的坐标，试找一个半径最小的圆，将n
个点全部包围，点可以在圆上。 

1. 在点集中任取3点A,B,C。
2. 作一个包含A,B,C三点的最小圆,圆周可能通过这3点，也可能只通过
其中两点,但包含第3点.后一种情况圆周上的两点一定是位于圆的一条直
径的两端。
3. 在点集中找出距离第2步所建圆圆心最远的D点，若D点已在圆内或圆周上，
则该圆即为所求的圆，算法结束.则，执行第4步。
4. 在A,B,C,D中选3个点,使由它们生成的一个包含这4个点的圆为最小，这3
点成为新的A,B,C，返回执行第2步。若在第4步生成的圆的圆周只通过A,B,C,D
中的两点，则圆周上的两点取成新的A和B,从另两点中任取一点作为新的C。

程序设计题解上的解题报告：
对于一个给定的点集A，记MinCircle(A)为点集A的最小外接圆，显然，对于所
有的点集情况A,MinCircle(A)都是存在且惟一的。需要特别说明的是，当A为空
集时，MinCircle(A)为空集，当A={a}时，MinCircle(A)圆心坐标为a，半径为0；
   显然，MinCircle(A)可以有A边界上最多三个点确定(当点集A中点的个数大于
1时，有可能两个点确定了MinCircle(A))，也就是说存在着一个点集B，|B|<=3
且B包含与A，有MinCircle(B)=MinCircle(A).所以，如果a不属于B，则
MinCircle(A-{a})=MinCircle(A);如果MinCircle(A-{a})不等于MinCircle(A),则
a属于B。
    所以我们可以从一个空集R开始，不断的把题目中给定的点集中的点加入R，同
时维护R的外接圆最小，这样就可以得到解决该题的算法。 

pku2069

*/
#include <stdio.h>
#include <math.h>

const int maxn = 1005;
//const double eps = 1e-6;

struct TPoint
{
	double x, y;
	TPoint operator-(TPoint &a)
	{
		TPoint p1;
		p1.x = x - a.x;
		p1.y = y - a.y;
		return p1;
	}
};

struct TCircle
{
	double r;
	TPoint centre;
};

struct TTriangle
{
	TPoint t[3];
};

TCircle c;
TPoint a[maxn];

double distance(TPoint p1, TPoint p2)
{
	TPoint p3;
	p3.x = p2.x - p1.x;
	p3.y = p2.y - p1.y;
	return sqrt(p3.x * p3.x + p3.y * p3.y);
}

double triangleArea(TTriangle t)
{
	TPoint p1, p2;
	p1 = t.t[1] - t.t[0];
	p2 = t.t[2] - t.t[0];
	return fabs(p1.x * p2.y - p1.y * p2.x) / 2;
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
         ((xA - xB) * (yA - yC) - (xA - xC) * (yA - yB)); 
    tmp.centre.y = (c1 * (xA - xC) - c2 * (xA - xB)) / 
         ((yA - yB) * (xA - xC) - (yA - yC) * (xA - xB)); 
         
    return tmp;     
}

TCircle MinCircle2(int tce, TTriangle ce)
{
	TCircle tmp;
	if(tce == 0) tmp.r = -2;
	else if(tce == 1) 
	{
		tmp.centre = ce.t[0];
		tmp.r = 0;
	}
	else if(tce == 2)
	{
		tmp.r = distance(ce.t[0], ce.t[1]) / 2;
		tmp.centre.x = (ce.t[0].x + ce.t[1].x) / 2;
		tmp.centre.y = (ce.t[0].y + ce.t[1].y) / 2; 	
	}
	else if(tce == 3) tmp = circumcircleOfTriangle(ce);
	return tmp;
}

void MinCircle(int t, int tce, TTriangle ce)
{
	int i, j;
	TPoint tmp;
	c = MinCircle2(tce, ce);
	if(tce == 3) return;
	for(i = 1;i <= t;i++)
	{
		if(distance(a[i], c.centre) > c.r)
		{
			ce.t[tce] = a[i];
			MinCircle(i - 1, tce + 1, ce);
			tmp = a[i];
			for(j = i;j >= 2;j--)
			{
				a[j] = a[j - 1];
			}
			a[1] = tmp;
		}
	}
}

void run(int n)
{
	TTriangle ce;
	int i;
	MinCircle(n, 0, ce);
	printf("%.2lf %.2lf %.2lf\n", c.centre.x, c.centre.y, c.r);
}

int main()
{
    freopen("circle.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
	while(scanf("%d", &n) != EOF && n)
	{
		for(int i = 1;i <= n;i++)
			scanf("%lf%lf", &a[i].x, &a[i].y);
		run(n);
	}
	return 0;
}
/*
1
2 2
3
1 1
2 2
3 3
4
0 0
1 0
1 1
0 1
8
1 0
2 0
3 1
2 2
1 2
0 1
2 1
1 1
25
0 0
1 0
2 0
3 0
4 0
0 1
1 1
2 1
3 1
4 1
0 2
1 2
2 2
3 2
4 2
0 3
1 3
2 3
3 3
4 3
0 4
1 4
2 4
3 4
4 4
36
0 0
8 0
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
2 1
8 2
3 1
3 2
8 3
4 1
2 4
3 4
7 4
8 4
5 1
3 5
6 5
8 5
8 1
4 6
8 6
0 8
8 8
7 8
6 6
6 7
7 3
7 4
7 7
5 5
42
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
1 1
2 1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
10 1
11 1
12 1
13 1
14 1
15 1
16 1
17 1
18 1
19 1
20 1
21 1
30
0 0
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0 9
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
2 2
2 3
2 4
2 5
2 6
2 7
3 3
3 4
3 5
3 6
4 4
4 5
15
0 0
0 1
0 2
0 3
2 0
2 1
2 2
2 3
4 0
4 1
4 2
4 3
4 4
5 0
6 0
13
0 3
1 2
2 1
3 0
4 1
4 2
4 3
5 2
6 1
7 0
8 1
9 2
10 3




*/

