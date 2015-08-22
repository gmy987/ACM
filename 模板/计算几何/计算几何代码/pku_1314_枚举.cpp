#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TPoint
{
	char c[10];
	int x;
	int y;
}TPoint;

struct str
{
	char chr[6];
}ans[100];

int cmp(const void *a, const void *b)
{
	struct str *c = (struct str *)a;
	struct str *d = (struct str *)b;
	if(strcmp(c->chr, d->chr) < 0) return -1;
	else return 1;
}

int main()
{
	int i, n, t, test = 1;
	int x1, x2, x3, x4;
	TPoint p[30]; 
	while(scanf("%d", &n) != EOF && n){
		for(i = 1;i <= n;i++){
			scanf("%s%d%d", p[i].c, &p[i].x, &p[i].y);
		}
		t = 0;
		for(x1 = 1;x1 <= n;x1++){
			for(x4 = 1;x4 <= n;x4++){
				if(p[x4].x != p[x1].x || x4 == x1 || p[x1].y < p[x4].y) continue;
				for(x3 = 1;x3 <= n;x3++){
					if(p[x3].y != p[x4].y || x3 == x1 || x3 == x4 || p[x3].x < p[x4].x) continue;
					for(x2 = 1;x2 <= n;x2++){
						if(p[x2].x != p[x3].x || p[x2].y != p[x1].y) continue;
						if(p[x2].x < p[x1].x || p[x2].x < p[x4].x) continue;
						if(p[x2].y < p[x4].y || p[x2].y < p[x3].y) continue;
						if(x2 == x1 || x2 == x4 || x2 == x3) continue;
						ans[t].chr[0] = p[x1].c[0];
						ans[t].chr[1] = p[x2].c[0];
						ans[t].chr[2] = p[x3].c[0];
						ans[t].chr[3] = p[x4].c[0];
						ans[t].chr[4] = 0;
						t++;
					}
				}
			}
		}
		qsort(ans, t, sizeof(ans[0]), cmp);
	
		if(t == 0)	printf("Point set %d: No rectangles\n", test++);
		else {
			printf("Point set %d:\n", test++);
			for(i = 1;i <= t;i++){
				printf(" %s", ans[i - 1].chr);
				if(i % 10 == 0) printf("\n");				
			}
			if((i - 1) % 10 != 0) printf("\n");
		}	
	}
	return 0;
}
