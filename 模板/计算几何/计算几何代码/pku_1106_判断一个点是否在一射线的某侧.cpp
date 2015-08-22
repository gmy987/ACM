
/*
先把到圆心距离大于半径的删除掉，枚举每个点所在的直径，
统计一下在其下方的点的个数，取最大值
注意边界 
*/

#include <stdio.h>
#include <math.h>

typedef struct TPoint 
{
	double x;
	double y;
}TPoint;

typedef struct Tcircle
{
	TPoint center;
	double r;
}TCircle;

double distance(TPoint p1, TPoint p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double multi(TPoint p1, TPoint p2, TPoint p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

int main()
{
	TCircle circle;
	TPoint p0, p[155] ;
	int n, i, j, maxnum, num;
	
	while(scanf("%lf%lf%lf", &circle.center.x, &circle.center.y, &circle.r) != EOF){
		if(circle.r < 0.0) break;
		scanf("%d", &n);
		j = 0;
		for(i = 1;i <= n;i++){
			scanf("%lf%lf", &p0.x, &p0.y);
			if(distance(circle.center, p0) <= circle.r){
				p[j] = p0;
				j++;
			}
		}
		n = j;
		maxnum = -1;
		for(i = 0;i <= n - 1;i++){
			num = 1;
			for(j = 0;j <= n - 1;j++){
				if(i != j && multi(p[i], p[j], circle.center) <= 0) num++;
			}
			if(num > maxnum) maxnum = num;
		}
		if(maxnum < 0) printf("0\n");
		else printf("%d\n", maxnum);
	}
	return 0;	
}


