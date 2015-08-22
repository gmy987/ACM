#include <stdio.h>
#include <stdlib.h>

#define MaxNode 50005

int stack[MaxNode];
int top;

typedef struct TPoint
{
    int x, y;
}TPoint;
TPoint point[MaxNode];

void swap(TPoint point[], int i, int j)
{
    TPoint tmp;
    tmp = point[i];
    point[i] = point[j];
    point[j] = tmp;
}

int multi(TPoint p1, TPoint p2, TPoint p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

int distance(TPoint p1, TPoint p2)
{
   return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int cmp(const void *a, const void *b)
{
    TPoint *c = (TPoint *)a;
    TPoint *d = (TPoint *)b;
    int k = multi(*c, *d, point[0]);
    if(k < 0) return 1;
    else if(k == 0 && distance(*c, point[0]) >= distance(*d, point[0])) return 1;
    else return -1;   
}

void grahamScan(int n)
{ 
    int i, u;     
    u = 0;
    for(i = 1;i <= n - 1;i++)
	{
        if((point[i].y < point[u].y) || (point[i].y == point[u].y && point[i].x  < point[u].x))
        u = i;      
    } 
    swap(point, 0, u);
    qsort(point + 1, n - 1, sizeof(point[0]), cmp);
    for(i = 0;i <= 2;i++) stack[i] = i;
    top = 2;
    for(i = 3;i <= n - 1;i++)
	{
        while(multi(point[i], point[stack[top]], point[stack[top - 1]]) > 0){
            top--;
            if(top == 0)break;
        }
        top++;
        stack[top] = i;
    }
}

int main()
{
    double length(int n);
    int i, j, n, test;
    while(scanf("%d", &n) != EOF)
	{
		for(i = 0;i < n;i++)
			scanf("%d%d", &point[i].x, &point[i].y);
		if(n == 2) 
		{
			printf("%d\n", distance(point[0], point[1]));
			continue;
		}
        grahamScan(n);	
        int maxd = -1;
        //printf("%d\n", top);
        for(i = 0;i <= top;i++)
        {
        	for(j = i + 1;j <= top;j++)
        	{
				//printf("i = %d %d %d j = %d %d %d\n", i, point[stack[i]].x, point[stack[i]].y, j, point[stack[j]].x, point[stack[j]].y);
        		maxd >?= distance(point[stack[i]], point[stack[j]]);
			}
		}
        printf("%d\n", maxd);
    }
    return 0;
}


