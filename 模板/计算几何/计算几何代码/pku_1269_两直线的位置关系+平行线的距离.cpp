#include <stdio.h>
#include <math.h>

typedef struct TPoint 
{
	int x;
	int y;
}TPoint;

typedef struct TLine
{
	int a, b, c;
}TLine;

TLine lineFromSegment(TPoint p1, TPoint p2)
{
    //线段所在直线,返回直线方程的三个系统 
    TLine tmp;
    tmp.a = p2.y - p1.y;
    tmp.b = p1.x - p2.x;
    tmp.c = p2.x * p1.y - p1.x * p2.y;
    return tmp;
}

void LineInter(TLine l1, TLine l2)
{
    //求两直线得交点坐标
    double x, y;
    int a1 = l1.a;
    int b1 = l1.b;
    int c1 = l1.c;
    int a2 = l2.a;
    int b2 = l2.b;
    int c2 = l2.c;
    if(b1 == 0){
        x = -c1 / (double)a1;  
        y = (-c2 - a2 * x) / (double)b2;
    }       
    else{
        x = (double)(c1 * b2 - b1 * c2) / (double)(b1 * a2 - b2 * a1);
        y = (double)(-c1 - a1 * x) /(double)b1;
    }
    printf("POINT %.2lf %.2lf\n", x, y);
}

int main()
{
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	int test;
	TPoint s1, e1, s2, e2;
	TLine l1, l2;
	scanf("%d", &test);
	printf("INTERSECTING LINES OUTPUT\n");
	while(test--){ 
		scanf("%d%d%d%d%d%d%d%d", &s1.x, &s1.y, 
		  &e1.x, &e1.y, &s2.x, &s2.y, &e2.x, &e2.y);
		if((s1.y - e1.y) * (s2.x - e2.x) == (s1.x - e1.x) * (s2.y - e2.y)){
			//平行直线系数相等 
			l1 = lineFromSegment(s1, e1);
			l2.c = -(l1.a * s2.x + l1.b * s2.y);
			if(fabs((l1.c - l2.c) / sqrt(l1.a * l1.a + l1.b * l1.b)) > 0) 
			   printf("NONE\n");
			else printf("LINE\n");
		}
		else {
			l1 = lineFromSegment(s1, e1);
			l2 = lineFromSegment(s2, e2);
			LineInter(l1, l2);	
		}	
	}
	printf("END OF OUTPUT\n");
	return 0;
}
