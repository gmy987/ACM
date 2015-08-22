/*
1.ֱ���ཻ�󽻵�
2.�߶��ཻ�󽻵�
3.�ж��߶��Ƿ��ཻ 
4.��ֱ�߷���
5.ֱ���ཻ�󽻵� 
6.��ֱƽ���� 
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define MaxNode 1000
#define INF 99999999
const double eps = 1e-6;

typedef struct TPoint
{
    double x;
    double y;
    int flag;
}TPoint;

typedef struct TPolygon 
{
    TPoint point[MaxNode];
    int n;
}TPolygon;

typedef struct TLine
{
    //ֱ�߷��̵�ϵ�� 
    double a, b, c;
}TLine;

double dis2(TPoint p1, TPoint p2)
{
    //�����ƽ�� 
    return (p1.x - p2.x ) * (p1.x - p2.x) 
		+ (p1.y - p2.y) * (p1.y - p2.y);
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

bool IsPointsSame(TPoint p1, TPoint p2)
{
    if(p1.x != p2.x || p1.y != p2.y) return false;
    
    return true;
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

TLine lineFromSegment(TPoint p1, TPoint p2)
{
    //�߶�����ֱ��,����ֱ�߷��̵�����ϵͳ 
    TLine tmp;
    tmp.a = p2.y - p1.y;
    tmp.b = p1.x - p2.x;
    tmp.c = p2.x * p1.y - p1.x * p2.y;
    return tmp;
}

TPoint GetOtherPoint(TPoint pre, TPoint mid, TPoint tmp)
{
    //�����߶����˵��������ֱƽ��������һ�㣨���ڸ�ֱ���ϣ� 
	double kx, ky;
	TPoint other;
	kx = pre.x - tmp.x;
	ky = pre.y - tmp.y;
	if(fabs(kx) < eps){
		other.y = mid.y;
		other.x = 1.0;
		if(fabs(other.x - mid.x) < eps) other.x = 2.0;
	}
	else if(fabs(ky) < eps){
		other.x = mid.x;
		other.y = 1.0;
		if(fabs(other.y - mid.y) < eps) other.y = 2.0;
	}
	else {
		double k = -kx / ky;
		other.x = 1.0;
		if(fabs(other.x - mid.x) < eps) other.x = 2.0;
		other.y = mid.y + k * (other.x - mid.x);
	}
	return other;
}

bool isIntersected(TPoint s1, TPoint e1, TPoint s2, TPoint e2)
{
    //�ж��߶��Ƿ��ཻ
    //1.�����ų������ж��������߶�Ϊ�Խ��ߵ����������Ƿ��ཻ 
    //2.��������
    //cout << s1.x << " " << s1.y << endl;
    //cout << e1.x << " " << e1.y << endl;
    //cout << s2.x << " " << s2.y << endl;
    //cout << e2.x << " " << e2.y << endl;
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

/*bool ParallelLine(TPoint s1, TPoint e1, TPoint s2, TPoint e2)
{
    //����ֱ���Ƿ�ƽ�� 
   TPoint tmp1, tmp2;
   tmp1.x = s1.x - e1.x;
   tmp1.y = s1.y - e1.y;
   tmp2.x = s2.x - e2.x;
   tmp2.y = s2.y - e1.y;
   if(fabs(tmp2.x) > eps && fabs(tmp1.x) > eps 
      && fabs(tmp2.y / tmp2.x - tmp1.y / tmp1.x) < eps)
       return true;
    else if(fabs(tmp2.y) > eps && fabs(tmp1.y) > eps 
      && fabs(tmp2.x / tmp2.y - tmp1.x / tmp1.y) < eps)
      return true;
    else return false;  
}*/

void Insert(int p, TPolygon &polygon)
{
    //��Ӷ��� 
   // cout << "LL" << endl;
    int i;
    for(i = polygon.n - 1;i >= p;i--){
        polygon.point[i + 1] = polygon.point[i];
    }
}

void Delete(int p, TPolygon &polygon)
{
    //ɾ������
    int i;
    for(i = p;i < polygon.n - 1;i++){
        polygon.point[i] = polygon.point[i + 1];        
    }
}

double polygonArea(const TPolygon p)
{
    //��֪����θ���������꣬�������
    double area;
    int i, n;
    area = 0;
    n = p.n;
    for(i = 1;i <= n;i++){
        area += (p.point[i - 1].x * p.point[i % n].y 
                 - p.point[i % n].x * p.point[i - 1].y);
    }  
    if(area < 0) area = -area;
    return area / 2; 
}

