/*
���㼸�����֪ʶ�������㷨 
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MaxNode 100

//�Զ��峣�������ͼ�ͨ�ú���
const double eps = 1e-6;

typedef struct TPoint
{
    //ƽ��� 
    double x;
    double y;
}TPoint; 

typedef struct TSegment
{
    
    TPoint p1;
    TPoint p2;
}TSegment;

typedef struct TTriangle
{
    TPoint t[2];
}TTriangle;

typedef struct TPolygon
{
    //����� 
    TPoint p[MaxNode];
}TPolygon;

typedef struct TLine
{
    //ֱ�߷��̵�ϵ�� 
    double a, b, c;
}TLine;

typedef struct TCircle 
{
    //Բ 
    double r;
    TPoint centre;
}TCircle;

bool same(double x, double y)
{
    //�ж�����ʵ���Ƿ����
    if(fabs(x - y) < eps) return true;
    return false;
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

double distance(TPoint p1, TPoint p2)
{
    //����ƽ����������֮��ľ���
   return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));    
}

double multi(TPoint p1, TPoint p2, TPoint p0)
{
    //��ʸ��[p0, p1], [p0, p2]�Ĳ��
    //p0�Ƕ��� 
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
    //���������0���������㹲��
    //���������0����p0p2��p0p1����ʱ�뷽��
    //�����С��0����p0p2��p0p1��˳ʱ�뷽�� 
}

/*
���ߵĹ�����жϣ���p0��p1����ȥ����ߣ� 
�� (p2 - p1) ��� (p1 - p0) < 0 ,��p0p1��p1���������õ�p1p2
�� (p2 - p1) ��� (p1 - p0) = 0 ,�� p0, p1, p2���㹲��
�� (p2 - p1) ��� (p1 - p0) > 0 ,��p0p1��p1������Ҳ��õ�p1p2 
*/


TLine lineFromSegment(TPoint p1, TPoint p2)
{
    //�߶�����ֱ��,����ֱ�߷��̵�����ϵͳ 
    TLine tmp;
    tmp.a = p2.y - p1.y;
    tmp.b = p1.x - p2.x;
    tmp.c = p2.x * p1.y - p1.x * p2.y;
    return tmp;
}

//��������ļ��� 
//  S = ah / 2
//  S = absinC / 2
//  S = sqrt(p * (p - a) * (p - b) * (p - c)), p = (a + b + c) / 2
//  S = abc / R / 4

double triangleArea(TTriangle t)
{
    //��֪������������������꣬�������ε���� 
    return fabs(t.t[0].x * t.t[1].y + t.t[1].x * t.t[2].y + t.t[2].x * t.t[0].y
      - t.t[1].x * t.t[0].y - t.t[2].x * t.t[1].y - t.t[0].x * t.t[2].y) / 2;   
}

double polygonArea(TPolygon p, int n)
{
    //��֪����θ���������꣬�������
    double area;
    int i;
    area = 0;
    for(i = 1;i <= n;i++){
        area += (p.p[i - 1].x * p.p[i % n].y - p.p[i % n].x * p.p[i - 1].y);
    }  
    return fabs(area) / 2;   
}

TCircle circumcircleOfTriangle(TTriangle t)
{
    //�����ε����Բ
    TCircle tmp;
    double a, b, c, c1, c2;
    double xA, yA, xB, yB, xC, yC;
    a = distance(t.t[0], t.t[1]);
    b = distance(t.t[1], t.t[2]);
    c = distance(t.t[2], t.t[0]);
    //����S = a * b * c / R / 4;��뾶R 
    tmp.r = a * b * c / triangleArea(t) / 4;
    
    xA = t.t[0].x; yA = t.t[0].y;
    xB = t.t[1].x; yB = t.t[1].y;
    xC = t.t[2].x; yC = t.t[2].y;
    c1 = (xA * xA + yA * yA - xB * xB - yB * yB) / 2;
    c2 = (xA * xA + yA * yA - xC * xC - yC * yC) / 2;
    
    tmp.centre.x = (c1 * (yA - yC) - c2 * (yA - yB)) / 
         (xA - xB) * (yA - yC) - (xA - xC) * (yA - yB); 
    tmp.centre.y = (c1 * (xA - xC) - c2 * (xA - xB)) / 
         (yA - yB) * (xA - xC) - (yA - yC) * (xA - xB); 
         
    return tmp;     
}

