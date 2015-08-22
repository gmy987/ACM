/*
大牛的思想 
题目给出 n 个矩形，要求它们的面积并。具体做法是离散化。
先把 2n 个 x 坐标排序去重，然后再把所有水平线段（
要记录是矩形上边还是下边）按 y 坐标排序。
最后对于每一小段区间 (x[i], x[i + 1]) 扫描所有的水平线段，
求出这些水平线段在小区间内覆盖的面积。总的时间复杂度是 O(n^2)。
利用线段树，可以优化到 O(nlogn)。
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define up  1
#define down -1


typedef struct TSeg
{
	double l, r;
	double y;
	int UpOrDown;
}TSeg;
TSeg seg[210];
int segn;
double x[210];
int xn;

int cmp1(const void *a, const void *b)
{
	if(*(double *)a < *(double *)b) return -1;
	else return 1;
}

int cmp2(const void *a, const void *b)
{
	TSeg *c = (TSeg *)a;
	TSeg *d = (TSeg *)b;
	if(c->y < d->y) return -1;
	else return 1;
}

void movex(int t, int &xn)
{
	int i;
	for(i = t;i <= xn - 1;i++){
		x[i] = x[i + 1];
	}
	xn--;
}

int main()
{
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	int n, i, j, cnt, test = 1;
	double x1, y1, x2, y2, ylow, area;
	while(scanf("%d", &n) != EOF && n){
		xn = 0;
		segn = 0;		
		for(i = 0;i < n;i++){
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			x[xn++] = x1;
			x[xn++] = x2;
			seg[segn].l = x1;
			seg[segn].r = x2;		
			seg[segn].y = y1;
			seg[segn++].UpOrDown = up;
			seg[segn].l = x1;
			seg[segn].r = x2;
			seg[segn].y = y2;
			seg[segn++].UpOrDown = down;			
		}
		qsort(x, xn, sizeof(x[0]), cmp1);
		/*除掉重复的x*/
		for(i = 1;i < xn;){
			if(x[i] == x[i - 1]) movex(i, xn);
			else i++;
		}
		qsort(seg, segn, sizeof(seg[0]), cmp2);	
		area = 0.0;
		for(i = 0;i < xn - 1;i++){
			cnt = 0;		
			for(j = 0;j < segn;j++){
				if(seg[j].l <= x[i] && seg[j].r >= x[i + 1]){
					if(cnt == 0) ylow = seg[j].y;
					if(seg[j].UpOrDown == down) cnt++;
					else cnt--;
					if(cnt == 0) area += (x[i + 1] - x[i]) * (seg[j].y - ylow);					
				}
			}
		}
		printf("Test case #%d\n", test++);
        printf("Total explored area: %.2lf\n", area); 		
	}
	return 0;
}
