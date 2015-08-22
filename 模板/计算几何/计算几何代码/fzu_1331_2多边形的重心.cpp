/*
��Ŀ������
��һ���ܶȾ��ȵ�ƽ��N�����(3 <= N <= 1000000)�����ܰ�Ҳ����͹����û�б��ཻ�棬
������֪N������(˳ʱ�����ʱ��)���������ֵ����j����������Ϊ��Xi �� Yi ��������
�� (|Xi|, |Yi| <= 20000)�������ƽ�����ε����ġ�

  ������̣�
  �ӵ�1������������ֱ����ӵ�i, i+1���������������Ti,1 < i < n, 
  һ��n-2�������������Ƕ����ε�һ�����֣��ֱ����ÿ�������ε����Si��
  �����Ϊ����������
  ��������ѧ֪ʶ�ã�n����(xi,yi)ÿ��������mi,��������   
  X = (x1*M1+x2*M2+...+xn*Mn) / (M1+M2+....+Mn)   
  Y = (y1*M1+y2*M2+...+yn*Mn) / (M1+M2+....+Mn)   
  �����Ҫ�õ�֪ʶ�У�
  ��֪3���������ε������������ֱ�Ϊp[0].x, p[0].y p[1].x, p[1].y p[1].x, p[1].y
  ���s =[ p[0].x*p[1].y-p[1].x*p[0].y + p[1].x*p[2].y-p[2].x*p[1].y + p[2].x*p[0].y-p[0].x*p[2].y ] / 2 , 
  ������3��������ʱ���ֵ��˳ʱ��ȡ����
  ��֪3�������ģ�x = (p[0].x+p[1].x+p[2].x)/3.0 , y = (p[0].y+p[1].y+p[2].y)/3.0 
  ���������Ĺ����У�����Ҫ���ǵ������˳����˳ʱ�뻹����ʱ�룬�����͵����ˣ�
  ��Ҫע�� һ���ǲ�������ÿ��С�����ε�����ʱ������3������������һ��
  	
*/
#include <stdio.h>
#include <math.h>

typedef struct TPoint
{
    double x;
    double y;
}TPoint;

double triangleArea(TPoint p0, TPoint p1, TPoint p2)
{
    //��֪������������������꣬�������ε���� 
    double k = p0.x * p1.y + p1.x * p2.y
		+ p2.x * p0.y - p1.x * p0.y 
		- p2.x * p1.y - p0.x * p2.y;
	//if(k >= 0) return k / 2;
//	else return -k / 2;    
       return k / 2;
}

int main()
{
    int i, n, test;
	TPoint p0, p1, p2, center;
    double area, sumarea, sumx, sumy;    
    scanf("%d", &test);  
    while(test--){
		scanf("%d", &n);
		scanf("%lf%lf", &p0.x, &p0.y);
		scanf("%lf%lf", &p1.x, &p1.y);
        sumx = 0;
        sumy = 0;
        sumarea = 0;
        for(i = 2;i < n;i++){
			scanf("%lf%lf", &p2.x, &p2.y);
            center.x = p0.x + p1.x + p2.x;
            center.y = p0.y + p1.y + p2.y;  
            area =  triangleArea(p0, p1, p2);
            sumarea += area;
			sumx += center.x * area;
			sumy += center.y * area; 
			p1 = p2;           
        }
        printf("%.2lf %.2lf\n", sumx / sumarea / 3, sumy / sumarea / 3);
    }
    return 0;
}
