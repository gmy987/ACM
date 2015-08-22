/*
������������壬 
�������ĳ��ľ���Ϊlambda,γ��Ϊphi�� 
�����Ŀռ������� 
x=cos(phi)*cos(lambda) 
y=cos(phi)*sin(lambda) 
z=sin(phi) 
�����������Ŀռ�����ֱ�Ϊ(x1,y1,z1),(x2,y2,z2) 
ֱ�߾��뼴ΪR*sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1)),
�����ǵļн�Ϊ 
A = acos(x1 * x2 + y1 * y2 + z1 * z2)��
�����ؾ���Ϊ A * R������RΪ����ƽ���뾶6371 
*/

/*
�������궼Ҫ���԰뾶R������������Ƕȣ�����ͳһ��û�г� 
ע�����ﻹҪ�ж�����������;���γ�ȵĹ涨�й� 
*/
#include <stdio.h>
#include <math.h>

const double pi = acos(-1.0);

struct TPoint
{
   double x, y, z;
};
 
int main()
{
    double w1, wm1, j1, jm1, wd1, wd2;
    double w2, wm2, j2, jm2, jd1, jd2;
    TPoint p1, p2;
    char chr1, chr2;
    while(scanf("%lf%lf ", &w1, &wm1) != EOF){
        scanf("%c ", &chr1);
        scanf("%lf %lf %c", &j1, &jm1, &chr2);
        wd1 = (w1 + wm1 / 60) * pi / 180;
        jd1 = (j1 + jm1 / 60) * pi / 180;
        if(chr1 == 'S') wd1 *= -1.0;
        if(chr2 == 'W') jd1 *= -1.0;
        p1.x = cos(wd1) * cos(jd1);
        p1.y = cos(wd1) * sin(jd1);
        p1.z = sin(wd1);
        scanf("%lf %lf %c %lf %lf %c", &w2, &wm2, &chr1, &j2, &jm2, &chr2);
        wd2 = (w2 + wm2 / 60) * pi / 180;
        jd2 = (j2 + jm2 / 60) * pi / 180;
        if(chr1 == 'S') wd2 *= -1.0;
        if(chr2 == 'W') jd2 *= -1.0;
        p2.x = cos(wd2) * cos(jd2);
        p2.y = cos(wd2) * sin(jd2);
        p2.z = sin(wd2);
        double a = acos(p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
        printf("%.3lf\n", a * 6370.0);   
    }
    return 0;
}
