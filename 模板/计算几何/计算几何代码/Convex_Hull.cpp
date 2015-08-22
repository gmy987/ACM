/*
͹��( Convex Hull )
͹���Ƕ�ƽ�����ϵ�ĳ���㼯���Եģ�͹����һ����С͹����Σ�����㼯
�е����е㶼�ڸ�͹������ڣ����ڸö���εı��ϣ���
ͨ�������ǲ���Grahamɨ�跨����㼯��͹�������ȣ�����ѡ���㼯��������
�ǵ㣨��ȡy������С�ĵ㣬���ж����������ȡx������С�ĵ㣩����õ�Ϊp0��
Ȼ�󣬽�����İ���p0Ϊ���ĵļ���������ʱ�����򣬶�����ͬ���ǵĵ�ֻ����
����p0��Զ��һ���������Ϳ��Եõ�һ���������p1,p2, p2.....,pn;��������
��p0, p1, p2ѹ��ջ��һ�δ���pi��i >= 2 && i <= n����������ջ����Ԫ�س�
ջ��ֱ��ջ������һ��Ԫ�أ�ջ��Ԫ�أ��Լ�pi���ɵ����߲�������࣬��piѹ
��ջ�У����ջ�е�Ԫ�ؼ�Ϊ�����͹���Ķ�������  
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

