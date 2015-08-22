#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MaxNode 100015

int stack[MaxNode];
int top;

typedef struct TPoint
{
    int x;
    int y;
}TPoint;
TPoint point[MaxNode];

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
    double k = multi(*c, *d, point[0]);
    if(k< 0) return 1;
    else if(k == 0 && distance(*c, point[0]) >= distance(*d, point[0])) return 1;
    else return -1;   
}

void grahamScan(int n)
{ 
    //Grahamɨ����͹��
    int i, u;     
    //�������µĵ������p[0]��λ��
    u = 0;
    for(i = 1;i <= n - 1;i++){
        if((point[i].y < point[u].y) || (point[i].y == point[u].y && point[i].x  < point[u].x))
        u = i;      
    } 
    swap(point, 0, u);
    
    //��ƽp[1]��p[n - 1]�����������򣬿ɲ��ÿ�������
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

int main()
{
	double polygonArea(TPoint p[], int n);
    int i, n, test;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &n);
        for(i = 0;i < n;i++)
        scanf("%d%d", &point[i].x, &point[i].y);
        if(n <= 2){
			printf("0.0\n");
            continue;       
        }
        grahamScan(n);
		printf("%.1lf\n", polygonArea(point, top + 1));		
    }
    return 0;
}

double polygonArea(TPoint p[], int n)
{
    //��֪����θ���������꣬�������
    double area;
    int i;
    area = 0;
    for(i = 1;i <= n;i++){
        area += (p[stack[i - 1]].x * p[stack[i % n]].y - p[stack[i % n]].x * p[stack[i - 1]].y);
    }  
    return fabs(area) / 2;   
}