TCircle incircleOfTriangle(TTriangle t)
{
    //�����ε��ڽ�Բ
    TCircle tmp;
    double a, b, c, angleA, angleB, angleC, p, p2, p3, f1, f2;
    double xA, yA, xB, yB, xC, yC;
    a = distance(t.t[0], t.t[1]);
    b = distance(t.t[1], t.t[2]);
    c = distance(t.t[2], t.t[0]);
    /*
    S = p * r
    p = (a + b + c) / 2;
    r = S / P = 2 * S / (a + b + c)
    */
    tmp.r = 2 * triangleArea(t) / (a + b +c);
    angleA = acos((b * b + c * c - a * a) / (2 * b * c));
    angleB = acos((a * a + c * c - b * b) / (2 * a * c));
    angleC = acos((a * a + b * b - c * c) / (2 * a * b));
    p = sin(angleA / 2);
    p2 = sin(angleB / 2);
    p3 = sin(angleC / 2);
    
    xA = t.t[0].x; yA = t.t[0].y;
    xB = t.t[1].x; yB = t.t[1].y;
    xC = t.t[2].x; yC = t.t[2].y;
    
    f1 = ((tmp.r / p2) * (tmp.r / p2) - (tmp.r / p) * (tmp.r / p) + 
         xA * xA - xB * xB + yA * yA - yB * yB) / 2;
    f2 = ((tmp.r / p3) * (tmp.r / p3) - (tmp.r / p) * (tmp.r / p) + 
         xA * xA - xC * xC + yA * yA - yC * yC) / 2;
    tmp.centre.x = (f1 * (yA - yC) - f2 * (yA - yB)) / 
                   ((xA - xB) * (yA - yC) - (xA - xC) * (yA - yB));
    tmp.centre.y = (f1 * (xA - xC) - f2 * (xA - xB)) / 
                   ((yA - yB) * (xA - xC) - (yA - yC) * (xA - xB));
    return tmp;   
}

