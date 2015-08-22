/*
��ţ��˼�� 
��Ŀ���� n �����Σ�Ҫ�����ǵ��������������������ɢ����
�Ȱ� 2n �� x ��������ȥ�أ�Ȼ���ٰ�����ˮƽ�߶Σ�
Ҫ��¼�Ǿ����ϱ߻����±ߣ��� y ��������
������ÿһС������ (x[i], x[i + 1]) ɨ�����е�ˮƽ�߶Σ�
�����Щˮƽ�߶���С�����ڸ��ǵ�������ܵ�ʱ�临�Ӷ��� O(n^2)��
�����߶����������Ż��� O(nlogn)��
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
TSeg seg[4000];
int segn;
double x[4000];
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
	int n, i, j, cnt;
	double x1, y1, x2, y2, ylow, area;
	while(1){
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		if(x1 == -1 && x2 == -1 && y1 == -1 && y2 == -1) break;
		xn = 0;
		segn = 0;	
		while(1){
			if(xn != 0) {
				scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
				if(x1 == -1 && x2 == -1 && y1 == -1 && y2 == -1) break;
			}
			x[xn++] = x1;
			x[xn++] = x2;
			seg[segn].l = x1;
			seg[segn].r = x2;		
			seg[segn].y = y1;
			seg[segn++].UpOrDown = down;
			seg[segn].l = x1;
			seg[segn].r = x2;
			seg[segn].y = y2;
			seg[segn++].UpOrDown = up;			
		}
		qsort(x, xn, sizeof(x[0]), cmp1);
		/*�����ظ���x*/
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
        printf("%.0lf\n", area); 		
	}
	return 0;
}
