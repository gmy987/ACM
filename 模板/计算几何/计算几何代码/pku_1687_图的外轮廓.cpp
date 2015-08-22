#include <stdio.h>

typedef struct TPoint 
{
	int x;
	int y;
}TPoint;

int main()
{
	int test, n, m, s, i, j, u;
	TPoint p[60];
	int a[60];
	int area, maxa;
	scanf("%d", &test);
	while(test--){
		scanf("%d", &n);
		for(i = 1;i <= n;i++){
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		scanf("%d", &m);
		maxa = -1;
		for(i = 1;i <= m;i++){
			scanf("%d", &s);
			for(j = 0;j < s;j++){
				scanf("%d", &a[j]);
			}
			area = 0;
			for(j = 1;j <= s;j++){
				area += (p[a[j - 1]].x * p[a[j % s]].y - p[a[j % s]].x * p[a[j - 1]].y);
			} 
			if(area < 0) area = -area;
			if(area >= maxa){
				u = i;
				maxa = area;
			}		
		}
		printf("%d\n", u);
	}
	return 0;
}