bool isPointOnSegment(TPoint p, TPoint p1, TPoint p2)
{
    // �ж�p���Ƿ����߶�p1p2��
    //1.p�Ƿ���ֱ��p1p2�� 
    //2.p�Ƿ�����p1p2Ϊ�Խ��ߵľ�����
    if(multi(p1, p2, p) != 0) return false ;
    if((p.x > p1.x && p.x > p2.x) || (p.x < p1.x && p.x < p2.x)) return false;
    if((p.y > p1.y && p.y > p2.y) || (p.y < p1.y && p.y < p2.y)) return false;
    return true;   
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

bool isIntersected(TPoint s1, TPoint e1, TPoint s2, TPoint e2)
{
    //�ж��߶��Ƿ��ཻ
    //1.�����ų������ж��������߶�Ϊ�Խ��ߵ����������Ƿ��ཻ 
    //2.��������
    if(
    (max(s1.x, e1.x) >= min(s2.x, e2.x)) &&
    (max(s2.x, e2.x) >= min(s1.x, e1.x)) &&
    (max(s1.y, e1.y) >= min(s2.y, e2.y)) &&
    (max(s2.y, e2.y) >= min(s1.y, e1.y)) &&
    (multi(s2, e1, s1) * multi(e1, e2, s1) >= 0) &&
    (multi(s1, e2, s2) * multi(e2, e1, s2) >= 0)
    )  return true;
    
    return false;    
}

TPoint LineInter(TLine l1, TLine l2)
{
    //����ֱ�ߵý�������
    TPoint tmp; 
    double a1 = l1.a;
    double b1 = l1.b;
    double c1 = l1.c;
    double a2 = l2.a;
    double b2 = l2.b;
    double c2 = l2.c;
    //ע������b1 = 0 
    if(fabs(b1) < eps){
        tmp.x = -c1 / a1;  
        tmp.y = (-c2 - a2 * tmp.x) / b2;
    }       
    else{
        tmp.x = (c1 * b2 - b1 * c2) / (b1 * a2 - b2 * a1);
        tmp.y = (-c1 - a1 * tmp.x) / b1;
    }
    //cout << "��������" << endl; 
    //cout << a1 * tmp.x + b1 * tmp.y + c1 << endl;
    //cout << a2 * tmp.x + b2 * tmp.y + c2 << endl;
	return tmp;
}

//�ж��߶��Ƿ��ֱ���ཻ������Ҫ�ж��߶�[s1, e1]��ֱ�� L �Ƿ��ཻ��
//ֻҪ�ж��߶�[s1, e1]�Ƿ���� L ���ɡ�

//�жϵ��Ƿ�����������
//1.����ж� 
//2.�߶εĹ����ж�

//�жϵ��Ƿ��ڶ�����ڣ���������Ϊ͹����Σ�
//��������������������õģ�ֻ��Ҫ���������޸�
// ����Ҫ�жϵĵ��ڰ�������ڣ����������ȫ��ͬ
//�ķ��� 
 
bool isPointInTriangle1(TPoint p, TTriangle t)
{
    //�жϵ��Ƿ�����������,����ж� 
    TTriangle tmp;
    double area;
    int i, j;
    area = 0;
    for(i = 0;i <= 2;i++){
        for(j = 0;j <= 2;j++){
            if(i == j) tmp.t[j] = p;
            else tmp.t[j] = t.t[j];
        }
        area += triangleArea(tmp);
    }
    return same(area, triangleArea(t));
}

bool isPointInTriangle2(TPoint p, TTriangle t)
{
    //�жϵ��Ƿ�����������,�߶εĹ����ж� 
    //APB, BPC, CPA �Ĺ�������ͬ�� 
    double k1, k2, k3;
    k1 = multi(t.t[0], t.t[1], p);
    k2 = multi(t.t[1], t.t[2], p);
    k3 = multi(t.t[2], t.t[0], p);
    if(k1 * k2 * k3 != 0){
        if(k1 * k2 < 0) return false;
        if(k1 * k3 < 0) return false;
    }
    return true;
}

TPoint symmetricalPoint(TPoint p1, TPoint p2)
{
    //��p1����p2�ĶԳƵ�
    TPoint p3;
    p3.x = 2 * p2.x - p1.x;
    p3.y = 2 * p2.y - p1.y;
    
    return p3;
}

TPoint symmetricalPointofLine(TPoint p, TLine L)
{
    //p�����ֱ��L�ĶԳƵ� 
    TPoint p2;
    double d;
    d = L.a * L.a + L.b * L.b;
    p2.x = (L.b * L.b * p.x - L.a * L.a * p.x - 
            2 * L.a * L.b * p.y - 2 * L.a * L.c) / d;
    p2.y = (L.a * L.a * p.y - L.b * L.b * p.y - 
            2 * L.a * L.b * p.x - 2 * L.b * L.c) / d;
    return p2;
}

//������߶εĶԳƵ�
//���ȿ��Ը����߶ε������˵�����߶����ڵ�ֱ��L��Ȼ��������ָ��
//�����ֱ��L�ĶԳƵ�

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

void swap(TPoint p[], int i, int j)
{
    TPoint tmp;
    tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
}
int stack[MaxNode];
int top;

int cmp(const void *a, const void *b)
{
    TPoint *c = (TPoint *)a;
    TPoint *d = (TPoint *)b;
    double k = multi(*c, *d, point[0]);
    if(k< 0) return 1;
    else if(k == 0 && distance(*c, point[0]) < distance(*d, point[0])) return 1;
    else return -1;   
}

void grahamScan(TPoint p[], int n)
{ 
    //Grahamɨ����͹��
    int i; 
    
    //�������µĵ������p[0]��λ��
    for(i = 1;i <= n - 1;i++){
        if((p[i].y < p[0].y) || (p[i].y == p[0].y && p[i].x  < p[0].x))
        swap(p, 0, i);
    } 
    
    //��ƽp[1]��p[n - 1]�����������򣬿ɲ��ÿ�������
    qsort(p + 1, , n - 1, sizeof(p[0], cmp));
    
    for(i = 0;i <= 2;i++) stack[i] = i;
    top = 2;
    for(i = 3;i <= n - 1;i++){
        while(multi(p[i], p[stack[top]], p[stack[top - 1]]) > 0)  top--;
    } 
    top++;
    stack[top] = i;  
}

int main()
{
    
}