int main()
{
    //freopen("fzu_1014.in", "r", stdin);
    //freopen("fzu_1014.out", "w", stdout);
    TPolygon polygon;  
    TLine LineMidOther, Linep0p1;
    TPoint tmp, pre, mid, other;
    TPoint otherinf, midinf;
    TPoint Interpoint;
    double a, b, c;
    bool TrueOrFalse;
	int tag, flag1, i;
    string check;
    pre.x = 0;
    pre.y = 0;
    polygon.point[0].x = 0;
    polygon.point[0].y = 0;
    polygon.point[1].x = 10;
    polygon.point[1].y = 0;
    polygon.point[2].x = 10;
    polygon.point[2].y = 10;
    polygon.point[3].x = 0;
    polygon.point[3].y = 10;
    polygon.n = 4;
    
    tag = 0;
    while(cin >> tmp.x >> tmp.y >> check){
		if(tag == 1 || check == "Same"){
            printf("0.00\n");
            tag = 1;
            continue;
        }		
		mid.x = (pre.x + tmp.x) / 2;
		mid.y = (pre.y + tmp.y) / 2;
		other = GetOtherPoint(pre, mid, tmp);
		//�õ�ƽ�ֶ���ε�ֱ���ϵ�������mid, other
		LineMidOther = lineFromSegment(mid, other);
		a = LineMidOther.a;
		b = LineMidOther.b;
		c = LineMidOther.c;
		//cout << "abc " << a << " " <<  b << " " << c << endl;
		//�õ�oher,��mid���ߣ������������ʾ��midinf, otherinf�� 
		if(b == 0){
            midinf.x = -c / a;
            midinf.y = -INF;
            otherinf.x = -c / a;
            otherinf.y = INF;
        }
        else{
            midinf.x = -INF;
            midinf.y = (-c - a * midinf.x) / b;
            otherinf.x = INF;
            otherinf.y = (-c - a * otherinf.x) / b;
        }
        //��������뵽����εĶ����� 
        //flag2 = 0;
		for(i = 0;i < polygon.n;i++){
            //cout << "polygon.n = " << polygon.n << endl;
            //cout << "i = " << i << endl;
            //cout << "abc " << a << " " <<  b << " " << c << endl;
            //cout << "midinf = " << midinf.x << " " <<  midinf.y << endl;
            //cout << "otherinf = " << otherinf.x << " " << otherinf.y << endl; 
			TrueOrFalse = isIntersected(polygon.point[i], 
				polygon.point[(i + 1) % polygon.n], otherinf, midinf);
            //cout << "[ " << polygon.point[i].x << ", " << polygon.point[i].y << " ]" << endl; 
            //cout << "[ " << polygon.point[(i + 1) % polygon.n].x << ", "  << polygon.point[(i + 1) % polygon.n].y << " ]" << endl;
			if(TrueOrFalse == true){
                /*if(ParallelLine(polygon.point[i], polygon.point[(i + 1) % polygon.n]��
                        midinf, otherinf)){
                            //ֱ��ƽ��
                            flag2 = 1;
                            
                            printf("%d", 0; 
                }*/
                //cout << "�н���" << endl; 
				Linep0p1 = lineFromSegment(polygon.point[i], polygon.point[(i + 1) % polygon.n]);
				//cout << "abcabs Linep0p1 " << Linep0p1.a << " " << Linep0p1.b << " " << Linep0p1.c << endl;
				Interpoint = LineInter(Linep0p1, LineMidOther);
				//cout << "Interpoint " << Interpoint.x << " " << Interpoint.y << endl;
				if(IsPointsSame(Interpoint, polygon.point[i]) == false 
                  && IsPointsSame(Interpoint, polygon.point[(i + 1) % polygon.n]) == false){
                    //���㲻�������˵� 
                   // cout << " ��Ӷ��� " << endl;
                    Insert(i + 1, polygon);
                    polygon.point[i + 1] = Interpoint;
                    polygon.n++;
                    i++;
                }
			}	  
        }
        //cout << "kldfjs;" << endl;
        flag1 = 0;
		if(check == "Hotter") flag1 = 1; //���� 
		else flag1 = 0; 
		//���ĳЩ�����¶������flag = 1��ʾ 
		for(i = 0;i < polygon.n;i++){
            
            //cout << "polygon.n = " << polygon.n << endl;
            //cout << "i = " << i << endl;
            
            double d1 = dis2(pre, polygon.point[i]);
            double d2 = dis2(tmp, polygon.point[i]);
            //cout << "d1 = " << d1 <<"  d2 = " << d2 << endl;
            if(fabs(d1 - d2) < eps) polygon.point[i].flag = 1;
            else if(d1 > d2){
                if(flag1 == 1) polygon.point[i].flag = 1;
                else polygon.point[i].flag = 0;
            }
            else{
				if(flag1 == 1) polygon.point[i].flag = 0;
				else polygon.point[i].flag = 1;
            } 
            //cout << "polygon.point[i].flag = " << polygon.point[i].flag << endl;       
        }
        //ɾ�����ڶ�����еĶ��� 
        for(i = 0;i < polygon.n;i++){
            //cout << "i = " << i << endl;
            if(polygon.point[i].flag == 0){
                //cout << "ɾ������" << endl;
                Delete(i, polygon);
                polygon.n--;
                i--;
            }
        }
        //cout << "polygon.n = " << polygon.n << endl;
        //for(i = 0;i < polygon.n;i++){
            //cout << "[ " << polygon.point[i].x << ", " 
                // << polygon.point[i].y << " ]" << endl;
       // }
        printf("%.2lf\n", polygonArea(polygon));   
        pre = tmp;     	        
	}
	return 0;
}

