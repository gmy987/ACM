/*
暴力+凸包 
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double inf = 99999999.0;

struct TPoint
{
	double x, y;
}p[20], pp;

struct TREE
{
	double x, y, v, l;
}tree[20];

int stack[20];
int top;
int used[20];
int usenum[20];

double minvalue;
int ans[20];
double Elen;
int ansn;

void swap(TPoint point[], int i, int j)
{
    TPoint tmp;
    tmp = point[i];
    point[i] = point[j];
    point[j] = tmp;
}

double multi(TPoint p1, TPoint p2, TPoint p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double distance(TPoint p1, TPoint p2)
{
   return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int cmp(const void *a, const void *b)
{
    TPoint *c = (TPoint *)a;
    TPoint *d = (TPoint *)b;
    double k = multi(*c, *d, pp);
    if(k< 0) return 1;
    else if(k == 0 && distance(*c, pp) >= distance(*d, pp)) return 1;
    else return -1;   
}

void grahamScan(TPoint point[], int n)
{ 
    //Graham扫描求凸包
    int i, u;     
    //将最左下的点调整到p[0]的位置
    u = 0;
    for(i = 1;i <= n - 1;i++){
        if((point[i].y < point[u].y) || (point[i].y == point[u].y && point[i].x  < point[u].x))
        u = i;      
    } 
    swap(point, 0, u);
    pp = point[0];
    
    //将平p[1]到p[n - 1]按按极角排序，可采用快速排序
    qsort(point + 1, n - 1, sizeof(point[0]), cmp);
    for(i = 0;i <= 2;i++) stack[i] = i;
    top = 2;
    for(i = 3;i <= n - 1;i++){
        while(multi(point[i], point[stack[top]], point[stack[top - 1]]) >= 0){
            if(top == 0)break;
            top--;
        }
        top++;
        stack[top] = i;
    }
}

double length(TPoint p[], int n)
{
	double len = 0;
	int i;
	for(i = 0;i < n -1;i++){
		len += distance(p[stack[i]], p[stack[i + 1]]);		
	}
	len += distance(p[stack[n - 1]], p[stack[0]]);		
	return len;
}

void dfs(int depth, int n)
{
	int i, t, t1;
	double svalue, sl, len;
	if(depth == n){
		t = 0;
		t1 = 0;
		svalue = 0;
		sl = 0;
		for(i = 0;i < n;i++){
			if(used[i] == 0){
				p[t].x = tree[i].x;
				p[t++].y = tree[i].y;
			}
			else {
				usenum[t1++] = i;
				svalue += tree[i].v;
				sl += tree[i].l;
			}
		}
		if(svalue > minvalue || t == 0 || t1 == 0) return;
		if(t == 1) len = 0;
		else if(t == 2) len = 2 * distance(p[0], p[1]);
		else {
			grahamScan(p, t);
			len = length(p, top + 1);
		}
		if(sl < len) return ;
		if(svalue < minvalue || (svalue == minvalue && t1 < ansn)){
			minvalue = svalue;
			for(i = 0;i <= t1 - 1;i++){
				ans[i] = usenum[i];
			}	
			ansn = t1;
			Elen = sl - len;
		}	
		return ;
	}
	used[depth] = 1;
	dfs(depth + 1, n);
	used[depth] = 0;
	dfs(depth + 1, n);
}

int main()
{
	int n, i, j, test = 1;
	while(scanf("%d", &n) && n){
		for(i = 0;i < n;i++){
			scanf("%lf%lf%lf%lf", &tree[i].x, &tree[i].y, &tree[i].v, &tree[i].l);
		}
		minvalue = inf;
		ansn = int(inf);
		for(i = 1;i <= n;i++) used[i] = 0;
		dfs(0, n);
		printf("Forest %d\nCut these trees:", test++);
		for(i = 0;i < ansn;i++){
			printf(" %d", ans[i] + 1);
		}
		printf("\nExtra wood: %.2lf\n\n", Elen);
	}
	return 0;
}
