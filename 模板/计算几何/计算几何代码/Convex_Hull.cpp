/*
凸包( Convex Hull )
凸包是对平面是上的某个点集而言的，凸包是一个最小凸多边形，满足点集
中的所有点都在该凸多边形内（或在该多边形的边上）。
通常，我们采用Graham扫描法来求点集的凸包。首先，排序选出点集中最左下
角点（先取y坐标最小的点，若有多个再在其中取x坐标最小的点），设该点为p0；
然后，将其余的按以p0为中心的极角坐标逆时针排序，多于相同极角的点只保留
距离p0最远的一个，这样就可以得到一个点的序列p1,p2, p2.....,pn;接下来，
将p0, p1, p2压入栈，一次处理pi（i >= 2 && i <= n），不断让栈顶的元素出
栈，直到栈顶的下一个元素，栈顶元素，以及pi构成的折线不拐向左侧，将pi压
入栈中；最后栈中的元素即为所求的凸包的顶点序列  
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MaxNode 100005

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
   return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int cmp(const void *a, const void *b)
{
    TPoint *c = (TPoint *)a;
    TPoint *d = (TPoint *)b;
    double k = multi(*c, *d, point[0]);
    if(k< 0) return 1;
    else if(k == 0 && distance(*c, point[0]) < distance(*d, point[0])) return 1;
    else return -1;   
}

void grahamScan(int n)
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
    
    //将平p[1]到p[n - 1]按按极角排序，可采用快速排序
    qsort(point + 1, n - 1, sizeof(point[0]), cmp);
    for(i = 0;i <= 2;i++) stack[i] = i;
    top = 2;
    for(i = 3;i <= n - 1;i++){
        while(multi(point[i], point[stack[top]], point[stack[top - 1]]) >= 0)  top--;
        top++;
        stack[top] = i;
    }
}

int main()
{
    int i, n;
    while(scanf("%d", &n) != EOF){
        for(i = 0;i < n;i++)
        scanf("%d%d", &point[i].x, &point[i].y);
        if(n <= 2){
            for(i = 0;i < n;i++)
            printf("<%d,%d>\n", point[i].x, point[i].y);    
            continue;       
        }
        grahamScan(n);
        for(i = 0;i <= top;i++)
        printf("<%d,%d>\n", point[stack[i]].x, point[stack[i]].y);
    }
    return 0;
}

