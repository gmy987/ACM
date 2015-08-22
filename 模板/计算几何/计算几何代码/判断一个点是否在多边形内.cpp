/*
fzu_1120
�жϵ�q�Ƿ��ڶ�����ڵ�һ�ַ�������q��ˮƽ����L��
���L������P�ı߽粻�ཻ����q��P���ⲿ������
L��P�ı߽��ཻ�������˵���������Ϊ�棨ż����
ʱ����q��P���ڣ��⣩���� */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MaxNode 50
#define INF  999999999

typedef struct TPoint
{
    double x;
    double y;    
}TPoiont;

typedef struct TSegment
{
    
    TPoint p1;
    TPoint p2;
}TSegment;

typedef struct TPolygon
{
    TPoint point[MaxNode];
    int n;
}TPolygon;

double multi(TPoint p1, TPoint p2, TPoint p0)
{
    //��ʸ��[p0, p1], [p0, p2]�Ĳ��
    //p0�Ƕ��� 
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
    //���������0���������㹲��
    //���������0����p0p2��p0p1����ʱ�뷽��
    //�����С��0����p0p2��p0p1��˳ʱ�뷽�� 
}

double max(double x, double y)
{
    //�Ƚ��������Ĵ�С�����ش����
    if(x > y) return x;
    else return y; 
}

double min(double x, double y)
{
    //�Ƚ��������Ĵ�С������С����
    if(x < y) return x;
    else return y; 
}

bool Intersect(TSegment L1, TSegment L2)
{
    //�߶�l1��l2�ཻ���Ҳ��ڶ˵���ʱ������true    
    //�ж��߶��Ƿ��ཻ
    //1.�����ų������ж��������߶�Ϊ�Խ��ߵ����������Ƿ��ཻ 
    TPoint s1 = L1.p1;
    TPoint e1 = L1.p2;
    TPoint s2 = L2.p1;
    TPoint e2 = L2.p2;
    //2.��������
    if(
		(max(s1.x, e1.x) > min(s2.x, e2.x)) &&
		(max(s2.x, e2.x) > min(s1.x, e1.x)) &&
		(max(s1.y, e1.y) > min(s2.y, e2.y)) &&
		(max(s2.y, e2.y) > min(s1.y, e1.y)) &&
		(multi(s2, e1, s1) * multi(e1, e2, s1) > 0) &&
		(multi(s1, e2, s2) * multi(e2, e1, s2) > 0)
		)  return true;
    
    return false;    
}


bool Online(TSegment L, TPoint p)
{
    //p��L��(���ڶ˵�)ʱ����true
    //1.��L���ڵ�ֱ���� 
    //2.��LΪ�Խ��ߵľ�����
    double dx, dy, dx1, dy1;
    dx = L.p2.x - L.p1.x;
    dy = L.p2.y - L.p1.y;
    dx1 = p.x - L.p1.x;
    dy1 = p.y - L.p1.y;
    if(dx * dy1 - dy * dx1 != 0) return false; //���
    if(dx1 * (dx1 - dx) < 0 || dy1 * (dy1 - dy) < 0) return true;
    return false; 
}

bool same1(TSegment L, TPoint p1, TPoint p2)
{
    //�ж�p1, p2�Ƿ���L��ͬ�� 
    if(multi(p1, L.p2, L.p1) * multi(L.p2, p2, L.p1)< 0) return true;
    return false;    
}

bool Inside(TPoint q, TPolygon polygon)
{
    int c, i;
    TSegment L1, L2;
    c = 0;
    L1.p1 = q;
    L1.p2 = q;
    L1.p2.x = INF; 
    /*
    ��1���ཻ 
    1.p[i]��p[i+1]��L������ 
    2.p[i]��p[i+2]��L��ͬ��
    3.p[u]��p[i+3]��L��ͬ������ 
    */
    for(i = 0;i <= polygon.n - 1;i++){
        L2.p1 = polygon.point[i];
        L2.p2 = polygon.point[(i + 1) % polygon.n];
        if(Intersect(L1, L2)){
            c++; 
            continue;
        }
        if(!Online(L1, polygon.point[(i + 1) % polygon.n])) continue; 
        if(!Online(L1, polygon.point[(i + 2) % polygon.n]) && 
            !same1(L1, polygon.point[i], polygon.point[(i + 2) % polygon.n])){
			c++;
			continue;
		}
		if(Online(L1, polygon.point[(i + 2) % polygon.n]) && 
            !same1(L1, polygon.point[i], polygon.point[(i + 3) % polygon.n]))
			c++;
    }  
    if(c % 2 == 0) return false;
    else return true;
}

int main()
{
    int i, test, k;
    int primp, primq;
    TPoint p;
    p.x = 0;
    p.y = 0;
    test = 1;
    TPolygon polygon;
    while(scanf("%d", &polygon.n) != EOF && polygon.n){
        printf("Pilot %d\n", test++);
        for(i = 0;i <= polygon.n - 1;i++){
            scanf("%lf%lf", &polygon.point[i].x, &polygon.point[i].y);
        }
        scanf("%d%d", &primp, &primq);
        if(Inside(p, polygon)){
            printf("The pilot is in danger!\n");
            k = (primp - 1) * (primq - 1) / 2;
            printf("The secret number is %d.\n", k); 
        }
        else printf("The pilot is safe.\n");
        printf("\n");
    }
    return 0;
}

