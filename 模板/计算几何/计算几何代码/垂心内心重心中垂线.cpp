/*cug_1011_�������������д���.cpp*/
#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-6; 

struct point
{
    double x, y;
};

void K()

{
    //�����߾������� 
}

void L(double a, double b, double c, double A, double B, double C)
{    //���ߵĽ���
    double t1, t2, t3;
    t1 = c * cos(A) / cos(M_PI / 2 - C);
    t2 = c * cos(B) / cos(M_PI / 2 - C);
    t3 = a * cos(C) / cos(M_PI / 2 - A);
    t1 += t2 + t3;
    printf("%.3lf\n", t1);   
}

struct TLine
{
    double a, b, c;
};

TLine lineFromSegment(point p1, point p2)
{
    //�߶�����ֱ��,����ֱ�߷��̵�����ϵͳ 
    TLine tmp;
    tmp.a = p2.y - p1.y;
    tmp.b = p1.x - p2.x;
    tmp.c = p2.x * p1.y - p1.x * p2.y;
    return tmp;
}

point LineInter(TLine l1, TLine l2)
{
    //����ֱ�ߵý�������
    point tmp; 
    if(fabs(l1.b) < eps){
        tmp.x = -l1.c / l1.a;  
        tmp.y = (-l2.c - l2.a * tmp.x) / l2.b;
    }       
    else{
        tmp.x = (l1.c * l2.b - l1.b * l2.c) / (l1.b * l2.a - l2.b * l1.a);
        tmp.y = (-l1.c - l1.a * tmp.x) / l1.b;
    }
     return tmp;
}

double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
} 

void F(double a, double b, double c, double A, double B, double C)
{
    //��������ľ�������, ����� 
    /*�����������Ķ���С��120�ȵ�ʱ����������һ�㵽
    ������֮��ľ�����С����������нǶ���120�ȵĵ�P��
    �������ڵ���120�ȣ��ö���ȡ��Сֵ
     ����һ�£��������ε�����С��120��ʱ���Ѷ��������
    �����ڣ������ж��֣����Դ��ζ����������ȱ������Σ���
    ���������εĶ����ԭ�����εĶԽǣ����ߵ����߼�����
    �������ε����Ǵ��ڵ���120��ʱ��
    �Ѷ�����������εĶ۽��ϡ�*/ 
    if(A - 2 * M_PI / 3 > -eps){
        printf("%.3lf ", b + c);

        return ;
    }
    else if(B - 2 * M_PI / 3 > -eps){
        printf("%.3lf ", a + c);
        return ;
    }
    else if(C - 2 * M_PI / 3 > -eps){
        printf("%.3lf ", a + b);
        return ;
    }
    point pa, pb, pc, pc1, pa1;
    pa.x = 0, pa.y = 0;
    pb.x = c, pb.y = 0;
    pc.x = b * cos(A);
    pc.y = b * sin(A); 
    pc1.x = c * cos(-M_PI / 3);
    pc1.y = c * sin(-M_PI / 3);
    pa1.x = a * cos(2 * M_PI / 3 - B) + c;
    pa1.y = a * sin(2 * M_PI / 3 - B);
    TLine l1, l2;
    l1 = lineFromSegment(pa, pa1);
    l2 = lineFromSegment(pc, pc1);
    point f = LineInter(l1, l2);
    printf("%.3lf ", dis(pa, f) + dis(pb, f) + dis(pc, f));    
} 

void I(double a, double b, double c, double A, double B, double C)
{
    //��ƽ���ߵĽ��㵽������ľ���� 
    double t, ans;
    t = (a + b - c) / 2;
    ans = t / cos(C / 2) + (b - t) / cos(A / 2) + (a - t) / cos(B / 2);
    printf("%.3lf ", ans);
}

void G(double a, double b, double c, double A, double B, double C)
{
    //���ߵĽ��� 
    double t1, t2, t3;
    t1 = sqrt((b / 2) * (b / 2) + a * a - 2 * a * b / 2 * cos(C));
    t2 = sqrt((a / 2) * (a / 2) + c * c - 2 * a * c / 2 * cos(B));
    t3 = sqrt((c / 2) * (c / 2) + b * b - 2 * b * c / 2 * cos(A));
    t1 += t2 + t3;
    printf("%.3lf ", t1 * 2 / 3);  
}

void O(double a, double b, double c, double A, double B, double C)
{    //���ߵĽ���
    double t = (A + C - B) / 2;
    printf("%.3lf\n", 3 * b / 2 / cos(t));        
} 

int main()
{
    int i, ca;
    double a, b, c;
    double A, B, C;
    cin >> ca;
    for(i = 1;i <= ca;i++){
        cin >> a >> b >> c;
        A = (b * b + c * c - a * a) / 2 / b / c;
        B = (a * a + c * c - b * b) / 2 / a / c;
        C = (a * a + b * b - c * c) / 2 / a / b;
        A = acos(A), B = acos(B), C = acos(C);
        F(a, b, c, A, B, C);
        I(a, b, c, A, B, C);
        G(a, b, c, A, B, C);
        O(a, b, c, A, B, C);
    }
    return 0;
}

